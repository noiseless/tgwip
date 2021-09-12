--- absl/debugging/failure_signal_handler.cc.orig	Thu May 13 00:14:05 2021
+++ absl/debugging/failure_signal_handler.cc	Thu May 13 00:14:12 2021
@@ -136,7 +136,7 @@
 #else
   const size_t page_mask = sysconf(_SC_PAGESIZE) - 1;
 #endif
-  size_t stack_size = (std::max(SIGSTKSZ, 65536) + page_mask) & ~page_mask;
+  size_t stack_size = (std::max(SIGSTKSZ, (unsigned int)65536) + page_mask) & ~page_mask;
 #if defined(ABSL_HAVE_ADDRESS_SANITIZER) || \
     defined(ABSL_HAVE_MEMORY_SANITIZER) || defined(ABSL_HAVE_THREAD_SANITIZER)
   // Account for sanitizer instrumentation requiring additional stack space.
