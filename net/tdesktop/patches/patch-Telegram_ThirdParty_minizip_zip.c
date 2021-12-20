$ OpenBSD: $

Fix minizip building from the bundle by declaring NOCRYPT.

Index: Telegram/ThirdParty/minizip/zip.c
--- Telegram/ThirdParty/minizip/zip.c.orig
+++ Telegram/ThirdParty/minizip/zip.c
@@ -22,6 +22,7 @@
 */
 
 
+#define NOCRYPT
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
