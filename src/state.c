/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 03:21:38 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/01 03:25:35 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** states actions
*/

#include "header.h"

/*
void			think(t_philo *ph)
{
	ph->state = THINK;
	ph->life -= THINK_T;
	sleep(THINK_T);
}
*/

void			eat(t_philo *ph)
{
	ph->state = EAT;
	ph->life = MAX_LIFE;
	sleep(EAT_T);
}

void			rest(t_philo *ph)
{
	ph->state = REST;
	ph->life -= REST_T;
	sleep(REST_T);
}
