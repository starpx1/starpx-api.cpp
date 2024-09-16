cmake_minimum_required(VERSION 3.18)

project(starpxapi)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(json 
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)
FetchContent_Declare(httplib 
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
    GIT_TAG v0.16.2
)

FetchContent_MakeAvailable(json)
FetchContent_MakeAvailable(httplib)


SET(TARGEH_H 
    starpx.h
)

add_executable(example example.cpp ${TARGEH_H})
target_link_libraries(example PRIVATE httplib nlohmann_json)


