--- tg_owt/src/rtc_base/openssl_stream_adapter.cc.orig	Fri Nov 20 02:50:36 2020
+++ tg_owt/src/rtc_base/openssl_stream_adapter.cc	Fri Nov 20 02:57:32 2020
@@ -16,7 +16,7 @@
 #include <openssl/rand.h>
 #include <openssl/tls1.h>
 #include <openssl/x509v3.h>
-#ifndef OPENSSL_IS_BORINGSSL
+#if !defined(OPENSSL_IS_BORINGSSL) && !defined(OPENSSL_IS_LIBRESSL)
 #include <openssl/dtls1.h>
 #include <openssl/ssl.h>
 #endif
@@ -392,8 +392,6 @@
   if (ssl_mode_ == SSL_MODE_DTLS) {
     if (ssl_version == DTLS1_VERSION) {
       return SSL_PROTOCOL_DTLS_10;
-    } else if (ssl_version == DTLS1_2_VERSION) {
-      return SSL_PROTOCOL_DTLS_12;
     }
   } else {
     if (ssl_version == TLS1_VERSION) {
@@ -968,6 +966,7 @@
     return nullptr;
   }
 
+#ifndef OPENSSL_IS_LIBRESSL
   if (support_legacy_tls_protocols_flag_) {
     // TODO(https://bugs.webrtc.org/10261): Completely remove this branch in
     // M84.
@@ -995,6 +994,7 @@
     SSL_CTX_set_max_proto_version(
         ctx, ssl_mode_ == SSL_MODE_DTLS ? DTLS1_2_VERSION : TLS1_2_VERSION);
   }
+#endif
 
 #ifdef OPENSSL_IS_BORINGSSL
   // SSL_CTX_set_current_time_cb is only supported in BoringSSL.
