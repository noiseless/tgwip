--- Telegram/SourceFiles/core/utils.cpp.orig	Fri Jul 16 05:39:02 2021
+++ Telegram/SourceFiles/core/utils.cpp	Fri Jul 16 05:40:57 2021
@@ -101,6 +101,7 @@
 		if (!sslSupported) {
 			LOG(("Error: current Qt build doesn't support SSL requests."));
 		}
+#ifndef LIBRESSL_VERSION_NUMBER
 		if (!CRYPTO_get_locking_callback()) {
 			// Qt didn't initialize OpenSSL, so we will.
 			auto numLocks = CRYPTO_num_locks();
@@ -118,6 +119,7 @@
 		} else if (!CRYPTO_get_dynlock_lock_callback()) {
 			LOG(("MTP Error: dynlock_create callback is set without dynlock_lock callback!"));
 		}
+#endif
 
 		_sslInited = true;
 	}
