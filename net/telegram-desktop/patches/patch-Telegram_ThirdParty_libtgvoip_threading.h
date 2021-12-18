$ OpenBSD: $

Proper version proposed at https://github.com/telegramdesktop/libtgvoip/pull/37

Index: Telegram/ThirdParty/libtgvoip/threading.h
--- Telegram/ThirdParty/libtgvoip/threading.h.orig
+++ Telegram/ThirdParty/libtgvoip/threading.h
@@ -18,6 +18,9 @@
 #ifdef __APPLE__
 #include "os/darwin/DarwinSpecific.h"
 #endif
+#ifdef __OpenBSD__
+#include <pthread_np.h>
+#endif
 #ifdef __FreeBSD__
 #include <pthread_np.h>
 #endif
@@ -97,6 +100,8 @@ namespace tgvoip{
 			if(self->name){
 #if defined(__linux__) || defined(__FreeBSD__)
 				pthread_setname_np(self->thread, self->name);
+#elif defined(__OpenBSD__)
+				pthread_set_name_np(self->thread, self->name);
 #elif defined(__APPLE__)
 				pthread_setname_np(self->name);
 				if(self->maxPriority){
