NAME = cub3d

LIBCUB = cub3d.a

GNL = gnl.a

SRCS= ./src/*.c 

MLX_OBJ = ./minilibx-linux/*.o

OBJS = $(SRCS:.c=.o)

DIR_MLX = ./minilibx-linux/

DIR_GNL = ./getnextline/

INC = includes

%.o: %.c
	gcc -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) main.c
	rm -rf $(NAME)
	make -C $(DIR_MLX)
	make -C $(DIR_GNL)
	cp $(DIR_GNL)$(GNL) ./$(LIBCUB)
	ar rc $(LIBCUB) $(OBJS)
	ranlib $(LIBCUB)
	gcc main.c $(MLX_OBJ) $(LIBCUB) -I$(INC). -lm  -lXext -lX11 -lbsd -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf objects
	make clean -C $(DIR_GNL)
	make clean -C $(DIR_MLX)

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(GNL)
	rm -rf $(LIBCUB)
	make fclean -C $(DIR_GNL)
	
re: fclean all
