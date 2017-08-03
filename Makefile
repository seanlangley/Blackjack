CC=g++
CFLAGS = -Wall -g -o 

all:
	$(CC) $(CFLAGS) blackjack main.cpp classFiles.cpp
clean:
	rm -rf blackjack