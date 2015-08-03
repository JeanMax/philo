/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/03 14:01:51 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "header.h"

void		error(char e, char *msg)
{
	if (e == USAGE)
		fail("Usage: "), fail(msg), failn(USAGE_MSG);
	else if (e == THR_CREATE)
		fail(THR_CREATE_MSG);
	else if (e == THR_JOIN)
		fail(THR_JOIN_MSG);
	exit(-1);
}
