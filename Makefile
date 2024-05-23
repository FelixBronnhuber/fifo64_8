# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
BUILD_DIR = build
DEBUG_FLAGS =

# Source files
SRCS = main.c fifo64_8.c

# Object files
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

# Executable name
EXEC = main

# Default target
all: $(EXEC)

# Linking
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $@ $^

# Compiling
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

# Format source files
format:
	find . -name "*.c" -o -name "*.h" | xargs clang-format -i

# Phony targets
.PHONY: all clean

# Debug target
debug: DEBUG_FLAGS = -DDEBUG
debug: CFLAGS += -g
debug: all
