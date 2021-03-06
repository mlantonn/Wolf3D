/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_get_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:40 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:41 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loaded.h"
#include "mysdl.h"
#include "sg.h"
#include "texture.h"

#define FL double

t_col	texture_get_color(const t_texture *t, const double y, const double x)
{
	static unsigned int	(*get[T_TEX_SIZE])(const void *, const FL, const FL) = {
		[T_TEX_LOADED] = &texture_loaded_get_color,
		[T_TEX_SG] = &texture_sg_get_color
	};
	t_col				res;

	if (t != NULL && t->type < T_TEX_SIZE)
	{
		res.c = get[t->type](t->node, y, x);
	}
	else
		res.c = 0;
	return (res);
}
