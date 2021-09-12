--- absl/base/config.h.orig	Wed May 12 23:51:28 2021
+++ absl/base/config.h	Wed May 12 23:58:31 2021
@@ -370,6 +370,7 @@
 #ifdef ABSL_HAVE_MMAP
 #error ABSL_HAVE_MMAP cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||   \
+    defined(__OpenBSD__) || \
     defined(__ros__) || defined(__native_client__) || defined(__asmjs__) || \
     defined(__wasm__) || defined(__Fuchsia__) || defined(__sun) || \
     defined(__ASYLO__) || defined(__myriad2__)
@@ -383,7 +384,7 @@
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
-    defined(__ros__)
+    defined(__ros__) || defined(__OpenBSD__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
 #endif
 
