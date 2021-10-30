--- src/rtc_base/byte_order.h.orig	Thu Oct 21 09:15:41 2021
+++ src/rtc_base/byte_order.h	Sat Oct 30 00:53:36 2021
@@ -92,6 +92,8 @@
 #include <endian.h>
 #elif defined(WEBRTC_FREEBSD)
 #include <sys/endian.h>
+#elif defined(__OpenBSD__)
+#include <sys/endian.h>
 #else
 #error "Missing byte order functions for this arch."
 #endif  // defined(WEBRTC_MAC)
