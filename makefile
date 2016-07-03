#Target...:Dependency...
#[tab]Command:...

#Normal setting
CC = gcc
CFLAGS = -o

#C file
FILE = 104

#executable file name
EXE = $(FILE)

all:command1

command1:$(FILE).o
	$(CC) $(CFLAGS) $(EXE) $(FILE).c
clean:
	rm -f $(FILE) *.o $(EXE).exe