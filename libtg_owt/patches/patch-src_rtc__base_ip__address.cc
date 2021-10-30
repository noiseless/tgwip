--- src/rtc_base/ip_address.cc.orig	Thu Oct 21 09:15:41 2021
+++ src/rtc_base/ip_address.cc	Sat Oct 30 00:58:12 2021
@@ -13,6 +13,7 @@
 #include <sys/socket.h>
 #ifdef OPENBSD
 #include <netinet/in_systm.h>
+#include <sys/types.h>
 #endif
 #include <netdb.h>
 #endif
