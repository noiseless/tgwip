--- Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp.orig	Tue Aug 18 10:13:47 2020
+++ Telegram/ThirdParty/libtgvoip/audio/AudioInput.cpp	Sun Nov 22 03:01:31 2020
@@ -26,10 +26,12 @@
 #include "../os/windows/AudioInputWave.h"
 #endif
 #include "../os/windows/AudioInputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#if !defined(__OpenBSD__)
 #ifndef WITHOUT_ALSA
 #include "../os/linux/AudioInputALSA.h"
 #endif
+#endif
 #ifndef WITHOUT_PULSE
 #include "../os/linux/AudioPulse.h"
 #endif
@@ -72,8 +74,8 @@
 	}
 #endif
 	AudioInputWASAPI::EnumerateDevices(devs);
-#elif defined(__linux__) && !defined(__ANDROID__)
-#if !defined(WITHOUT_PULSE) && !defined(WITHOUT_ALSA)
+#elif (defined(__linux__) || defined(__OpenBSD__)) && !defined(__ANDROID__)
+#if !defined(WITHOUT_PULSE) && !defined(WITHOUT_ALSA) && !defined(__OpenBSD__)
 	if(!AudioInputPulse::EnumerateDevices(devs))
 		AudioInputALSA::EnumerateDevices(devs);
 #elif defined(WITHOUT_PULSE)
