--- absl/debugging/failure_signal_handler.cc.orig	Tue Jun  1 17:52:49 2021
+++ absl/debugging/failure_signal_handler.cc	Wed Oct  6 05:46:01 2021
@@ -137,7 +137,7 @@
   const size_t page_mask = sysconf(_SC_PAGESIZE) - 1;
 #endif
   size_t stack_size =
-      (std::max<size_t>(SIGSTKSZ, 65536) + page_mask) & ~page_mask;
+      (std::max<size_t>(SIGSTKSZ, (unsigned int)65536) + page_mask) & ~page_mask;
 #if defined(ABSL_HAVE_ADDRESS_SANITIZER) || \
     defined(ABSL_HAVE_MEMORY_SANITIZER) || defined(ABSL_HAVE_THREAD_SANITIZER)
   // Account for sanitizer instrumentation requiring additional stack space.
