--- src/rtc_base/openssl_stream_adapter.cc.orig	Sun May  2 01:58:21 2021
+++ src/rtc_base/openssl_stream_adapter.cc	Sun May  2 02:06:27 2021
@@ -17,8 +17,11 @@
 #include <openssl/tls1.h>
 #include <openssl/x509v3.h>
 #ifndef OPENSSL_IS_BORINGSSL
-#include <openssl/dtls1.h>
 #include <openssl/ssl.h>
+#ifdef LIBRESSL_VERSION_NUMBER
+#include <openssl/ssl3.h>
+#endif
+#include <openssl/dtls1.h>
 #endif
 
 #include <atomic>
