/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/05 18:42:26 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "header.h"

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
	exit(EXIT_FAILURE);
}
