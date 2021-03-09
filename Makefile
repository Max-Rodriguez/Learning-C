# ======================================
#
#     Build Source Code - Makefile
#
#   Written for Windows/Linux Systems
#
# ======================================

# ----- Build Arguments ----- #

CC = gcc
TARGET = SortingAlgorithm

# ----- Build and Compile ----- #

windows: $(TARGET) clean-win
linux: $(TARGET) clean-bash

$(TARGET): $(TARGET).o
	$(CC) $(TARGET).o -o $(TARGET)

$(TARGET).o: $(TARGET).c
	$(CC) -c $(TARGET).c

# ----- Clean Build Files ----- #

clean-win:
	del *.o

clean-bash:
	rm *.os