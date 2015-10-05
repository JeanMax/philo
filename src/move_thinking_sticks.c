/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_thinking_sticks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 17:33:51 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/05 20:39:53 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** if forest moving sticks...
*/

#include "philo.h"

static void	assign(SDL_Rect *pos, Sint16 x, Sint16 y)
{
	pos->x = x;
	pos->y = y;
}

static void	move_thinking_sticks2(t_sdl *sdl, t_philo **ph)
{
	if ((*ph + 2)->state == THINK)
	{
		if (!(int)((sdl->sticks_pos + 2)->x - (Sint16)STICK2_X) && \
			!(int)((sdl->sticks_pos + 2)->y - (Sint16)STICK2_Y))
			assign((sdl->sticks_pos + 2), (Sint16)STICK2_RX, (Sint16)STICK2_RY);
		else
			assign((sdl->sticks_pos + 1), (Sint16)STICK1_LX, (Sint16)STICK1_LY);
	}
	if ((*ph + 3)->state == THINK)
	{
		if (!(int)((sdl->sticks_pos + 3)->x - (Sint16)STICK3_X) && \
			!(int)((sdl->sticks_pos + 3)->y - (Sint16)STICK3_Y))
			assign((sdl->sticks_pos + 3), (Sint16)STICK3_RX, (Sint16)STICK3_RY);
		else
			assign((sdl->sticks_pos + 2), (Sint16)STICK2_LX, (Sint16)STICK2_LY);
	}
	if ((*ph + 4)->state == THINK)
	{
		if (!(int)((sdl->sticks_pos + 4)->x - (Sint16)STICK4_X) && \
			!(int)((sdl->sticks_pos + 4)->y - (Sint16)STICK4_Y))
			assign((sdl->sticks_pos + 4), (Sint16)STICK4_RX, (Sint16)STICK4_RY);
		else
			assign((sdl->sticks_pos + 3), (Sint16)STICK3_LX, (Sint16)STICK3_LY);
	}
}

static void	move_thinking_sticks3(t_sdl *sdl, t_philo **ph)
{
	if ((*ph + 5)->state == THINK)
	{
		if (!(int)((sdl->sticks_pos + 5)->x - (Sint16)STICK5_X) && \
			!(int)((sdl->sticks_pos + 5)->y - (Sint16)STICK5_Y))
			assign((sdl->sticks_pos + 5), (Sint16)STICK5_RX, (Sint16)STICK5_RY);
		else
			assign((sdl->sticks_pos + 4), (Sint16)STICK4_LX, (Sint16)STICK4_LY);
	}
	if ((*ph + 6)->state == THINK)
	{
		if (!(int)((sdl->sticks_pos + 6)->x - (Sint16)STICK6_X) && \
			!(int)((sdl->sticks_pos + 6)->y - (Sint16)STICK6_Y))
			assign((sdl->sticks_pos + 6), (Sint16)STICK6_RX, (Sint16)STICK6_RY);
		else
			assign((sdl->sticks_pos + 5), (Sint16)STICK5_LX, (Sint16)STICK5_LY);
	}
}

void		move_thinking_sticks(t_sdl *sdl, t_philo **ph)
{
	if ((*ph + 0)->state == THINK)
	{
		if (!(int)((sdl->sticks_pos + 0)->x - (Sint16)STICK0_X) && \
			!(int)((sdl->sticks_pos + 0)->y - (Sint16)STICK0_Y))
			assign((sdl->sticks_pos + 0), (Sint16)STICK0_RX, (Sint16)STICK0_RY);
		else
			assign((sdl->sticks_pos + 6), (Sint16)STICK6_LX, (Sint16)STICK6_LY);
	}
	if ((*ph + 1)->state == THINK)
	{
		if (!(int)((sdl->sticks_pos + 1)->x - (Sint16)STICK1_X) && \
			!(int)((sdl->sticks_pos + 1)->y - (Sint16)STICK1_Y))
			assign((sdl->sticks_pos + 1), (Sint16)STICK1_RX, (Sint16)STICK1_RY);
		else
			assign((sdl->sticks_pos + 0), (Sint16)STICK0_LX, (Sint16)STICK0_LY);
	}
	move_thinking_sticks2(sdl, ph);
	move_thinking_sticks3(sdl, ph);
}
