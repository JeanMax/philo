/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:09:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 04:12:48 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main!;D
*/

#include "header.h"

static void		*thread_it(void *arg)
{
	usleep(1000000);
	ft_debugstr("", (char *)arg);
	usleep(1000000);
	return (NULL);
}

static void		init(t_env *e)
{
	e->hooking = 1;
	if (!(e->mlx = mlx_init()))
		error(MLX_INI);
	if (!(e->win = mlx_new_window(e->mlx, WIN_SIZE, WIN_SIZE, "PhiloZboub")))
		error(MLX_WIN);
	if (!(e->img = mlx_new_image(e->mlx, WIN_SIZE, WIN_SIZE)))
		error(IMG_PTR);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->x_len), &(e->endian));
	if (!e->data)
		error(MLX_DATA);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_hook(e->win, MotionNotify, PointerMotionMask, mouse_move, e);
	mlx_expose_hook(e->win, ex_hook, e);
}

int				main(int ac, char **av)
{
	t_env		e;
	pthread_t	t[7];
	int			i;

	av = av; //debug
	if (ac != 1)
		error(USAGE);
	init(&e);

	ft_debugstr("I'm before the thread", "-1");
	i = 0;
	while (i <= 7)
	{
		if (pthread_create(&t[i], NULL, thread_it, (void *)ft_itoa(i)))
			error(THR_CRE);
		i++;
	}
	i = 0;
	while (i <= 7)
		if (pthread_join(t[i++], NULL))
			error(THR_JOI);
	ft_debugstr("I'm after the thread", "10000");

	mlx_loop(e.mlx);
	return (0);
}
