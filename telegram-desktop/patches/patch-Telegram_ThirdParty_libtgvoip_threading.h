Index: Telegram/ThirdParty/libtgvoip/threading.h
--- Telegram/ThirdParty/libtgvoip/threading.h.orig
+++ Telegram/ThirdParty/libtgvoip/threading.h
@@ -9,7 +9,7 @@
 
 #include <functional>
 
-#if defined(_POSIX_THREADS) || defined(_POSIX_VERSION) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
+#if defined(_POSIX_THREADS) || defined(_POSIX_VERSION) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)) || defined(__OpenBSD__)
 
 #include <pthread.h>
 #include <semaphore.h>
@@ -18,6 +18,9 @@
 #ifdef __APPLE__
 #include "os/darwin/DarwinSpecific.h"
 #endif
+#ifdef __OpenBSD__
+#include <pthread_np.h>
+#endif
 
 namespace tgvoip{
 	class Mutex{
@@ -92,7 +95,9 @@ namespace tgvoip{
 		static void* ActualEntryPoint(void* arg){
 			Thread* self=reinterpret_cast<Thread*>(arg);
 			if(self->name){
-#if !defined(__APPLE__) && !defined(__gnu_hurd__)
+#if defined(__OpenBSD__)
+				pthread_set_name_np(self->thread, self->name);
+#elif !defined(__APPLE__) && !defined(__gnu_hurd__)
 				pthread_setname_np(self->thread, self->name);
 #elif !defined(__gnu_hurd__)
 				pthread_setname_np(self->name);
