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
    "verilator-3.841/verilator.exe" "--compiler" "msvc" "--cc" "source/ym2149.v"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(TARGET vgmverilator PRE_BUILD COMMAND
    "verilator-3.841/verilator.exe" "--compiler" "msvc" "--cc" "source/sn76489.v"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(TARGET vgmverilator PRE_BUILD COMMAND
    "verilator-3.841/verilator.exe" "--compiler" "msvc" "--cc" "source/nesapu.v" "--top-module" "nesapu"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(TARGET vgmverilator PRE_BUILD COMMAND
    "verilator-3.841/verilator.exe" "--compiler" "msvc" "--cc" "source/ym3812.v" "--top-module" "ym3812"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

configure_file(source/nesapu_dac.txt  nesapu_dac.txt  COPYONLY)
configure_file(source/nesapu_len.txt  nesapu_len.txt  COPYONLY)
configure_file(source/nesapu_tri.txt  nesapu_tri.txt  COPYONLY)
configure_file(source/sn76489_dac.txt sn76489_dac.txt COPYONLY)
configure_file(source/ym2149_dac.txt  ym2149_dac.txt  COPYONLY)
