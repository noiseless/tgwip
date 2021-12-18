$OpenBSD$

Index: Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp
--- Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp.orig
+++ Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp
@@ -39,6 +39,7 @@
 #ifndef WITHOUT_PULSE
 #include "../os/linux/AudioPulse.h"
 #endif
+#elif defined(__OpenBSD__)
 #else
 #error "Unsupported operating system"
 #endif
