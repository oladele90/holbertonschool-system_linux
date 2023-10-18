CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

todo_api_0: sockets.o message0.o
	$(CC) $(CFLAGS) -o todo_api_0 sockets.o message0.o -lm

todo_api_1: sockets.o message1.o
	$(CC) $(CFLAGS) -o todo_api_1 sockets.o message1.o -lm

sockets.o: sockets.c sockets.h
	$(CC) $(CFLAGS) -c sockets.c

message0.o: message0.c sockets.h
	$(CC) $(CFLAGS) -c message0.c

message1.o: message1.c sockets.h
	$(CC) $(CFLAGS) -c message1.c

.PHONY: clean
clean:
	rm -f todo_api_0 todo_api_1 sockets.o message0.o message1.o