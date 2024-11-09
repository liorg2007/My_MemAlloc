# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source files
SRCS = main.c mem_alloc.c

# Header files
HDRS = mem_alloc.h

# Output executable
TARGET = main

# Default target
all: $(TARGET)

# Linking the object files to create the executable
$(TARGET): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)
	rm -f *.o

# Phony targets (these do not create files)
.PHONY: all clean run
