# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 14:36:30 by ehossain          #+#    #+#              #
#    Updated: 2025/07/10 15:28:20 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = ./src/ft_printf/ft_find_format.c \
./src/ft_printf/ft_number_size.c \
./src/ft_printf/ft_printf.c \
./src/ft_printf/ft_putchar.c \
./src/ft_printf/ft_putdec.c \
./src/ft_printf/ft_puthexa.c \
./src/ft_printf/ft_putptr.c \
./src/ft_printf/ft_putstr.c \
./src/ft_printf/ft_putuns.c \
./src/ft_atoi.c \
./src/ft_bzero.c \
./src/ft_calloc.c \
./src/ft_isalnum.c \
./src/ft_isalpha.c \
./src/ft_isascii.c \
./src/ft_isdigit.c \
./src/ft_isprint.c \
./src/ft_itoa.c \
./src/ft_memchr.c \
./src/ft_memcmp.c \
./src/ft_memcpy.c \
./src/ft_memmove.c \
./src/ft_memset.c \
./src/ft_putchar_fd.c \
./src/ft_putendl_fd.c \
./src/ft_putnbr_fd.c \
./src/ft_putstr_fd.c \
./src/ft_split.c \
./src/ft_strchr.c \
./src/ft_strdup.c \
./src/ft_striteri.c \
./src/ft_strjoin.c \
./src/ft_strlcat.c \
./src/ft_strlcpy.c \
./src/ft_strlen.c \
./src/ft_strmapi.c \
./src/ft_strncmp.c \
./src/ft_strnstr.c \
./src/ft_strrchr.c \
./src/ft_strtrim.c \
./src/ft_substr.c \
./src/ft_tolower.c \
./src/ft_toupper.c \
./src/get_next_line/get_next_line.c \
./src/get_next_line/get_next_line_utils.c

NAME = libft.a
INCLUDE = ../include
OBJECT = ${SOURCE:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

all : $(NAME)

$(NAME) : $(OBJECT)
	@ar rcs $(NAME) $(OBJECT)
	@echo "$(GREEN)libft compiled$(END)"

%.o : %.c
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean : 
	@rm -rf $(OBJECT)
	@echo "$(RED)libft object files removed$(END)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)libft removed$(END)"

re : fclean all

.PHONY: clean fclean re all

# Define color variables
RED    = \033[0;31m
GREEN  = \033[0;32m
END     = \033[0m
