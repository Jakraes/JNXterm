CC = gcc
SRC = ../../src/
INC = ../../inc/
LIB = ./lib

CFLAGS = -O3
#LDFLAGS = -Wall -lmingw32 -lSDL2main -lSDL2 
LDFLAGS = -mwindows -lmingw32 -lSDL2main -lSDL2 

OUT = app

all:
	$(CC) $(SRC)*.c -I$(INC) -L$(LIB) $(LDFLAGS) $(CFLAGS) -o $(OUT)
	
clean:
	rm -f $(OUT)
