CC = emcc
CXX = em++
WEB_DIR = ../web
EXE = $(WEB_DIR)/index.html
SRC_DIR = src/
BUILD_DIR = ../build
SOURCES = main/main.c common/str.c common/dyn_buf.c common/log.c graphic/context.c
OBJS = $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(basename $(notdir $(SOURCES)))))
UNAME_S := $(shell uname -s)
CPPFLAGS =
LDFLAGS =
EMS =
DEFINES = -DDEBUG_TRACE -DDEBUG_REQUEST -DRUN_TEST

##---------------------------------------------------------------------
## EMSCRIPTEN OPTIONS
##---------------------------------------------------------------------

# ("EMS" options gets added to both CPPFLAGS and LDFLAGS, whereas some options are for linker only)
EMS += -s USE_SDL=2
EMS += -s DISABLE_EXCEPTION_CATCHING=1
LDFLAGS += -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 -s NO_EXIT_RUNTIME=0 -s ASSERTIONS=1 -sFETCH

# Uncomment next line to fix possible rendering bugs with Emscripten version older then 1.39.0 (https://github.com/ocornut/imgui/issues/2877)
#EMS += -s BINARYEN_TRAP_MODE=clamp
#EMS += -s SAFE_HEAP=1    ## Adds overhead

# Emscripten allows preloading a file or folder to be accessible at runtime.
# The Makefile for this example project suggests embedding the misc/fonts/ folder into our application, it will then be accessible as "/fonts"
# See documentation for more details: https://emscripten.org/docs/porting/files/packaging_files.html
# (Default value is 0. Set to 1 to enable file-system and include the misc/fonts/ folder as part of the build.)
USE_FILE_SYSTEM ?= 1
ifeq ($(USE_FILE_SYSTEM), 0)
LDFLAGS += -s NO_FILESYSTEM=1
CPPFLAGS += -DIMGUI_DISABLE_FILE_FUNCTIONS
endif
ifeq ($(USE_FILE_SYSTEM), 1)
LDFLAGS += -lidbfs.js
endif

##---------------------------------------------------------------------
## FINAL BUILD FLAGS
##---------------------------------------------------------------------

#CPPFLAGS += -g
CPPFLAGS += -Wall -Wformat -Os $(EMS) $(DEFINES)
LDFLAGS += --shell-file shell_minimal.html $(EMS) $(DEFINES)
CPPFLAGS += -I.

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------


#----- mdtmp
$(BUILD_DIR)/%.o:main/%.c
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o:graphic/%.c
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o:common/%.c
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
#----- mdtmp

#$(BUILD_DIR)/%.o:%.cpp
#	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

all: $(BUILD_DIR) $(EXE)
	@echo Build complete for $(EXE)

$(BUILD_DIR):
	mkdir $@

$(WEB_DIR):
	mkdir $@

$(EXE): $(OBJS) $(WEB_DIR)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

clean:
	rm -rf $(WEB_DIR) $(BUILD_DIR)
