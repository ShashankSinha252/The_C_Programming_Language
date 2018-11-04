run: main.c
	gcc -Wall -std=c99 main.c -o run

debug: main.c
	gcc -Wall -std=c99 -g -DDEBUG=1 main.c -o run

clean:
	rm -f run

.PHONY: clean
