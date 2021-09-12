--- ./Telegram/ThirdParty/libtgvoip/os/posix/NetworkSocketPosix.cpp.orig	Tue Jul 13 22:00:08 2021
+++ ./Telegram/ThirdParty/libtgvoip/os/posix/NetworkSocketPosix.cpp	Sat Sep  4 13:06:46 2021
@@ -87,62 +87,16 @@
 	}
 	int res;
 	if(protocol==PROTO_UDP){
-		sockaddr_in6 addr;
+		sockaddr_in addr;
 		IPv4Address *v4addr=dynamic_cast<IPv4Address *>(packet->address);
 		if(v4addr){
-			if(needUpdateNat64Prefix && !isV4Available && VoIPController::GetCurrentTime()>switchToV6at && switchToV6at!=0){
-				LOGV("Updating NAT64 prefix");
-				nat64Present=false;
-				addrinfo *addr0;
-				int res=getaddrinfo("ipv4only.arpa", NULL, NULL, &addr0);
-				if(res!=0){
-					LOGW("Error updating NAT64 prefix: %d / %s", res, gai_strerror(res));
-				}else{
-					addrinfo *addrPtr;
-					unsigned char *addr170=NULL;
-					unsigned char *addr171=NULL;
-					for(addrPtr=addr0; addrPtr; addrPtr=addrPtr->ai_next){
-						if(addrPtr->ai_family==AF_INET6){
-							sockaddr_in6 *translatedAddr=(sockaddr_in6 *) addrPtr->ai_addr;
-							uint32_t v4part=*((uint32_t *) &translatedAddr->sin6_addr.s6_addr[12]);
-							if(v4part==0xAA0000C0 && !addr170){
-								addr170=translatedAddr->sin6_addr.s6_addr;
-							}
-							if(v4part==0xAB0000C0 && !addr171){
-								addr171=translatedAddr->sin6_addr.s6_addr;
-							}
-							char buf[INET6_ADDRSTRLEN];
-							LOGV("Got translated address: %s", inet_ntop(AF_INET6, &translatedAddr->sin6_addr, buf, sizeof(buf)));
-						}
-					}
-					if(addr170 && addr171 && memcmp(addr170, addr171, 12)==0){
-						nat64Present=true;
-						memcpy(nat64Prefix, addr170, 12);
-						char buf[INET6_ADDRSTRLEN];
-						LOGV("Found nat64 prefix from %s", inet_ntop(AF_INET6, addr170, buf, sizeof(buf)));
-					}else{
-						LOGV("Didn't find nat64");
-					}
-					freeaddrinfo(addr0);
-				}
-				needUpdateNat64Prefix=false;
-			}
-			memset(&addr, 0, sizeof(sockaddr_in6));
-			addr.sin6_family=AF_INET6;
-			*((uint32_t *) &addr.sin6_addr.s6_addr[12])=v4addr->GetAddress();
-			if(nat64Present)
-				memcpy(addr.sin6_addr.s6_addr, nat64Prefix, 12);
-			else
-				addr.sin6_addr.s6_addr[11]=addr.sin6_addr.s6_addr[10]=0xFF;
-
+			addr.sin_addr.s_addr=v4addr->GetAddress();
+			addr.sin_port=htons(packet->port);
+			addr.sin_family=AF_INET;
+			res=sendto(fd, (const char*)packet->data, packet->length, 0, (const sockaddr*)&addr, sizeof(addr));
 		}else{
-			IPv6Address *v6addr=dynamic_cast<IPv6Address *>(packet->address);
-			assert(v6addr!=NULL);
-			memcpy(addr.sin6_addr.s6_addr, v6addr->GetAddress(), 16);
-			addr.sin6_family=AF_INET6;
+			res = -1;
 		}
-		addr.sin6_port=htons(packet->port);
-		res=(int)sendto(fd, packet->data, packet->length, 0, (const sockaddr *) &addr, sizeof(addr));
 	}else{
 		res=(int)send(fd, packet->data, packet->length, 0);
 	}
@@ -197,8 +151,8 @@
 		return;
 	}
 	if(protocol==PROTO_UDP){
-		int addrLen=sizeof(sockaddr_in6);
-		sockaddr_in6 srcAddr;
+		int addrLen=sizeof(sockaddr_in);
+		sockaddr_in srcAddr;
 		ssize_t len=recvfrom(fd, packet->data, packet->length, 0, (sockaddr *) &srcAddr, (socklen_t *) &addrLen);
 		if(len>0)
 			packet->length=(size_t) len;
@@ -207,21 +161,11 @@
 			packet->length=0;
 			return;
 		}
