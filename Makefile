# ======================================
#
#     Build Source Code - Makefile
#
#      My first makefile with GCC.
#
# ======================================

# ----- Build Variables ----- #

COMPILER = gcc
TARGET = MemoryLeaks

# ----- Build & Compile Target ----- #

all: $(TARGET) clean

$(TARGET): $(TARGET).o
	$(COMPILER) $(TARGET).o -o $(TARGET)

$(TARGET).o: $(TARGET).c
	$(COMPILER) -c $(TARGET).c

# ----- Clean Build Files ----- #

clean:
	del *.o