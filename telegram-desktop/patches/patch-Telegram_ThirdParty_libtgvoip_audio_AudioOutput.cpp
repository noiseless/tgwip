$OpenBSD$

--- Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp.orig	2021-06-04 10:04:42 UTC
+++ Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp
@@ -29,7 +29,7 @@
 #include "../os/windows/AudioOutputWave.h"
 #endif
 #include "../os/windows/AudioOutputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__) || defined(__OpenBSD__)
 #ifndef WITHOUT_ALSA
 #include "../os/linux/AudioOutputALSA.h"
 #endif
