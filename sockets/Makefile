CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

todo_api_0: sockets.c sockets.h
	$(CC) $(CFLAGS) -o todo_api_0 sockets.c -lm

.PHONY: clean
clean:
	rm -f todo_api_0
