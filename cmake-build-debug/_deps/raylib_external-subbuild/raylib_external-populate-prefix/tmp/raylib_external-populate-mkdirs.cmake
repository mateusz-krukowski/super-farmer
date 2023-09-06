# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/mateusz/Documents/Thorlakur/dev/super-farmer/cmake-build-debug/_deps/raylib_external-src"
  "/home/mateusz/Documents/Thorlakur/dev/super-farmer/cmake-build-debug/_deps/raylib_external-build"
  "/home/mateusz/Documents/Thorlakur/dev/super-farmer/cmake-build-debug/_deps/raylib_external-subbuild/raylib_external-populate-prefix"
  "/home/mateusz/Documents/Thorlakur/dev/super-farmer/cmake-build-debug/_deps/raylib_external-subbuild/raylib_external-populate-prefix/tmp"
  "/home/mateusz/Documents/Thorlakur/dev/super-farmer/cmake-build-debug/_deps/raylib_external-subbuild/raylib_external-populate-prefix/src/raylib_external-populate-stamp"
  "/home/mateusz/Documents/Thorlakur/dev/super-farmer/cmake-build-debug/_deps/raylib_external-subbuild/raylib_external-populate-prefix/src"
  "/home/mateusz/Documents/Thorlakur/dev/super-farmer/cmake-build-debug/_deps/raylib_external-subbuild/raylib_external-populate-prefix/src/raylib_external-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/mateusz/Documents/Thorlakur/dev/super-farmer/cmake-build-debug/_deps/raylib_external-subbuild/raylib_external-populate-prefix/src/raylib_external-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/mateusz/Documents/Thorlakur/dev/super-farmer/cmake-build-debug/_deps/raylib_external-subbuild/raylib_external-populate-prefix/src/raylib_external-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
