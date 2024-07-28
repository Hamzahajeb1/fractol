NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c init.c hooks.c render.c utils.c functions.c minilibx-linux/libmlx_Linux.a

all: $(NAME) 
$(NAME):$(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -Lminilibx-linux -lmlx -lXext -lX11

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
