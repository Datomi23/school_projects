# Project: minitalk
NAME		= minitalk

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= server.c client.c
OBJS		= $(SRCS:.c=.o)

BONUS_SRCS	= server_bonus.c client_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

PRINTF_DIR	= ft_printf
PRINTF_LIB	= $(PRINTF_DIR)/libftprintf.a

RM			= rm -f

# Default target
all: $(NAME)

$(NAME): $(PRINTF_LIB) $(OBJS)
	@$(CC) $(CFLAGS) server.o $(PRINTF_LIB) -o server
	@$(CC) $(CFLAGS) client.o $(PRINTF_LIB) -o client
	@echo "✅ Compiled server and client with ft_printf"

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

bonus: $(PRINTF_LIB) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) server_bonus.o $(PRINTF_LIB) -o server
	@$(CC) $(CFLAGS) client_bonus.o $(PRINTF_LIB) -o client
	@echo "✨ Compiled bonus server and client with ft_printf"

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@make clean -C $(PRINTF_DIR)
	@echo "🧹 Cleaned object files"

fclean: clean
	@$(RM) server client
	@make fclean -C $(PRINTF_DIR)
	@echo "🔥 Removed executables and ft_printf.a"

re: fclean all

.PHONY: all clean fclean re bonus
