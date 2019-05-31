# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malluin <malluin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 13:25:13 by malluin           #+#    #+#              #
#    Updated: 2019/03/20 14:41:19 by malluin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	  ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
	  ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	  ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c \
	  ft_tabdup.c ft_tabcpy.c ft_deltab.c ft_swap.c ft_fabs.c ft_iabs.c ft_power.c ft_imax.c ft_fmax.c \
	  ft_imin.c ft_fmin.c ft_memcpyeol.c ft_insert.c \
	  ft_strupcase.c ft_strlowcase.c \
	  ft_lltoa.c ft_atol.c ft_convert_base.c ft_memcset.c  ft_fpower.c ft_strxdup.c ft_pswap.c \
	  ft_convert_base.c ft_ltoi.c ft_llpower.c ft_numlen.c ft_gnl_utils.c
CC 			= gcc
CFLAGS		= -Werror -Wall -Wextra
CPPFLAGS = -I ./Includes/

HEADER = libft.h

OBJ = $(SRC:.c=.o)

all: $(FT_NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $(SRC)

$(FT_NAME): $(OBJ)
	@ar rc $(FT_NAME) $(OBJ)
	@ranlib $(FT_NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(FT_NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
