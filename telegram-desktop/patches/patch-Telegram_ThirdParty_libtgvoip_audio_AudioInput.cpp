$OpenBSD$

--- Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp.orig	2021-07-04 10:05:17 UTC
+++ Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp
@@ -26,7 +26,7 @@
 #include "../os/windows/AudioInputWave.h"
 #endif
 #include "../os/windows/AudioInputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__) || defined(__OpenBSD__)
 #ifndef WITHOUT_ALSA
 #include "../os/linux/AudioInputALSA.h"
 #endif
