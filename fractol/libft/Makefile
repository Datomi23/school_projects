# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 12:41:11 by dadeyemi          #+#    #+#              #
#    Updated: 2024/01/08 16:42:20 by dadeyemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar 
ARFLAGS = -rcs
INC = libft.h
SRC = ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_tolower.c\
	ft_toupper.c\

BONUSC= ft_lstnew.c\
ft_lstclear.c\
ft_lstiter.c\
ft_lstmap.c\
ft_lstdelone.c\
ft_lstadd_back.c\
ft_lstlast.c\
ft_lstsize.c\
ft_lstadd_front.c\


OBJ = $(SRC:.c=.o)
BONUSOBJ = $(BONUSC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus: $(BONUSOBJ) $(INC)
	$(AR) $(ARFLAGS) $(NAME) $(BONUSOBJ)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(BONUSOBJ)
fclean: clean
	rm -f libft.a

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re