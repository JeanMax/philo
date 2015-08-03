/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:09:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/03 14:02:44 by mcanal           ###   ########.fr       */
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

int				main(int ac, char **av)
{
	pthread_t	t[7];
	int			i;
	t_ob		tob;

	(void)av; //debug
	if (ac != 1)
		error(USAGE, *av);

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
			error(THR_CREATE, NULL);
	}
	i = 0;
	while (i < 7)
		if (pthread_join(t[i++], NULL))
			error(THR_JOIN, NULL);
	ft_debugnbr("I'm after the thread", tob.test);

	return (0);
}
