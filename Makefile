#
# nettool
CC=gcc
DEBUG=-g
nettool: nettool.c
	$(CC) $(DEBUG) -o nettool nettool.c
