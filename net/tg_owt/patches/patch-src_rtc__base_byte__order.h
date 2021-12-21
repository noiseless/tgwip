$ OpenBSD: $

Included required header files

Index: src/rtc_base/byte_order.h
--- src/rtc_base/byte_order.h.orig
+++ src/rtc_base/byte_order.h
@@ -92,6 +92,8 @@
 #include <endian.h>
 #elif defined(WEBRTC_FREEBSD)
 #include <sys/endian.h>
+#elif defined(__OpenBSD__)
+#include <sys/endian.h>
 #else
 #error "Missing byte order functions for this arch."
 #endif  // defined(WEBRTC_MAC)
