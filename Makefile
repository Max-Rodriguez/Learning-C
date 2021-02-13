# ======================================
#
#     Build Source Code - Makefile
#
# ======================================

# ----- Build Variables ----- #

COMPILER = gcc
TARGET = SortingAlgorithm

# ----- Build & Compile Target ----- #

all: $(TARGET) clean

$(TARGET): $(TARGET).o
	$(COMPILER) $(TARGET).o -o $(TARGET)

$(TARGET).o: $(TARGET).c
	$(COMPILER) -c $(TARGET).c

# ----- Clean Build Files ----- #

clean:
	del *.o