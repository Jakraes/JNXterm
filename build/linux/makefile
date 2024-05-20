CC = gcc
SRC = ../../src/
INC = ../../inc/

CFLAGS = -O3
LDFLAGS = -Wall `sdl2-config --cflags --libs`

OUT = app

all:
	$(CC) $(SRC)*.c -I$(INC) $(CFLAGS) $(LDFLAGS) -o $(OUT)
	
clean:
	rm -f $(OUT)
