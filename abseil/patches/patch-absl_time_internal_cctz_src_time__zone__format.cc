--- absl/time/internal/cctz/src/time_zone_format.cc.orig	Wed May 12 23:34:49 2021
+++ absl/time/internal/cctz/src/time_zone_format.cc	Wed May 12 23:35:27 2021
@@ -18,12 +18,6 @@
 #endif
 #endif
 
-#if defined(HAS_STRPTIME) && HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE)
-#define _XOPEN_SOURCE  // Definedness suffices for strptime.
-#endif
-#endif
-
 #include "absl/base/config.h"
 #include "absl/time/internal/cctz/include/cctz/time_zone.h"
 
