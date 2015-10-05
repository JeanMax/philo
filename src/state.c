/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 03:21:38 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/05 20:27:46 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** states actions
*/

#include "philo.h"

void			eat(t_philo *ph)
{
	int	i;

	ph->state = EAT;
	ph->life = MAX_LIFE;
	i = 0;
	while (i < EAT_T && !g_exit)
	{
		usleep(1000000);
		i++;
	}
}

void			rest(t_philo *ph)
{
	int	i;

	ph->state = REST;
	i = 0;
	while (i < REST_T && !g_exit && ph->life > 0)
	{
		ph->life -= 1;
		usleep(1000000);
		i++;
	}
}
