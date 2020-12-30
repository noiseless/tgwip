--- tg_owt/src/modules/video_capture/linux/video_capture_linux.cc.orig	Fri Nov 20 03:34:11 2020
+++ tg_owt/src/modules/video_capture/linux/video_capture_linux.cc	Fri Nov 20 03:35:21 2020
@@ -12,7 +12,11 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#if defined(__OpenBSD__)
+#include <sys/videoio.h>
+#else
 #include <linux/videodev2.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <sys/ioctl.h>
