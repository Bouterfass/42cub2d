NAME = cub3d

LIBCUB = cub3d.a

GNL = gnl.a

SRCS = ./src/*.c 

RAY = ./raycasting/*.c 

MLX_OBJ = ./minilibx-linux/*.o

OBJS = $(SRCS:.c=.o)

SRCS_OBJ = ./src/*.o

DIR_MLX = ./minilibx-linux/

DIR_GNL = ./getnextline/

INC = includes

%.o: %.c
	gcc -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) main.c
	gcc -c $(SRCS) $(RAY)
	rm -rf $(NAME)
	make -C $(DIR_MLX)
	make -C $(DIR_GNL)
	cp $(DIR_GNL)$(GNL) ./$(LIBCUB)
	ar rc $(LIBCUB) $(OBJS)
	ranlib $(LIBCUB)
	gcc main.c *.o $(MLX_OBJ) $(LIBCUB) -I$(INC). -lm  -lXext -lX11 -lbsd 

clean:
	rm -rf $(OBJS)
	rm -rf *.o a.out
	make clean -C $(DIR_GNL)
	make clean -C $(DIR_MLX)

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(GNL)
	rm -rf $(LIBCUB)
	make fclean -C $(DIR_GNL)
	
re: fclean all
