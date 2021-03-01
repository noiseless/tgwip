--- tg_owt/src/rtc_base/platform_thread_types.cc.orig	Wed Feb  3 14:42:41 2021
+++ tg_owt/src/rtc_base/platform_thread_types.cc	Mon Mar  1 01:03:56 2021
@@ -11,7 +11,6 @@
 #include "rtc_base/platform_thread_types.h"
 
 #if defined(WEBRTC_LINUX)
-#include <sys/prctl.h>
 #include <sys/syscall.h>
 #endif
 
@@ -38,7 +37,11 @@
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
 #elif defined(WEBRTC_LINUX)
+#if defined(__OpenBSD__)
+  return reinterpret_cast<uint64_t>(pthread_self());;
+#else
   return syscall(__NR_gettid);
+#endif
 #elif defined(__EMSCRIPTEN__)
   return static_cast<PlatformThreadId>(pthread_self());
 #else
@@ -67,6 +70,7 @@
 }
 
 void SetCurrentThreadName(const char* name) {
+#if !defined(__OpenBSD__)
 #if defined(WEBRTC_WIN)
   // The SetThreadDescription API works even if no debugger is attached.
   // The names set with this API also show up in ETW traces. Very handy.
@@ -106,9 +110,8 @@
   }
 #pragma warning(pop)
 #elif defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
-  prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));  // NOLINT
-#elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
+#endif
 #endif
 }
 
