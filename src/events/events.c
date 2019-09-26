/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:23:56 by mlantonn          #+#    #+#             */
/*   Updated: 2019/09/26 15:51:06 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static _Bool	limit_frames(void)
{
	static unsigned int	last_time = 0;
	static unsigned int	current_time;

	current_time = SDL_GetTicks();
	if (current_time < last_time + 10)
		return (1);
	last_time = current_time;
	return (0);
}

_Bool			event_loop(t_e *e)
{
	static _Bool	key_downs[4] = (_Bool[4]){0, 0, 0, 0};
	SDL_Event		ev;

	while (1)
	{
		if (limit_frames())
			continue ;
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT || (ev.type == SDL_KEYDOWN
				&& ev.key.keysym.sym == SDLK_ESCAPE))
				return (EXIT_SUCCESS);
			if (ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP)
				key_event(e, key_downs, ev);
			if (ev.type == SDL_MOUSEMOTION)
				mouse_event(e, ev);
			if (ev.type == SDL_WINDOWEVENT && window_event(e, ev))
				return (EXIT_FAILURE);
		}
		if (update_cam(e, key_downs))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}