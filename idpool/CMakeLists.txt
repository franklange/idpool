project(idpool)

add_library(${PROJECT_NAME} "")

include(Warnings)
add_warnings_as_errors(${PROJECT_NAME} PRIVATE)

set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

target_sources(${PROJECT_NAME} PRIVATE
    interface/idpool/idpool.hpp

    lib/include/idpool/idpool_st.hpp
    lib/include/idpool/idpool_mt.hpp

    lib/src/idpool_st.cpp
    lib/src/idpool_mt.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    interface
    lib/include
)

if (IDP_ENABLE_TESTS)
    add_subdirectory(test)
endif()
