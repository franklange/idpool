cmake_minimum_required(VERSION 3.15)
project(idpool_top)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/third_party/cmake_modules/cmake)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build Type" FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if (IDP_ENABLE_TESTS)
  enable_testing()
endif()

add_subdirectory(idpool)

if (IDP_ENABLE_EXAMPLE)
  add_subdirectory(example)
endif()
