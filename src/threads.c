/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 03:32:31 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/01 04:42:50 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** threads handling
*/

#include "header.h"

void			*philo_thread(void *arg)
{
	t_philo		*ph;

	ph = (t_philo *)arg;
	while (ph->life > 0)
	{
		ft_debugnbr("id", (int)ph->id); //debug
		ft_debugnbr("life", (int)ph->life); //debug
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
	}
	ft_debugnbr("DEAD", (int)ph->id); //debug
	return (NULL);
}

void			launch_threads(pthread_t *philo)
{
//	t_philo			ph[NB_PHILO];
//	pthread_mutex_t stick[NB_PHILO];
	t_philo			*ph = malloc(sizeof(t_philo) * NB_PHILO); //TODO: free
	pthread_mutex_t *stick = malloc(sizeof(pthread_mutex_t) * NB_PHILO); //TODO: free
	size_t			i;

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
