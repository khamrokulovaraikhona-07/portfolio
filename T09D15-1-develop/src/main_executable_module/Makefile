# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -I../data_libs -I../data_module -I../yet_another_decision_module
LDFLAGS = -lm

# Directories
SRC_DIR = .
BUILD_DIR = ../../build
DATA_MODULE_DIR = ../data_module
DECISION_MODULE_DIR = ../yet_another_decision_module
DATA_LIBS_DIR = ../data_libs

# Source files
SRCS = $(SRC_DIR)/main_executable_module.c \
       $(DATA_MODULE_DIR)/data_process.c \
       $(DECISION_MODULE_DIR)/decision.c \
       $(DATA_LIBS_DIR)/data_io.c \
       $(DATA_LIBS_DIR)/data_stat.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = $(BUILD_DIR)/Quest_3

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild the project
rebuild: clean all





