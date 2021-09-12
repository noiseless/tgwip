$OpenBSD$

--- Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp.orig	2021-07-04 10:09:33 UTC
+++ Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp
@@ -31,7 +31,7 @@
 #endif
 #include "../os/windows/AudioInputWASAPI.h"
 #include "../os/windows/AudioOutputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__) || defined(__OpenBSD__)
 #ifndef WITHOUT_ALSA
 #include "../os/linux/AudioInputALSA.h"
 #include "../os/linux/AudioOutputALSA.h"
