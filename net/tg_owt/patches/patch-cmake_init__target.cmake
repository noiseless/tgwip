Index: cmake/init_target.cmake
--- cmake/init_target.cmake.orig
+++ cmake/init_target.cmake
@@ -71,6 +71,7 @@ function(init_target target_name) # init_target(my_tar
         else()
             target_compile_options(${target_name}
             PRIVATE
+                -isystem /usr/local/include
                 -Wno-deprecated-declarations
                 -Wno-attributes
                 -Wno-narrowing
