/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:18:56 by malluin           #+#    #+#             */
/*   Updated: 2019/03/11 18:46:22 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "libftprintf.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# define WIDTH 1920
# define HEIGHT 1120
# define BUFF_SIZE 1024

typedef	struct		s_sprite{
	SDL_Texture		*t;
	SDL_Surface		*s;
}					t_sprite;

typedef struct		s_xy {
	double			x;
	double			y;
}					t_xy;

typedef struct		s_nn {
	struct s_nn		*next;
	int				idx;
	int				visited;
}					t_nn;

typedef struct		s_lst {
	char			*str;
	char			stop;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_order {
	int				ant;
	char			*target;
	char			stop;
	struct s_order	*next;
}					t_order;

typedef struct		s_barr {
	int				idx;
	int				x;
	int				y;
	char			start;
	char			end;
	char			*name;
	t_nn			*nn;
}					t_barr;

typedef struct		s_ant {
	int				ant_idx;
	int				idx_pos;
}					t_ant;

typedef struct		s_s {
	t_barr			*barr;
	t_lst			*read_lst;
	t_order			*read_orders;
	t_ant			*ants;
	int				room_max;
	int				room_count;
	char			buff[BUFF_SIZE];
	short			idx;
	int				nb_ants;
	char			next_start;
	char			next_end;
	char			state_io;
	int				start_idx;
}					t_s;

typedef struct		s_sdl {
	SDL_Window		*pwindow;
	SDL_Renderer	*prenderer;
	t_sprite		*sprite_bg;
	t_sprite		*sprite_ant;
	t_sprite		*sprite_box;
	t_sprite		*sprite_end;
	t_sprite		*sprite_start;
	SDL_Event		event;
	t_s				*s_lem;
	int				max_x;
	int				min_x;
	int				max_y;
	int				min_y;
	int				end;
}					t_sdl;

void				ft_parse(t_sdl *sdl);
int					add_edge_barr(char *e1, char *e2, t_s *s_lem);

void				barr_append(t_s *s, char *name, t_xy xy);
void				print_list(t_s *s, char *str);

t_nn				*nnlst_new_node(int content);
t_nn				*nnlst_new_front(int idx, t_nn **lst);
t_nn				*nnlst_new_back(int idx, t_nn **lst);

void				ft_print_buffer(t_s *s, char *str);
void				ft_putnbr_buffer(t_s *s, int n);

void				save_str(t_s *s, char *str, int mode);

int					is_room(char *str, int i);
int					parse_room(char *str, t_s *s_lem);
int					is_edge(char *str);
int					parse_edge(char *str, t_s *s_lem);
int					parse_order(char *str, t_s *s_lem);

void				print_order_list(t_s *s, t_order *lst, char *str);

char				*ft_strdup_to_count(char *str, char c, int *z);
void				go_next(int *idx, t_lst **read_lst);
void				ft_error(void);
#endif
