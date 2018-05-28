cmake_minimum_required(VERSION 3.1...3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_VERSION})
endif()

project(jaggrab-server VERSION 1.0
                       DESCRIPTION ""
                       LANGUAGES C)

# log.c library
add_library(logc
    STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/logc/src/log.c)
target_include_directories(logc
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/logc/src)
target_compile_features(logc 
    PUBLIC
        c_std_11)
target_compile_definitions(logc
    PRIVATE
        LOG_USE_COLOR)


# jaggrab executable
add_executable(jaggrab-server
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/error_code.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/buffer.c)

target_include_directories(jaggrab-server
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(jaggrab-server
    PUBLIC
        logc
        uv)

target_compile_features(jaggrab-server
    PUBLIC
        c_std_11)

