default: dcl.h getch.h dcl.c getch.c
	cc -o dcl-parser dcl.c getch.c main.c -ggdb3
