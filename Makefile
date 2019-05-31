# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malluin <malluin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 14:56:26 by malluin           #+#    #+#              #
#    Updated: 2019/03/20 14:56:55 by fnussbau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
NAME2 = visu
SRC_NAME =	ft_lemin.c \
			ft_parse.c \
			ft_parse_read.c \
			ft_parse_rooms.c \
			ft_error.c \
			ft_atbl.c \
			ft_nnlst.c \
			ft_print_buffer.c \
			ft_utils.c \
			ft_bfs.c \
			ft_queue_utils.c \
			ft_path_utils.c \
			ft_move_ants.c \
			ft_free.c \
			ft_edmond_karp.c \
			ft_save_paths.c \
			ft_edmond_karp_utils.c

SRC2_NAME = visualizer/src_visu/ft_visu.c \
			visualizer/src_visu/ft_parse.c \
			visualizer/src_visu/ft_parse_read.c \
			visualizer/src_visu/ft_parse_rooms.c \
			visualizer/src_visu/ft_atbl.c \
			visualizer/src_visu/ft_nnlst.c \
			visualizer/src_visu/ft_utils.c

HEADER_NAME = fractol.h
SRC_PATH = src
OBJ_PATH = obj
HEADER_PATH = includes/
CC = gcc
CCFLAGS =  -Wall -Wextra  -Werror
CPPFLAGS = -I ./libftprintf/includes -I ./libftprintf/libft/includes -I $(HEADER_PATH) -MMD
LIBFLAGS = -L ./libftprintf/ -lftprintf
SDLFLAGS =  $(SDLINCL) -L/Users/malluin/.brew/Cellar/sdl2/2.0.9/lib -lSDL2 -L/Users/malluin/.brew/Cellar/SDL2_image/2.0.4/lib -lSDL2
SDLINCL = -I /Users/malluin/.brew/Cellar/sdl2/2.0.9/include -I /Users/malluin/.brew/Cellar/SDL2_image/2.0.4/include
HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libftprintf/
	$(CC) $(CCFLAGS) $(LIBFLAGS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CCFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	@make clean -C libftprintf/
	rm -f $(OBJ) $(OBJ:.o=.d)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:	clean
	@make fclean -C libftprintf/
	@rm -f $(NAME)

re: fclean
	$(MAKE) all

visu:
	gcc $(SRC2_NAME) $(SDLFLAGS) $(CPPFLAGS) $(LIBFLAGS) -o visualizer/$(NAME2)

revisu:
	rm -f $(SRC2_NAME:.c=.o)
	rm -f $(SRC2_NAME:.c=.d)
	make visu
norme:
	norminette $(SRC)
	norminette $(INCLUDES)

.PHONY: make clean fclean re

-include $(OBJ:.o=.d)
