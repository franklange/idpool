project(idpool_TEST)

find_package(GTest REQUIRED)

include(AddGTest)
add_gtest_executable(${PROJECT_NAME} idpool_TEST.cpp idpool)

include(Warnings)
add_warnings_as_errors(${PROJECT_NAME} PRIVATE)

if (IDP_ENABLE_COVERAGE)
    include(Coverage)
    add_coverage(${PROJECT_NAME} PRIVATE)
endif()
