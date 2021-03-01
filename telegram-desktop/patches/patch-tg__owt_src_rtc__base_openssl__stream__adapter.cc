--- tg_owt/src/rtc_base/openssl_stream_adapter.cc.orig	Wed Feb  3 14:42:41 2021
+++ tg_owt/src/rtc_base/openssl_stream_adapter.cc	Mon Mar  1 04:51:38 2021
@@ -17,9 +17,12 @@
 #include <openssl/tls1.h>
 #include <openssl/x509v3.h>
 #ifndef OPENSSL_IS_BORINGSSL
-#include <openssl/dtls1.h>
 #include <openssl/ssl.h>
+#ifdef LIBRESSL_VERSION_NUMBER
+#include <openssl/ssl3.h>
 #endif
+#include <openssl/dtls1.h>
+#endif
 
 #include <atomic>
 #include <memory>
@@ -418,8 +421,10 @@
   if (ssl_mode_ == SSL_MODE_DTLS) {
     if (ssl_version == DTLS1_VERSION) {
       return SSL_PROTOCOL_DTLS_10;
+#ifndef LIBRESSL_VERSION_NUMBER
     } else if (ssl_version == DTLS1_2_VERSION) {
       return SSL_PROTOCOL_DTLS_12;
+#endif
     }
   } else {
     if (ssl_version == TLS1_VERSION) {
@@ -1034,15 +1039,27 @@
       case SSL_PROTOCOL_TLS_12:
       default:
         SSL_CTX_set_max_proto_version(
+#ifdef LIBRESSL_VERSION_NUMBER
+            ctx, TLS1_2_VERSION);
+#else
             ctx, ssl_mode_ == SSL_MODE_DTLS ? DTLS1_2_VERSION : TLS1_2_VERSION);
+#endif
         break;
     }
   } else {
     // TODO(https://bugs.webrtc.org/10261): Make this the default in M84.
     SSL_CTX_set_min_proto_version(
+#ifdef LIBRESSL_VERSION_NUMBER
+        ctx, TLS1_2_VERSION);
+#else
         ctx, ssl_mode_ == SSL_MODE_DTLS ? DTLS1_2_VERSION : TLS1_2_VERSION);
+#endif
     SSL_CTX_set_max_proto_version(
+#ifdef LIBRESSL_VERSION_NUMBER
+        ctx, TLS1_2_VERSION);
+#else
         ctx, ssl_mode_ == SSL_MODE_DTLS ? DTLS1_2_VERSION : TLS1_2_VERSION);
+#endif
   }
 
 #ifdef OPENSSL_IS_BORINGSSL
