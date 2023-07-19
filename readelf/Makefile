CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g

SRC = 1-hreadelf.c printfuncs1.c printfuncs2.c printfuncs3.c helper_1.c help.c printfuncs4.c sectionPrint1.c sectionPrint2.c sectionPrint3.c
OBJ = $(SRC:.c=.o)
NAME = 1-hreadelf

.PHONY: all clean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) *~ $(OBJ) $(NAME)