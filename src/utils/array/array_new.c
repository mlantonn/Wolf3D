/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:14 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:14 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "wutils.h"

t_array	*array_new(size_t p_size)
{
	t_array	*a;
	size_t	capacity;

	a = (t_array *)malloc(sizeof(*a));
	if (a != NULL)
	{
		capacity = round_up_pow(p_size);
		a->p = malloc(capacity);
		if (a->p != NULL)
		{
			a->p_size = p_size;
			a->capacity = capacity;
			a->length = 0;
		}
		else
		{
			free(a);
			a = NULL;
		}
	}
	return (a);
}
