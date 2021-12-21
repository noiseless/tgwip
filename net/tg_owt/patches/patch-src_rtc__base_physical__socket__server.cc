$ OpenBSD: $

Proper ioctl name

Index: src/rtc_base/physical_socket_server.cc
--- src/rtc_base/physical_socket_server.cc.orig
+++ src/rtc_base/physical_socket_server.cc
@@ -74,7 +74,11 @@ typedef void* SockOptArg;
 
 int64_t GetSocketRecvTimestamp(int socket) {
   struct timeval tv_ioctl;
+#if defined(__OpenBSD__)
+  int ret = ioctl(socket, SO_TIMESTAMP, &tv_ioctl);
+#else
   int ret = ioctl(socket, SIOCGSTAMP, &tv_ioctl);
+#endif
   if (ret != 0)
     return -1;
   int64_t timestamp =
