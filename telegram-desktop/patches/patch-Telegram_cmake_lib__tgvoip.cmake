--- Telegram/cmake/lib_tgvoip.cmake.orig	Sun Nov 22 02:27:49 2020
+++ Telegram/cmake/lib_tgvoip.cmake	Sun Nov 22 02:30:28 2020
@@ -109,10 +109,6 @@
         os/darwin/DarwinSpecific.h
 
         # Linux
-        os/linux/AudioInputALSA.cpp
-        os/linux/AudioInputALSA.h
-        os/linux/AudioOutputALSA.cpp
-        os/linux/AudioOutputALSA.h
         os/linux/AudioOutputPulse.cpp
         os/linux/AudioOutputPulse.h
         os/linux/AudioInputPulse.cpp
@@ -827,7 +823,7 @@
 
     if (LINUX)
         find_package(PkgConfig REQUIRED)
-        find_package(ALSA REQUIRED)
+        find_package(ALSA QUIET)
         pkg_check_modules(PULSE REQUIRED libpulse)
 
         target_include_directories(lib_tgvoip_bundled
