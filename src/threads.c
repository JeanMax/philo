/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 03:32:31 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/04 17:00:29 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** threads handling
*/

#include "philo.h"

void			*timer_thread(void *ph)
{
	int			t;
	t_sdl		sdl; //TODO: free malloc'd elements (cf init_smurfs)

	if (!(sdl.screen = SDL_SetVideoMode(WIN_WIDTH, WIN_HEIGHT, WIN_BPP, \
									SDL_HWSURFACE | SDL_DOUBLEBUF)))
		error(SDL_SETVIDEO, NULL); //SDL_GetError());

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
		SDL_Flip(sdl.screen); //refresh
		sleep(1);
	}
	if (t > TIMEOUT)
		ft_putendl("Now, it is time... To DAAAAAAAANCE!!!");
	g_exit = TRUE;
	return (NULL);
}

void			*philo_thread(void *arg)
{
	t_philo		*ph;

	ph = (t_philo *)arg;
	sleep(1);
	while (ph->life > 0 && !g_exit)
		if (ph->state != EAT && !pthread_mutex_trylock(ph->l_stick))
		{
			if (!pthread_mutex_trylock(ph->r_stick)) //eating
			{
				eat(ph);
				pthread_mutex_unlock(ph->r_stick);
				pthread_mutex_unlock(ph->l_stick);
			}
			else //right stick busy
			{
				rest(ph);
				pthread_mutex_unlock(ph->l_stick);
			}
		}
		else //left stick busy
			rest(ph);
	if (ph->life <= 0 && !g_exit)
		ft_debugnbr("DEAD", (int)ph->id); //debug
	g_exit = TRUE;
	return (NULL);
}

t_philo			**launch_threads(pthread_t *philo)
{
	static t_philo			*ph;
	static pthread_mutex_t *stick;
	size_t			i;

	ph = malloc(sizeof(t_philo) * NB_PHILO); //TODO: free
	stick = malloc(sizeof(pthread_mutex_t) * NB_PHILO); //TODO: free
	i = 0;
	while (i < NB_PHILO)	//init all mutex
		pthread_mutex_init(&(stick[i++]), NULL);
	i = 0;
	while (i < NB_PHILO)	//create all philo threads
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

	//wait for all threads to die
	i = 0;
	while (i < NB_PHILO)
		if (pthread_join(philo[i++], NULL))
			error(THR_JOIN, NULL);
	//TODO: kill timer thread? (detach)
}
