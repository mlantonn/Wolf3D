/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:48:52 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:48:52 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "block.h"

void	block_del(void *a)
{
	t_block	*b;

	b = (t_block *)a;
	if (b != NULL)
	{
		free(b);
	}
}
