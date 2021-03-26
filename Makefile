NAME = cub3d.a

SRC= *.c ./getnextline/*.c 

OBJS = *.o

INCLUDES = ./

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 -I$(INCLUDES) -c $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)
	
re: fclean all
