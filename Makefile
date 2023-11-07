# Define the binary name and directories
BIN_NAME ?= 00_hello_world
BIN_DIR = bin
SRC_DIR = asm

# Construct TARGET and SRC using BIN_NAME
TARGET = $(BIN_DIR)/$(BIN_NAME)
SRC = $(SRC_DIR)/$(BIN_NAME).asm

# Define the assembly and linker flags
ASFLAGS = -f elf
LDFLAGS = -m elf_i386 -s

# Define the default rule to build the target
all: $(TARGET)

# Rule to assemble and link the program
$(TARGET): $(SRC)
	nasm $(ASFLAGS) -o $@.o $<
	ld $(LDFLAGS) -o $@ $@.o

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(TARGET).o
