/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:09:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/01 04:59:10 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main!;D
*/

#include "header.h"

int				main(int ac, char **av, char **ae)
{
	pthread_t		philo[NB_PHILO + 1];

	if (ac != 1)
		error(USAGE, *av);
	if (!*ae)
		error(ENV, NULL);

	//stuffs
	launch_threads(philo);
	time_loop();
	event_sdl();

	join_threads(philo);
//	SDL_Quit();	
	return (EXIT_SUCCESS);
}
