/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/03 18:05:12 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "philo.h"

void		error(char e, char *msg)
{
	if (e == USAGE)
		fail("Usage: "), fail(msg), failn(".");
	else if (e == ENV)
		failn("Env not found.");
	else if (e == THR_CREATE)
		failn("Error while creating thread.");
	else if (e == THR_JOIN)
		failn("Error while joining thread.");
	else if (e == SDL_INIT)
		failn("SDL_Init failed.");
	else if (e == SDL_SETVIDEO)
		failn("SDL_SetVideoMode failed.");
	g_exit = TRUE; //TODO: be sure it will exit before IMPLOSION
}
