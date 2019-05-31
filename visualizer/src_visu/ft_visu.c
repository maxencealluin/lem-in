/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 09:53:50 by malluin           #+#    #+#             */
/*   Updated: 2019/04/23 11:56:50 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	ft_error_sdl(char *str)
{
	ft_printf("%s (%s)\n", str, SDL_GetError());
	exit (-1);
}

t_sprite*	new_texture(SDL_Renderer *pRenderer, char *path)
{
	t_sprite	*sprite;

	sprite = NULL;
	if (!(sprite = (t_sprite *)malloc(sizeof(t_sprite))))
		exit(-1);
	if (!(sprite->s = SDL_LoadBMP(path)))
		ft_error_sdl("Échec de chargement du sprite");
	if (!(sprite->t = SDL_CreateTextureFromSurface(pRenderer, sprite->s)))
		ft_error_sdl("Échec de chargement texture");
	SDL_SetColorKey(sprite->s, SDL_TRUE, SDL_MapRGB(sprite->s->format,
		0, 255, 0));
	SDL_SetTextureBlendMode(sprite->t, SDL_BLENDMODE_BLEND);
	return (sprite);
}

t_s		*initialize_struct(void)
{
	t_s	*s_lem;

	if (!(s_lem = (t_s *)malloc(sizeof(t_s))))
		exit(-1);
	s_lem->barr = NULL;
	s_lem->nb_ants = 0;
	s_lem->next_start = 0;
	s_lem->next_end = 0;
	s_lem->read_lst = 0;
	s_lem->room_count = 0;
	s_lem->room_max = 0;
	ft_bzero(s_lem->buff, BUFF_SIZE);
	s_lem->idx = 0;
	s_lem->state_io = 0;
	s_lem->read_orders = NULL;
	s_lem->start_idx = 0;
	return (s_lem);
}

t_sdl		*initialize_struct_graph(void)
{
	t_sdl		*s;

	if (!(s = (t_sdl *)malloc(sizeof(t_sdl))))
		exit(-1);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_error_sdl("Échec de l'initialisation de la SDL");
	if (!(s->pwindow = SDL_CreateWindow("Ma première application SDL2", 100,
		100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		ft_error_sdl("Échec de creation de la fenetre");
	if (!(s->prenderer = SDL_CreateRenderer(s->pwindow,-1,
		SDL_RENDERER_ACCELERATED)))
		ft_error_sdl("Échec de chargement du renderer");
	s->sprite_bg = new_texture(s->prenderer, "./images_visu/earth.bmp");
	s->sprite_ant = new_texture(s->prenderer, "./images_visu/ant.bmp");
	s->sprite_box = new_texture(s->prenderer, "./images_visu/case.bmp");
	s->sprite_start = new_texture(s->prenderer, "./images_visu/case_start.bmp");
	s->sprite_end = new_texture(s->prenderer, "./images_visu/case_end.bmp");
	s->s_lem = initialize_struct();
	s->max_y = -20000000;
	s->max_x = -20000000;
	s->min_x = 20000000;
	s->min_x = 20000000;
	s->end = 0;
	return (s);
}

void	free_textures(t_sdl *s)
{
	SDL_DestroyTexture(s->sprite_bg->t);
}

void	ft_render_menu_bg(t_sdl *s)
{
	SDL_Rect dest = {0, 0, WIDTH / 2, HEIGHT};

	SDL_SetRenderDrawColor(s->prenderer, 160, 82, 45, 255);
	SDL_RenderClear(s->prenderer);
	SDL_RenderCopy(s->prenderer, s->sprite_bg->t, NULL, &dest);
	dest.x = WIDTH / 2;
	SDL_RenderCopy(s->prenderer, s->sprite_bg->t, NULL, &dest);
	dest.x = 0;
	dest.y = HEIGHT * 0.92;
	dest.w = WIDTH;
	dest.h = HEIGHT * 0.08;
}

double		scale_x(t_sdl *s, double x)
{
	return ((double)WIDTH * 0.1 + (double)(x - s->min_x)
		* (double)WIDTH * 0.8 / (double)(s->max_x - s->min_x));
}

double		scale_y(t_sdl *s, double y)
{
	return ((double)HEIGHT * 0.15 + (double)(y - s->min_y)
		* (double)HEIGHT * 0.7 / (double)(s->max_y - s->min_y));
}

void	ft_render_boxes(t_sdl *s)
{
	SDL_Rect dest2;
	int		i;

	i = 0;
	while (i < s->s_lem->room_count)
	{
		dest2.x = scale_x(s, s->s_lem->barr[i].x);
		dest2.y = scale_y(s, s->s_lem->barr[i].y);
		dest2.w = s->sprite_box->s->w * 1;
		dest2.h = s->sprite_box->s->h * 1;
		if (s->s_lem->barr[i].start == 1)
			SDL_RenderCopy(s->prenderer, s->sprite_start->t, NULL, &dest2);
		else if (s->s_lem->barr[i].end == 1)
			SDL_RenderCopy(s->prenderer, s->sprite_end->t, NULL, &dest2);
		else
			SDL_RenderCopy(s->prenderer, s->sprite_box->t, NULL, &dest2);
		i++;
	}
}

void	draw_paths(t_sdl *s, t_s *s_lem)
{
	int		i;
	t_nn	*nn;
	t_xy	xy1;
	t_xy	xy2;

	i = 0;
	while (i < s_lem->room_count)
	{
		nn = s_lem->barr[i].nn;
		while (nn)
		{
			SDL_SetRenderDrawColor(s->prenderer,
			255 - ((double)i / (double)s_lem->room_count) * 255,
			((double)i / (double)s_lem->room_count) * 120 + 120, 0, SDL_ALPHA_OPAQUE);
			xy1.x = scale_x(s, s_lem->barr[i].x) + (double)s->sprite_box->s->w / 2;
			xy1.y = scale_y(s, s_lem->barr[i].y) + (double)s->sprite_box->s->w / 2;
			xy2.x = scale_x(s, s_lem->barr[nn->idx].x) + (double)s->sprite_box->s->h / 2;
			xy2.y = scale_y(s, s_lem->barr[nn->idx].y) + (double)s->sprite_box->s->h / 2;
			SDL_RenderDrawLine(s->prenderer, xy1.x, xy1.y, xy2.x, xy2.y);
			nn = nn->next;
		}
		i++;
	}
}

void	assign_coordinates(SDL_Rect *dest, t_order *order, t_sdl *sdl, int bin)
{
	int		i;

	i = 0;
	while (i < sdl->s_lem->room_count && ft_strcmp(sdl->s_lem->barr[i].name,
		order->target) != 0)
		i++;
	if (i == sdl->s_lem->room_count)
	{
		dest->x = 0;
		dest->y = 0;
		return ;
	}
	if (bin == 0)
	{
		dest->x = scale_x(sdl, (double)((double)sdl->s_lem->barr[i].x
		+ (double)sdl->s_lem->barr[sdl->s_lem->ants[order->ant - 1].idx_pos].x) / 2.0);
		dest->y = scale_y(sdl, (double)((double)sdl->s_lem->barr[i].y
		+ (double)sdl->s_lem->barr[sdl->s_lem->ants[order->ant - 1].idx_pos].y) / 2.0);
	}
	else
	{
		dest->x = scale_x(sdl, sdl->s_lem->barr[i].x);
		dest->y = scale_y(sdl, sdl->s_lem->barr[i].y);
	}
}

void	assign_ant_pos(t_s *s, t_order *order, int bin)
{
	int		i;

	i = 0;
	if (bin == 0)
		return ;
	while (i < s->room_count && ft_strcmp(s->barr[i].name,
		order->target) != 0)
		i++;
	if (i == s->room_count)
		return ;
	s->ants[order->ant - 1].idx_pos = i;
}

void	render_ants(t_sdl *sdl, t_s *s)
{
	static	t_order	*order = NULL;
	static	int		bin = 0;
	SDL_Rect		dest2;
	int				i;
	t_order			*current;

	i = 0;
	if (order == NULL)
		order = s->read_orders;
	current = order;
	while (current)
	{
		assign_coordinates(&dest2, current, sdl, bin);
		dest2.w = sdl->sprite_box->s->w;
		dest2.h = sdl->sprite_box->s->h;
		assign_ant_pos(s, current, bin);
		SDL_RenderCopy(sdl->prenderer, sdl->sprite_ant->t, NULL, &dest2);
		if (current->stop == 1)
			break ;
		current = current->next;
	}
	current = current->next;
	if ((bin = (bin + 1) % 2) == 0)
		order = current;
	sdl->end = (order == NULL) ? 1 : 0;
}

void	ft_render(t_sdl *s)
{
	ft_render_menu_bg(s);
	draw_paths(s, s->s_lem);
	ft_render_boxes(s);
	SDL_RenderPresent(s->prenderer);
	while (SDL_WaitEvent(&(s->event)))
	{
		if (s->event.type == SDL_QUIT)
			break ;
		else if (s->event.type == SDL_KEYDOWN)
		{
			if (s->event.key.keysym.sym == SDLK_ESCAPE)
				break ;
			else if (s->event.key.keysym.scancode == 44 && s->end == 0
				&& s->s_lem->read_orders != NULL)
			{
				ft_render_menu_bg(s);
				draw_paths(s, s->s_lem);
				ft_render_boxes(s);
				render_ants(s, s->s_lem);
				SDL_RenderPresent(s->prenderer);
			}
		}
	}
	free_textures(s);
	if (s->pwindow)
		SDL_DestroyWindow(s->pwindow);
	SDL_Quit();
}

void	record_max(t_s *s, t_sdl *sdl)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < s->room_count)
	{
		x = s->barr[i].x;
		y = s->barr[i].y;
		if (x > sdl->max_x)
			sdl->max_x = x;
		if (x < sdl->min_x)
			sdl->min_x = x;
		if (y > sdl->max_y)
			sdl->max_y = y;
		if (y < sdl->min_y)
			sdl->min_y = y;
		i++;
	}
}

void	ft_initialize_ants(t_s *s)
{
	int		i;

	if (!(s->ants = (t_ant *)malloc(sizeof(t_ant) * s->nb_ants)))
		exit(-1);
	i = 0;
	while (i < s->nb_ants)
	{
		s->ants[i].ant_idx = i;
		s->ants[i].idx_pos = s->start_idx;
		i++;
	}
}

int		main(void)
{
	t_sdl	*sdl;

	sdl = initialize_struct_graph();
	ft_parse(sdl);
	ft_initialize_ants(sdl->s_lem);
	record_max(sdl->s_lem, sdl);
	if (sdl->max_x - sdl->min_x < WIDTH && sdl->max_y - sdl->min_y < HEIGHT)
		ft_render(sdl);
	else
		ft_printf("Coordinates range is too important to be displayed.\n");
	return (0);
}
