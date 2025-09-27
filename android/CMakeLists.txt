cmake_minimum_required(VERSION 3.4.1)
project(PrismRn)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 20)

add_library(prismrn            SHARED
            ../cpp/prism-rn.cpp
            #cpp-adapter.cpp
)


# Specifies a path to native header files.
include_directories(
   ../cpp
   build/generated/source/codegen/jni/react/renderer/components
)

target_link_libraries(
  prismrn
  fbjni
  jsi
  reactnative
  react_codegen_RNPrismRnSpec
)

target_compile_options(
  prismrn
  PRIVATE
  -DLOG_TAG=\"ReactNative\"
  -fexceptions
  -frtti
  -std=c++20
  -Wall
)
