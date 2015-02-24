/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:26:16 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 02:32:46 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mlx functions...
*/

#include "header.h"

void				put_pixel_to_img(t_env *e, int x, int y, int color)
{
	int		i;
	int		col_tmp;

	if (x > WIN_SIZE || y > WIN_SIZE)
		error(PUT_PIX);
	col_tmp = mlx_get_color_value(e->mlx, color);
	i = y * e->x_len + x * (e->bpp / 8);
	if (!(e->endian))
	{
		e->data[i] = (col_tmp & 0x0000FF);
		e->data[i + 1] = (col_tmp & 0x00FF00) >> 8;
		e->data[i + 2] = (col_tmp & 0xFF0000) >> 16;
	}
	else
	{
		e->data[i + 1] = (col_tmp & 0xFF0000) >> 8;
		e->data[i + 2] = (col_tmp & 0x00FF00) >> 16;
		e->data[i + 3] = (col_tmp & 0x0000FF) >> 24;
	}
}
