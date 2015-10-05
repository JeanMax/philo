/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_eating_sticks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 17:33:51 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/05 20:39:01 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** if forest moving sticks...
*/

#include "philo.h"

static void	move_eating_sticks3(t_sdl *sdl, t_philo **ph)
{
	if ((*ph + 5)->state == EAT)
	{
		(sdl->sticks_pos + 5)->x = (Sint16)STICK5_RX;
		(sdl->sticks_pos + 5)->y = (Sint16)STICK5_RY;
		(sdl->sticks_pos + 4)->x = (Sint16)STICK4_LX;
		(sdl->sticks_pos + 4)->y = (Sint16)STICK4_LY;
	}
	if ((*ph + 6)->state == EAT)
	{
		(sdl->sticks_pos + 6)->x = (Sint16)STICK6_RX;
		(sdl->sticks_pos + 6)->y = (Sint16)STICK6_RY;
		(sdl->sticks_pos + 5)->x = (Sint16)STICK5_LX;
		(sdl->sticks_pos + 5)->y = (Sint16)STICK5_LY;
	}
}

static void	move_eating_sticks2(t_sdl *sdl, t_philo **ph)
{
	if ((*ph + 3)->state == EAT)
	{
		(sdl->sticks_pos + 3)->x = (Sint16)STICK3_RX;
		(sdl->sticks_pos + 3)->y = (Sint16)STICK3_RY;
		(sdl->sticks_pos + 2)->x = (Sint16)STICK2_LX;
		(sdl->sticks_pos + 2)->y = (Sint16)STICK2_LY;
	}
	if ((*ph + 4)->state == EAT)
	{
		(sdl->sticks_pos + 4)->x = (Sint16)STICK4_RX;
		(sdl->sticks_pos + 4)->y = (Sint16)STICK4_RY;
		(sdl->sticks_pos + 3)->x = (Sint16)STICK3_LX;
		(sdl->sticks_pos + 3)->y = (Sint16)STICK3_LY;
	}
}

void		move_eating_sticks(t_sdl *sdl, t_philo **ph)
{
	if ((*ph + 0)->state == EAT)
	{
		(sdl->sticks_pos + 0)->x = (Sint16)STICK0_RX;
		(sdl->sticks_pos + 0)->y = (Sint16)STICK0_RY;
		(sdl->sticks_pos + 6)->x = (Sint16)STICK6_LX;
		(sdl->sticks_pos + 6)->y = (Sint16)STICK6_LY;
	}
	if ((*ph + 1)->state == EAT)
	{
		(sdl->sticks_pos + 1)->x = (Sint16)STICK1_RX;
		(sdl->sticks_pos + 1)->y = (Sint16)STICK1_RY;
		(sdl->sticks_pos + 0)->x = (Sint16)STICK0_LX;
		(sdl->sticks_pos + 0)->y = (Sint16)STICK0_LY;
	}
	if ((*ph + 2)->state == EAT)
	{
		(sdl->sticks_pos + 2)->x = (Sint16)STICK2_RX;
		(sdl->sticks_pos + 2)->y = (Sint16)STICK2_RY;
		(sdl->sticks_pos + 1)->x = (Sint16)STICK1_LX;
		(sdl->sticks_pos + 1)->y = (Sint16)STICK1_LY;
	}
	move_eating_sticks2(sdl, ph);
	move_eating_sticks3(sdl, ph);
}
