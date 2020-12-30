--- tg_owt/src/base/third_party/libevent/event-config.h.orig	Fri Nov 20 01:59:52 2020
+++ tg_owt/src/base/third_party/libevent/event-config.h	Fri Nov 20 02:00:26 2020
@@ -15,6 +15,8 @@
 #include "base/third_party/libevent/linux/event-config.h"
 #elif defined(__FreeBSD__)
 #include "base/third_party/libevent/freebsd/event-config.h"
+#elif defined(__OpenBSD__)
+#include "base/third_party/libevent/openbsd/event-config.h"
 #elif defined(__sun)
 #include "base/third_party/libevent/solaris/event-config.h"
 #elif defined(_AIX)
