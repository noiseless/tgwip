--- absl/base/internal/unscaledcycleclock.cc.orig	Wed May 12 23:03:12 2021
+++ absl/base/internal/unscaledcycleclock.cc	Wed May 12 23:09:11 2021
@@ -26,6 +26,11 @@
 #elif defined(__FreeBSD__)
 #include <sys/sysctl.h>
 #include <sys/types.h>
+#elif defined(__OpenBSD__)
+#include "absl/base/call_once.h"
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <threads.h>
 #endif
 #endif
 
