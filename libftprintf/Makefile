# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malluin <malluin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 14:56:26 by malluin           #+#    #+#              #
#    Updated: 2019/03/20 14:44:27 by malluin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_NAME =    ft_conv.c \
			  ft_printf.c \
			  scan_input.c \
			  utils_parsing.c \
			  show.c \
			  fac_opt.c \
			  lst_action.c \
			  set_refs.c \
			  ft_atol.c \
			  store_format.c \
			  ft_opt.c \
			  ft_lltoa_base.c \
			  ft_opt2.c \
			  ft_strcalc.c \
			  ft_strcalc2.c \
			  ft_bytes.c \
			  ft_convf.c \
			  ft_bytes2.c \
			  ft_wchar.c \
			  ft_wstr.c \
			  ft_color.c \
			  ft_putfinal.c \
			  ft_ulltoa_base.c \
			  ft_bits.c \
			  free.c
SRC_PATH = src
OBJ_PATH = obj
INCLUDES = ./includes/
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I ./libft/includes -I $(INCLUDES)
LIBFLAGS = -L ./libft/ -lft

OBJ_NAME = $(SRC_NAME:.c=.o)
	SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
	OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft/
	@$(AR) rc $@ $?
	@$(AR) r $@ $$($(AR) t libft/libft.a | grep ".o" | sed "s/^/libft\//")
	ranlib $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CCFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_PATH) :
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	@$(MAKE) $@ -C libft/
	$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:    clean
	@$(MAKE) $@ -C libft/
	@$(RM) $(NAME)

re: fclean
	$(MAKE)

norme:
	norminette $(SRC)
	norminette $(INCLUDES)

.PHONY: all clean fclean re
