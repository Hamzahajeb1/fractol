MANDELBROT = Mandelbrot
JULIA = julia

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(MANDELBROT) $(julia)

$(MANDELBROT): main.c init.c hooks.c render.c utils.c functions.c
	$(CC) $(CFLAGS) -lmlx -lx11 -lXext $^ -o $@

$(JULIA): main.c init.c hooks.c render.c utils.c functions.c
	$(CC) $(CFLAGS) -lmlx -lx11 -lXext $^ -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re