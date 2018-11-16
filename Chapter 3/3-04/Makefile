CC = gcc
CFLAGS = -Wall -std=c99

run: main.c
	$(CC) $(CFLAGS) main.c -o run

debug: main.c
	$(CC) $(CFLAGS) -g -DDEBUG=1 main.c -o run

clean:
	rm -f run

.PHONY: clean
