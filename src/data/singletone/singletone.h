/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletone.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:50:05 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:50:06 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLETONE_H
# define SINGLETONE_H

# include "block.h"
# include "env.h"
# include "map.h"
# include "texture.h"

extern t_block		***singletone_block(void);
extern void			singletone_block_del(void);

extern t_texture	***singletone_texture(void);
extern void			singletone_texture_del(void);

extern t_map		***singletone_map(void);
extern void			singletone_map_del(void);

extern t_env		***singletone_env(void);
extern void			singletone_env_del(void);
#endif
