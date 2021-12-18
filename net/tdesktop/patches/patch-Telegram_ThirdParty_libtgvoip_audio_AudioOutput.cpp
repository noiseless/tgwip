--- Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp.orig	Sun Sep 19 23:07:09 2021
+++ Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp	Sun Sep 19 23:11:37 2021
@@ -37,6 +37,7 @@
 #include "../os/linux/AudioOutputPulse.h"
 #include "../os/linux/AudioPulse.h"
 #endif
+#elif defined(__OpenBSD__)
 #else
 #error "Unsupported operating system"
 #endif
