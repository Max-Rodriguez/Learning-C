# =====================================
#
#    Build All Projects - Makefile
#
#     This is my first makefile.
#
# =====================================

CC = gcc

betting_game: BettingGame.exe
     $(CC) BettingGame.c -o BettingGame