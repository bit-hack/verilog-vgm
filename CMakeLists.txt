cmake_minimum_required(VERSION 3.0)
project(vgmverilator)

add_subdirectory("verilator-3.841/include")

include_directories("verilator-3.841/include")
include_directories("obj_dir")

file(GLOB RTL "obj_dir/*.cpp" "obj_dir/*.h")
add_library(librtl ${RTL})

file(GLOB SOURCE "source/*.cpp" "source/*.h" "source/*.v")
add_executable(vgmverilator ${SOURCE})
target_link_libraries(vgmverilator libverilator librtl)

add_custom_command(TARGET vgmverilator PRE_BUILD COMMAND
    "verilator-3.841/verilator.exe" "--compiler" "msvc" "--cc" "source/rtl.v"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
