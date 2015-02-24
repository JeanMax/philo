/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:09:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 06:06:06 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main!;D
*/

#include "header.h"

static void		*thread_it(void *arg)
{
	t_ob		*tob;
	int			i;
	
	tob = (t_ob *)arg;
	usleep(2000000);
	i = 0;
	ft_debugstr("1", "1");
	while (i < 7)
		pthread_mutex_lock(&(tob->baguette[i++]));
	tob->test += 10;
	ft_debugstr("LOCKED?", "ZBOUB");
	if (tob->test == 10)
		tob->test -= 10;
	usleep(2000000);
	i = 0;
	while (i < 7)
		pthread_mutex_unlock(&(tob->baguette[i++]));
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
	t_ob		tob;

	av = av; //debug
	if (ac != 1)
		error(USAGE);
	init(&e);

	i = 0;
	while (i < 7)
		pthread_mutex_init(&(tob.baguette[i++]), NULL);
	tob.test = 0;
	i = 0;
	ft_debugnbr("I'm before the thread", tob.test);
	while (i < 7)
	{
		tob.which_bag = i;
		if (pthread_create(&t[i++], NULL, thread_it, (void *)&tob))
			error(THR_CRE);
	}
	i = 0;
	while (i < 7)
		if (pthread_join(t[i++], NULL))
			error(THR_JOI);
	ft_debugnbr("I'm after the thread", tob.test);

	mlx_loop(e.mlx);
	return (0);
}
