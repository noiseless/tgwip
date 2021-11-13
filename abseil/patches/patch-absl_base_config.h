--- absl/base/config.h.orig	Wed Nov  3 18:26:14 2021
+++ absl/base/config.h	Sat Nov 13 02:26:25 2021
@@ -414,7 +414,7 @@
     defined(_AIX) || defined(__ros__) || defined(__native_client__) ||    \
     defined(__asmjs__) || defined(__wasm__) || defined(__Fuchsia__) ||    \
     defined(__sun) || defined(__ASYLO__) || defined(__myriad2__) ||       \
-    defined(__HAIKU__)
+    defined(__HAIKU__) || defined(__OpenBSD__)
 #define ABSL_HAVE_MMAP 1
 #endif
 
@@ -425,7 +425,7 @@
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
-    defined(_AIX) || defined(__ros__)
+    defined(_AIX) || defined(__ros__) || defined(__OpenBSD__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
 #endif
 
