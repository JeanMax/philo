/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:28:24 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 02:58:13 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** hooks et plus si affinité
*/

#include "header.h"

int						 ex_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	if (!(e->img = mlx_new_image(e->mlx, WIN_SIZE, WIN_SIZE)))
		error(IMG_PTR);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->x_len), &(e->endian));
	if (!e->data)
		error(MLX_DATA);
	return (0);
}

int			key_hook(int key, t_env *e)
{
	if (key == ESC)
		exit(0);
	e = e;
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	button = button;
	x = x;
	y = y;
	e = e;
	return (0);
}

int			mouse_move(int x, int y, t_env *e)
{
	x = x;
	y = y;
	e = e;
	return (0);
}

int			loop_hook(t_env *e)
{
	if (e->hooking)
	{
		ex_hook(e);
		e->hooking = 0;
	}
	return (0);
}
