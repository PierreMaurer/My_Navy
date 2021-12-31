##
## EPITECH PROJECT, 2021
## B-CPE-100-STG-1-1-cpoolday10-pierre.maurer
## File description:
## Makefile
##

SRC =   my_put_nbr.c		\
		my_putchar.c		\
		my_printf.c		\
		printf_o.c		\
		printf_dec.c		\
		printf_pointer.c		\
		printf_put_nbr.c		\
		my_putstr.c		\
		strcmp.c		\
		alloc.c        \
		my_revstr.c        \
		convert_i_c.c        \
		my_strlen.c        \
		my_getnbr.c


OBJ =    $(SRC:.c=.o)

NAME =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../includes/
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
