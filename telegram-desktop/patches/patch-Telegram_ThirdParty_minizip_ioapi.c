--- Telegram/ThirdParty/minizip/ioapi.c.orig	Sun Nov 22 04:59:10 2020
+++ Telegram/ThirdParty/minizip/ioapi.c	Sun Nov 22 05:00:46 2020
@@ -14,7 +14,7 @@
         #define _CRT_SECURE_NO_WARNINGS
 #endif
 
-#if defined(__APPLE__) || defined(IOAPI_NO_64)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(IOAPI_NO_64)
 // In darwin and perhaps other BSD variants off_t is a 64 bit value, hence no need for specific 64 bit functions
 #define FOPEN_FUNC(filename, mode) fopen(filename, mode)
 #define FTELLO_FUNC(stream) ftello(stream)
