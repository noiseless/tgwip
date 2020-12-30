--- Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp.orig	Tue Aug 18 10:13:47 2020
+++ Telegram/ThirdParty/libtgvoip/audio/AudioIO.cpp	Sun Nov 22 03:20:40 2020
@@ -31,11 +31,13 @@
 #endif
 #include "../os/windows/AudioInputWASAPI.h"
 #include "../os/windows/AudioOutputWASAPI.h"
-#elif defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
+#elif defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__) || defined(__gnu_hurd__)
 #ifndef WITHOUT_ALSA
+#if !defined(__OpenBSD__)
 #include "../os/linux/AudioInputALSA.h"
 #include "../os/linux/AudioOutputALSA.h"
 #endif
+#endif
 #ifndef WITHOUT_PULSE
 #include "../os/linux/AudioPulse.h"
 #endif
@@ -65,18 +67,24 @@
 		return new ContextlessAudioIO<AudioInputWave, AudioOutputWave>(inputDevice, outputDevice);
 #endif
 	return new ContextlessAudioIO<AudioInputWASAPI, AudioOutputWASAPI>(inputDevice, outputDevice);
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__OpenBSD__)
 #ifndef WITHOUT_ALSA
 #ifndef WITHOUT_PULSE
 	if(AudioPulse::Load()){
 		AudioIO* io=new AudioPulse(inputDevice, outputDevice);
 		if(!io->Failed() && io->GetInput()->IsInitialized() && io->GetOutput()->IsInitialized())
 			return io;
+#if !defined(__OpenBSD__)
 		LOGW("PulseAudio available but not working; trying ALSA");
+#else
+		LOGW("PulseAudio available but not working");
+#endif
 		delete io;
 	}
 #endif
+#if !defined(__OpenBSD__)
 	return new ContextlessAudioIO<AudioInputALSA, AudioOutputALSA>(inputDevice, outputDevice);
+#endif
 #else
 	return new AudioPulse(inputDevice, outputDevice);
 #endif
