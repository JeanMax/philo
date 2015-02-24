/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 20:39:30 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 03:35:22 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** errors handling
*/

#include "header.h"

void			error(t_char c)
{
	if (c == USAGE)
		failn(USAGE_MSG);
	else if (c == IMG_PTR)
		failn(IMG_PTR_MSG);
	else if (c == PUT_PIX)
		failn(PUT_PIX_MSG);
	else if (c == MLX_INI)
		failn(MLX_INI_MSG);
	else if (c == MLX_WIN)
		failn(MLX_WIN_MSG);
	else if (c == MLX_DATA)
		failn(MLX_DATA_MSG);
	else if (c == THR_CRE)
		failn(THR_CRE_MSG);
	else if (c == THR_JOI)
		failn(THR_JOI_MSG);
	exit(-1);
}
