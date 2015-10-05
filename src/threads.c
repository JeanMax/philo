/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 03:32:31 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/05 20:41:09 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** threads handling
*/

#include "philo.h"

void			*timer_thread(void *ph)
{
	int			t;
	t_sdl		sdl;

	if (!(sdl.screen = SDL_SetVideoMode(WIN_WIDTH, WIN_HEIGHT, WIN_BPP, \
									SDL_HWSURFACE | SDL_DOUBLEBUF)))
		error(SDL_SETVIDEO, NULL);
	init_smurfs(&sdl);
	init_sticks(&sdl);
	init_lives(&sdl);
	t = -1;
	while (++t <= TIMEOUT && !g_exit)
	{
		ft_putstr("time:");
		ft_putnbr(t);
		ft_putendl("s");
		time_loop(&sdl, (t_philo **)ph, t ? TRUE : FALSE);
		SDL_Flip(sdl.screen);
		usleep(1000000);
	}
	if (t > TIMEOUT)
		ft_putendl("Now, it is time... To DAAAAAAAANCE!!!");
	while (TRUE)
		usleep(1000000);
	exit(EXIT_SUCCESS);
	return (NULL);
}

void			*philo_thread(void *arg)
{
	t_philo		*ph;

	ph = (t_philo *)arg;
	usleep(1000000);
	while (ph->life > 0 && !g_exit)
		if (ph->state != EAT && !pthread_mutex_trylock(ph->l_stick))
		{
			if (!pthread_mutex_trylock(ph->r_stick))
			{
				eat(ph);
				pthread_mutex_unlock(ph->r_stick);
				pthread_mutex_unlock(ph->l_stick);
			}
			else
			{
				rest(ph);
				pthread_mutex_unlock(ph->l_stick);
			}
		}
		else
			rest(ph);
	if (ph->life <= 0 && !g_exit)
		ft_debugnbr("DEAD", (int)ph->id);
	g_exit = TRUE;
	return (NULL);
}

t_philo			**launch_threads(pthread_t *philo)
{
	static t_philo			*ph;
	static pthread_mutex_t	*stick;
	size_t					i;

	ph = malloc(sizeof(t_philo) * NB_PHILO);
	stick = malloc(sizeof(pthread_mutex_t) * NB_PHILO);
	i = 0;
	while (i < NB_PHILO)
		pthread_mutex_init(&(stick[i++]), NULL);
	i = 0;
	while (i < NB_PHILO)
	{
		ph[i].life = MAX_LIFE;
		ph[i].state = REST;
		ph[i].l_stick = &stick[i];
		ph[i].r_stick = &stick[i + 1 >= NB_PHILO ? 0 : i + 1];
		ph[i].id = i;
		if (pthread_create(&philo[i], NULL, philo_thread, (void *)&ph[i]))
			error(THR_CREATE, NULL);
		i++;
	}
	return (&ph);
}

void			join_threads(pthread_t *philo)
{
	size_t			i;

	i = 0;
	while (i < NB_PHILO)
		if (pthread_join(philo[i++], NULL))
			error(THR_JOIN, NULL);
}
