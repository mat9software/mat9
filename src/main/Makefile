MAIN_OUT = $(BUILD_PATH)index.out

MAIN_SOURCES = main/main.c common/str.c common/dyn_buf.c common/log.c graphic/context.c
MAIN_DEP_EXEC = $(addprefix $(BUILD_PATH), $(MAIN_SOURCES:.c=.o))

MAIN_DEP_EXEC_EMCC = $(MAIN_DEP_EXEC:.o=.bc)

$(BUILD_PATH)/%.o:%.c
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<


$(BUILD_PATH)index.out : $(MAIN_DEP_EXEC)
	$(GCC) $^ -o $@ -lGL -lGLEW -lSDL2
$(BUILD_PATH)index.html : $(MAIN_DEP_EXEC_EMCC)
	$(EMCC) $^ -o $@ 
