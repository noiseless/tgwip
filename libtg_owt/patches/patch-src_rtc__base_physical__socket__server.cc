Index: src/rtc_base/physical_socket_server.cc
--- src/rtc_base/physical_socket_server.cc.orig
+++ src/rtc_base/physical_socket_server.cc
@@ -51,7 +51,10 @@
 #include "rtc_base/synchronization/mutex.h"
 #include "rtc_base/time_utils.h"
 
-#if defined(WEBRTC_LINUX)
+
+#undef WEBRTC_LINUX
+
+#if defined(WEBRTC_LINUX) && !defined(__OpenBSD__)
 #include <linux/sockios.h>
 #endif
 
@@ -74,7 +77,11 @@ typedef void* SockOptArg;
 
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
@@ -564,7 +571,7 @@ int PhysicalSocket::TranslateOption(Option opt, int* s
       *slevel = IPPROTO_IP;
       *sopt = IP_DONTFRAGMENT;
       break;
-#elif defined(WEBRTC_MAC) || defined(BSD) || defined(__native_client__)
+#elif defined(WEBRTC_MAC) || defined(__OpenBSD__) || defined(BSD) || defined(__native_client__)
       RTC_LOG(LS_WARNING) << "Socket::OPT_DONTFRAGMENT not supported.";
       return -1;
 #elif defined(WEBRTC_POSIX)
