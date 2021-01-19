--- tg_owt/cmake/init_target.cmake.orig	Mon Jan 18 04:27:05 2021
+++ tg_owt/cmake/init_target.cmake	Mon Jan 18 04:34:15 2021
@@ -62,6 +62,7 @@
         else()
             target_compile_options(${target_name}
             PRIVATE
+                -isystem /usr/local/include
                 -Wno-deprecated-declarations
                 -Wno-attributes
                 -Wno-narrowing
