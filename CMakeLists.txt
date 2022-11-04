cmake_minimum_required(VERSION 3.23)

if(UNIX)
    find_package(glm REQUIRED)
elseif(WIN32)
    add_subdirectory(third_party/glfw)
endif()

# glad
project(glad)

add_library(glad third_party/glad/src/glad.c)
target_include_directories(glad PUBLIC third_party/glad/include)
# glad

set(CMAKE_CXX_STANDAR 20)

get_filename_component(DIR ${CMAKE_SOURCE_DIR} NAME)

project(${DIR})

file(GLOB PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.c")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME} glfw glm glad)
