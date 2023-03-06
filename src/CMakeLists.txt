cmake_minimum_required(VERSION 3.0)
project(mat9)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

#=== LIBRARY: cimgui + Dear ImGui
add_library(mat9 STATIC 
    common/str.c
    common/dyn_buf.c
    common/log.c
    common/allocators.c
    graphic/context.c)
target_include_directories(mat9 PUBLIC .)

add_executable(index main/main.c)
target_include_directories(index PUBLIC .)
target_link_libraries(index PUBLIC mat9)

set(SDL_FLAGS "-s USE_SDL=2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SDL_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SDL_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SDL_FLAGS}")

# Emscripten-specific linker options
if (CMAKE_SYSTEM_NAME STREQUAL Emscripten)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    # use our own minimal shell.html
    target_link_options(index PRIVATE --shell-file ../html/shell_minimal.html)
    # WASM+JS size optimizations
    target_link_options(index PRIVATE -sASSERTIONS=1 -sWASM=1 -sALLOW_MEMORY_GROWTH=1)
endif()

# explicitly strip dead code
if (CMAKE_C_COMPILER_ID MATCHES "Clang" AND NOT CMAKE_SYSTEM_NAME STREQUAL Emscripten)
    target_link_options(index PRIVATE LINKER:-dead_strip)
endif()

# this hack removes the xxx-CMakeForceLinker.cxx dummy file
set_target_properties(index PROPERTIES LINKER_LANGUAGE C)
