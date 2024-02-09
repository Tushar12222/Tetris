# Pre-compiler and Compiler flags
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb
PRE_FLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Project directory structure
BIN := bin
SRC := src
LIB := lib
INC := include
MAINFILE := $(SRC)/main.cpp

# Build directories and output
TARGET := $(BIN)/tetris
BUILD := build

# Library search directories and flags
EXT_LIB :=
LDFLAGS :=
LDPATHS := $(addprefix -L,$(LIB) $(EXT_LIB))

# Include directories
INC_DIRS := $(INC) $(shell find $(SRC) -type d) 
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Construct build output and dependency filenames
SRCS := $(shell find $(SRC) -name *.cpp)
OBJS := $(subst $(SRC)/,$(BUILD)/,$(addsuffix .o,$(basename $(SRCS))))
DEPS := $(OBJS:.o=.d)

# Run task
run: build
	@echo "🚀 Executing..."
	./$(TARGET) $(ARGS)

# Build task
build: clean all

# Main task
all: $(TARGET)

# Task producing target from built files
$(TARGET): $(OBJS)
	@echo "🚧 Building..."
	mkdir -p $(dir $@)
	$(CXX) $(OBJS) $(PRE_FLAGS) -o $@ $(LDPATHS) $(LDFLAGS)

# Compile all cpp files
$(BUILD)/%.o: $(SRC)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) $(INC_FLAGS) -c -o $@ $< $(LDPATHS) $(LDFLAGS) 

# Clean task
.PHONY: clean
clean:
	@echo "🧹 Clearing..."
	rm -rf build

# Include all dependencies
-include $(DEPS)
