# ======================================
#
#     Build Source Code - Makefile
#
#      Written for Windows Systems
#
# ======================================

# ----- Build Arguments ----- #

CC = gcc
TARGET = SortingAlgorithm

# ----- Build and Compile ----- #

all: $(TARGET) clean

$(TARGET): $(TARGET).o
	$(CC) $(TARGET).o -o $(TARGET)

$(TARGET).o: $(TARGET).c
	$(CC) -c $(TARGET).c

# ----- Clean Build Files ----- #

clean:
	del *.o