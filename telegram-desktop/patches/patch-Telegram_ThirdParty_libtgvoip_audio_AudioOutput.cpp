--- Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp.orig	Tue Aug 18 10:13:47 2020
+++ Telegram/ThirdParty/libtgvoip/audio/AudioOutput.cpp	Sun Nov 22 02:55:39 2020
@@ -29,10 +29,12 @@
 #include "../os/windows/AudioOutputWave.h"
 #endif
 #include "../os/windows/AudioOutputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
 #ifndef WITHOUT_ALSA
+#if !defined(__OpenBSD__)
 #include "../os/linux/AudioOutputALSA.h"
 #endif
+#endif
 #ifndef WITHOUT_PULSE
 #include "../os/linux/AudioOutputPulse.h"
 #include "../os/linux/AudioPulse.h"
@@ -83,8 +85,8 @@
 	}
 #endif
 	AudioOutputWASAPI::EnumerateDevices(devs);
-#elif defined(__linux__) && !defined(__ANDROID__)
-#if !defined(WITHOUT_PULSE) && !defined(WITHOUT_ALSA)
+#elif (defined(__linux__) || defined(__OpenBSD__)) && !defined(__ANDROID__)
+#if !defined(WITHOUT_PULSE) && !defined(WITHOUT_ALSA) && !defined(__OpenBSD__)
 	if(!AudioOutputPulse::EnumerateDevices(devs))
 		AudioOutputALSA::EnumerateDevices(devs);
 #elif defined(WITHOUT_PULSE)
