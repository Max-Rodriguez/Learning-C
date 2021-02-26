# ===============================
#
#       Build - Makefile
#   Written For Windows Systems
#
#   Run 'make all' to compile.
#
# ===============================

CC = gcc

# ----- Build Source Code ----- #

all: Headers.o build clean

build: headers.o
	$(CC) Headers.o -o Build

headers.o: Headers.c include/header.h
	$(CC) -c Headers.c

# ----- Clean Build Files ----- #

clean:
	del *.o