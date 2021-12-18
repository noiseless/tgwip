Index: src/rtc_base/platform_thread_types.cc
--- src/rtc_base/platform_thread_types.cc.orig
+++ src/rtc_base/platform_thread_types.cc
@@ -25,6 +25,11 @@ typedef HRESULT(WINAPI* RTC_SetThreadDescription)(HAND
                                                   PCWSTR lpThreadDescription);
 #endif
 
+#if defined(__OpenBSD__)
+#include <pthread.h>
+#include <pthread_np.h>
+#endif
+
 #if defined(WEBRTC_FREEBSD)
 #include <sys/thr.h>
 #include <pthread_np.h>
@@ -36,7 +41,9 @@ PlatformThreadId CurrentThreadId() {
 #if defined(WEBRTC_WIN)
   return GetCurrentThreadId();
 #elif defined(WEBRTC_POSIX)
-#if defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
+#if defined(__OpenBSD__)
+  return reinterpret_cast<uint64_t>(pthread_self());
+#elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   return pthread_mach_thread_np(pthread_self());
 #elif defined(WEBRTC_ANDROID)
   return gettid();
@@ -114,6 +121,8 @@ void SetCurrentThreadName(const char* name) {
   } __except (EXCEPTION_EXECUTE_HANDLER) {  // NOLINT
   }
 #pragma warning(pop)
+#elif defined(__OpenBSD__)
+  pthread_set_name_np(pthread_self(), name);
 #elif defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));  // NOLINT
 #elif defined(WEBRTC_FREEBSD)
