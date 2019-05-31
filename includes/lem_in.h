/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:18:56 by malluin           #+#    #+#             */
/*   Updated: 2019/03/20 14:36:48 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libftprintf.h"
# define BUFF_SIZE 1024

typedef struct		s_xy {
	double			x;
	double			y;
}					t_xy;

typedef struct		s_nn {
	struct s_nn		*next;
	int				idx;
	int				visited;
	int				flux;
}					t_nn;

typedef struct		s_lst {
	char			*str;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_queue {
	int				idx;
	int				idx_parent;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_path {
	int				idx;
	char			*name;
	int				w;
	struct s_path	*next;
}					t_path;

typedef struct		s_way {
	t_path			**paths;
	int				nb_paths;
	struct s_way	*next;
}					t_way;

typedef struct		s_barr {
	int				visited;
	int				idx;
	int				x;
	int				y;
	int				w;
	char			start;
	char			end;
	char			*name;
	t_nn			*nn;
	char			busy;
	char			blocked;
}					t_barr;

typedef struct		s_ant {
	int				w;
	int				ant_idx;
	int				launched;
	int				idx_pos;
	int				arrived;
	char			moved;
	t_path			*path;
}					t_ant;

typedef struct		s_s {
	t_barr			*barr;
	t_lst			*read_lst;
	t_queue			*queue;
	t_way			*ways;
	t_path			**paths;
	t_ant			*ants;
	int				nb_paths;
	int				room_max;
	int				room_count;
	char			buff[BUFF_SIZE];
	short			idx;
	int				nb_ants;
	char			next_start;
	char			next_end;
	char			state_io;
	short			end_idx;
	short			start_idx;
}					t_s;

t_s					*initialize_struct(void);
void				ft_initialize_ants(t_s *s);

void				ft_error(void);

void				ft_parse(t_s *s_lem);
int					add_edge_barr(char *e1, char *e2, t_s *s_lem);
void				barr_append(t_s *s, char *name, t_xy xy);

int					is_room(char *str, int i);
int					parse_room(char *str, t_s *s_lem);
int					is_edge(char *str);
int					parse_edge(char *str, t_s *s_lem);

t_nn				*nnlst_new_front(int idx, t_nn **lst);
t_nn				*nnlst_new_back(int idx, t_nn **lst);
t_queue				*queue_new_back(int idx, int idx_parent, t_queue **lst);
t_path				*path_new_front(int idx, char *name, t_path **lst);
t_path				*path_new_back(int idx, char *name, t_path **lst);
t_way				*new_way_back(t_way **lst);

void				ft_print_buffer(t_s *s, char *str);
void				ft_putnbr_buffer(t_s *s, int n);
void				print_out(t_s *s);
void				save_str(t_s *s, char *str, int mode);

char				*ft_strdup_to_count(char *str, char c, int *z);
void				go_next(int *idx, t_lst **read_lst);
t_queue				*find_index(t_queue	*q_ptr, int idx);
int					ft_len_path(t_path *path);

void				ft_check_way(t_s *s, int i, int out);
void				ft_one_step(t_s *s, int launched);
int					ft_launch(t_s *s, int flow, int i, int flux);

void				queue_del_first(t_queue **q);
void				ft_edmond_karp(t_s *s, int i);
void				save_paths(t_s *s, int i);
void				copy_best_path(t_s *s, int i, int best_idx);
void				show_way(t_queue *queue, t_s *s);
int					doublon(t_s *s, t_queue *q);
void				unblock_path(t_s *s, t_queue *queue);
void				reset_visited(t_s *s);

void				free_nn(t_nn *nn);
void				free_queue(t_s *s);
void				free_path(t_path *path_to_free);
void				free_struct_parsing(t_s *s);
void				free_struct_resolve(t_s *s);

#endif
