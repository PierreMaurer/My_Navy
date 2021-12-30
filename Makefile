##
## EPITECH PROJECT, 2021
## B-CPE-100-STG-1-1-cpoolday10-pierre.maurer
## File description:
## Makefile
##

SRC =	./src/main.c        \
        ./src/signal/connection_user.c        \
        ./src/signal/signal_manager.c        \
        ./src/map/create_map.c        \
        ./src/map/utils_map.c        \
        ./src/map/print_map.c        \
        ./src/map/place_boat.c        \
        ./src/game/game.c        \
        ./src/other/message.c        \
        ./src/other/init.c        \
        ./src/navy.c

OBJ =    $(SRC:.c=.o)

LIB = -I ../include/ -L ./lib/ -lmy -g

NAME =	navy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(SRC) $(LIB) -g
	make clean

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:
	fclean all
