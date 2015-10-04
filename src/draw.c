/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 03:18:55 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/04 18:06:23 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle SDL stuffs
*/

#include "philo.h"

static void		init_sticks_pos(t_sdl *sdl)
{
	(sdl->sticks_pos + 0)->x = (Sint16)STICK0_X;
	(sdl->sticks_pos + 0)->y = (Sint16)STICK0_Y;
	(sdl->sticks_pos + 1)->x = (Sint16)STICK1_X;
	(sdl->sticks_pos + 1)->y = (Sint16)STICK1_Y;
	(sdl->sticks_pos + 2)->x = (Sint16)STICK2_X;
	(sdl->sticks_pos + 2)->y = (Sint16)STICK2_Y;
	(sdl->sticks_pos + 3)->x = (Sint16)STICK3_X;
	(sdl->sticks_pos + 3)->y = (Sint16)STICK3_Y;
	(sdl->sticks_pos + 4)->x = (Sint16)STICK4_X;
	(sdl->sticks_pos + 4)->y = (Sint16)STICK4_Y;
	(sdl->sticks_pos + 5)->x = (Sint16)STICK5_X;
	(sdl->sticks_pos + 5)->y = (Sint16)STICK5_Y;
	(sdl->sticks_pos + 6)->x = (Sint16)STICK6_X;
	(sdl->sticks_pos + 6)->y = (Sint16)STICK6_Y;
}

static void		move_sticks(t_sdl *sdl, t_philo **ph)
{
	init_sticks_pos(sdl);
	move_eating_sticks(sdl, ph);
	move_thinking_sticks(sdl, ph);
}

void			event_sdl(void)
{
	SDL_Event event;

	while (TRUE)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN)
			break ;
	}
	g_exit = TRUE;
}

static void		debug(t_philo **ph)
{
	int		i;

	i = -1;
	while (++i < NB_PHILO)
	{
		ft_putstr("id:");
		ft_putnbr(i);
		ft_putstr(" life:");
		ft_putnbr((*ph + i)->life);
		ft_putstr("\tstate:");
		if ((*ph + i)->state == THINK)
			ft_putendl("think");
		else if ((*ph + i)->state == REST)
			ft_putendl("rest");
		else
			ft_putendl("eat");	 
	}
	ft_putendl("");
}

void			time_loop(t_sdl *sdl, t_philo **ph, t_bool think)
{
	int		i;

	SDL_FillRect(sdl->screen, NULL, \
				 SDL_MapRGB(sdl->screen->format, 255, 255, 255));
	SDL_BlitSurface(sdl->rice, NULL, sdl->screen, &sdl->rice_pos);

	i = -1;
	while (++i < NB_PHILO)
	{
		if (((*ph + i - (i == 0 ? -(NB_PHILO - 1) : 1))->state == REST \
	|| (*ph + i + (i == NB_PHILO - 1 ? -(NB_PHILO - 1) : 1))->state == REST) \
	&& (*ph + i)->state == REST && think)
			(*ph + i)->state = THINK; //handle think state

		SDL_BlitSurface(*(sdl->smurfs + i), NULL, sdl->screen, \
						sdl->smurfs_pos + i); //draw smurfs
	}
	move_sticks(sdl, ph);
	i = -1;
	while (++i < NB_PHILO)
		SDL_BlitSurface(*(sdl->sticks + i), NULL, sdl->screen, \
						sdl->sticks_pos + i);	 //draw sticks
	i = -1;
	while (++i < NB_PHILO)
	{
		sdl->lives[i]->w = 80 * (*ph + i)->life / MAX_LIFE;
		SDL_FillRect(*(sdl->lives + i), NULL,					\
					 SDL_MapRGB(sdl->screen->format, 255, 0, 0));
		SDL_BlitSurface(*(sdl->lives + i), NULL, sdl->screen, \
						sdl->lives_pos + i); //draw life
	}

	debug(ph); //infos to stdout
}
