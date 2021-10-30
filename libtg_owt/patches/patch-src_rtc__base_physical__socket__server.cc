--- src/rtc_base/physical_socket_server.cc.orig	Thu Oct 21 09:15:41 2021
+++ src/rtc_base/physical_socket_server.cc	Sat Oct 30 01:02:28 2021
@@ -74,7 +74,11 @@
 
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
