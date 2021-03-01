--- tg_owt/src/rtc_base/physical_socket_server.h.orig	Wed Feb  3 14:42:41 2021
+++ tg_owt/src/rtc_base/physical_socket_server.h	Mon Mar  1 01:51:23 2021
@@ -11,7 +11,7 @@
 #ifndef RTC_BASE_PHYSICAL_SOCKET_SERVER_H_
 #define RTC_BASE_PHYSICAL_SOCKET_SERVER_H_
 
-#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX)
+#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX) && !defined(__OpenBSD__)
 #include <sys/epoll.h>
 #define WEBRTC_USE_EPOLL 1
 #endif
