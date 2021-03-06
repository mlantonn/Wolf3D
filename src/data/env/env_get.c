/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:49:19 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:49:19 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "singletone.h"

char	*env_get(const char *key)
{
	return (pair_get((*singletone_env())[0], key));
}
