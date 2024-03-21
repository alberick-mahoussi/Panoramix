##
## EPITECH PROJECT, 2023
## B-CCP-400-PAR-4-1-panoramix-alberick.mahoussi
## File description:
## Makefile
##

SRC			=	$(shell echo src/*.c)

OBJ			=	$(SRC:.c=.o)

NAME		=	panoramix

CC			=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -I/include/panoramix -o $(NAME) $(OBJ) -lpthread -D_REENTRANT

clean:
	$(RM) $(NAME) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

./PHONY: all clean fclean
