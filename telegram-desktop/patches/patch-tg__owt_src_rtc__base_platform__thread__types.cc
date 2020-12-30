--- tg_owt/src/rtc_base/platform_thread_types.cc.orig	Wed Oct  7 17:11:02 2020
+++ tg_owt/src/rtc_base/platform_thread_types.cc	Fri Nov 20 02:41:08 2020
@@ -11,10 +11,13 @@
 #include "rtc_base/platform_thread_types.h"
 
 #if defined(WEBRTC_LINUX)
-#include <sys/prctl.h>
 #include <sys/syscall.h>
 #endif
 
+#ifdef __OpenBSD__
+#include <pthread_np.h>
+#endif
+
 namespace rtc {
 
 PlatformThreadId CurrentThreadId() {
@@ -28,7 +31,11 @@
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
 #elif defined(WEBRTC_LINUX)
+#if defined(__OpenBSD__)
+  return getthrid();
+#else
   return syscall(__NR_gettid);
+#endif
 #elif defined(__EMSCRIPTEN__)
   return static_cast<PlatformThreadId>(pthread_self());
 #else
@@ -78,9 +85,7 @@
   }
 #pragma warning(pop)
 #elif defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
-  prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));  // NOLINT
-#elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
-  pthread_setname_np(name);
+  pthread_set_name_np(pthread_self(), name);
 #endif
 }
 
