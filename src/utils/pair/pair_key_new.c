/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_key_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:51:34 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:51:34 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wutils.h"

char	*pair_key_new(const char *s)
{
	return (ft_strcdup(s, '='));
}
