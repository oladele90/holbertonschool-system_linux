# Compiler and flags
CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -g

# Source file and executable name
SRC := end1.c end2.c main.c nmnm.c symbols1.c symbols2.c symbols3.c utilities.c
EXE := hnm

# Default target (executable)
all: $(EXE)

# Compile the source file into an executable
$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)

# Clean up object files and executable
clean:
	rm -f $(EXE)

.PHONY: all clean