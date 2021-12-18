--- Telegram/ThirdParty/minizip/zip.c.orig	Thu Nov 19 05:12:40 2020
+++ Telegram/ThirdParty/minizip/zip.c	Thu Nov 19 05:13:37 2020
@@ -22,6 +22,7 @@
 */
 
 
+#define NOCRYPT
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
