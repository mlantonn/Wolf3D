/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:20:54 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/30 10:52:50 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define SKY 0x77B5FE
# define GROUND 0x9B7653

# define NORD 0
# define SUD 1
# define OUEST 2
# define EST 3
# define NONE 4

# define NB_THR 8

# include "mysdl.h"
# include "parser.h"
# include <pthread.h>
# include "map.h"

typedef struct	s_e
{
	t_sdl		sdl;
	t_map		*map;
	t_cam		cam;
	pthread_t	thread[NB_THR];
	t_img		sky;
	_Bool		show_cursor;
	_Bool		outlines;
	_Bool		skybox;
}				t_e;

typedef struct	s_blocks
{
	t_vec		total;
	t_vec		one;
}				t_blocks;

typedef struct	s_line
{
	void		*block_hit;
	double		wall_x;
	int			x;
	int			height;
	int			cardinal;
}				t_line;

_Bool			raycasting(t_e *e);
void			process_ray(t_e *e, t_vec ray, t_pos pos, int x);
void			draw_line(t_e *e, t_line line, t_vec hit);

t_vec			vec_add(t_vec u, t_vec v);
t_vec			vec_substract(t_vec u, t_vec v);
t_vec			vec_multiply(t_vec u, double t);
t_vec			vec_normalize(t_vec u);

#endif
