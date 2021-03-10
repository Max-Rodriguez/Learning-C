# ======================================
#
#     Build Source Code - Makefile
#
#   Written for Windows/Linux Systems
#
# --------------------------------------
#
#  Run 'make windows' for Windows OS.
#
#  Run 'make linux' for Linux Systems.
#
# ======================================

# ----- Build Arguments ----- #

CC = gcc
BIN = Executables

TARGET = BettingGame

# ----- Build and Compile ----- #

windows: winbuild clean-win
linux: linuxbuild clean-bash

winbuild: $(TARGET).o
	$(CC) $(TARGET).o -o $(BIN)/$(TARGET).exe

linuxbuild: $(TARGET)
	$(CC) $(TARGET).o -o $(BIN)/$(TARGET)-x64.linux

$(TARGET).o: $(TARGET).c
	$(CC) -c $(TARGET).c

# ----- Clean Object Files ----- #

clean-win:
	del *.o

clean-bash:
	rm *.o