-		//LOGV("Received %d bytes from %s:%d at %.5lf", len, inet_ntoa(srcAddr.sin_addr), ntohs(srcAddr.sin_port), GetCurrentTime());
-		if(!isV4Available && IN6_IS_ADDR_V4MAPPED(&srcAddr.sin6_addr)){
-			isV4Available=true;
-			LOGI("Detected IPv4 connectivity, will not try IPv6");
-		}
-		if(IN6_IS_ADDR_V4MAPPED(&srcAddr.sin6_addr) || (nat64Present && memcmp(nat64Prefix, srcAddr.sin6_addr.s6_addr, 12)==0)){
-			in_addr v4addr=*((in_addr *) &srcAddr.sin6_addr.s6_addr[12]);
-			lastRecvdV4=IPv4Address(v4addr.s_addr);
-			packet->address=&lastRecvdV4;
-		}else{
-			lastRecvdV6=IPv6Address(srcAddr.sin6_addr.s6_addr);
-			packet->address=&lastRecvdV6;
-		}
+		lastRecvdV4=IPv4Address(srcAddr.sin_addr.s_addr);
+		packet->address=&lastRecvdV4;
+		packet->port=ntohs(srcAddr.sin_port);
+		
 		packet->protocol=PROTO_UDP;
-		packet->port=ntohs(srcAddr.sin6_port);
 	}else if(protocol==PROTO_TCP){
 		int res=(int)recv(fd, packet->data, packet->length, 0);
 		if(res<=0){
@@ -240,52 +184,46 @@
 void NetworkSocketPosix::Open(){
 	if(protocol!=PROTO_UDP)
 		return;
-	fd=socket(PF_INET6, SOCK_DGRAM, IPPROTO_UDP);
+	fd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
 	if(fd<0){
 		LOGE("error creating socket: %d / %s", errno, strerror(errno));
 		failed=true;
 		return;
 	}
-	int flag=0;
-	int res=setsockopt(fd, IPPROTO_IPV6, IPV6_V6ONLY, &flag, sizeof(flag));
-	if(res<0){
-		LOGE("error enabling dual stack socket: %d / %s", errno, strerror(errno));
-		failed=true;
-		return;
-	}
 
 	SetMaxPriority();
 	fcntl(fd, F_SETFL, O_NONBLOCK);
 
 	int tries=0;
-	sockaddr_in6 addr;
-	//addr.sin6_addr.s_addr=0;
-	memset(&addr, 0, sizeof(sockaddr_in6));
-	//addr.sin6_len=sizeof(sa_family_t);
-	addr.sin6_family=AF_INET6;
+	int res;
+	sockaddr_in addr;
+	//addr.sin_addr.s_addr=0;
+	memset(&addr, 0, sizeof(sockaddr_in));
+	//addr.sin_len=sizeof(sa_family_t);
+	addr.sin_family=AF_INET;
 	for(tries=0;tries<10;tries++){
-		addr.sin6_port=htons(GenerateLocalPort());
-		res=::bind(fd, (sockaddr *) &addr, sizeof(sockaddr_in6));
-		LOGV("trying bind to port %u", ntohs(addr.sin6_port));
+		addr.sin_port=htons(GenerateLocalPort());
+		res=::bind(fd, (sockaddr *) &addr, sizeof(sockaddr_in));
+		LOGV("trying bind to port %u", ntohs(addr.sin_port));
 		if(res<0){
-			LOGE("error binding to port %u: %d / %s", ntohs(addr.sin6_port), errno, strerror(errno));
+			LOGE("error binding to port %u: %d / %s", ntohs(addr.sin_port), errno, strerror(errno));
 		}else{
 			break;
 		}
 	}
 	if(tries==10){
-		addr.sin6_port=0;
-		res=::bind(fd, (sockaddr *) &addr, sizeof(sockaddr_in6));
+		addr.sin_port=0;
+		res=::bind(fd, (sockaddr *) &addr, sizeof(sockaddr_in));
 		if(res<0){
-			LOGE("error binding to port %u: %d / %s", ntohs(addr.sin6_port), errno, strerror(errno));
+			LOGE("error binding to port %u: %d / %s", ntohs(addr.sin_port), errno, strerror(errno));
 			//SetState(STATE_FAILED);
 			failed=true;
 			return;
 		}
 	}
-	size_t addrLen=sizeof(sockaddr_in6);
+	size_t addrLen=sizeof(sockaddr_in);
 	getsockname(fd, (sockaddr*)&addr, (socklen_t*) &addrLen);
-	LOGD("Bound to local UDP port %u", ntohs(addr.sin6_port));
+	LOGD("Bound to local UDP port %u", ntohs(addr.sin_port));
 
 	needUpdateNat64Prefix=true;
 	isV4Available=false;
@@ -435,10 +373,10 @@
 }
 
 uint16_t NetworkSocketPosix::GetLocalPort(){
-	sockaddr_in6 addr;
-	size_t addrLen=sizeof(sockaddr_in6);
+	sockaddr_in addr;
+	size_t addrLen=sizeof(sockaddr_in);
 	getsockname(fd, (sockaddr*)&addr, (socklen_t*) &addrLen);
-	return ntohs(addr.sin6_port);
+	return ntohs(addr.sin_port);
 }
 
 std::string NetworkSocketPosix::V4AddressToString(uint32_t address){
