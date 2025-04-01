NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

# Librerie e flag di collegamento
MLX = -Lminilibx-linux -lmlx -lX11 -lXext -lm
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = $(MLX) -L$(LIBFT_DIR) -lft

SRCS = main.c \
	   init.c \
	   render.c \
	   math_utils.c \
	   events.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(OBJS)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re