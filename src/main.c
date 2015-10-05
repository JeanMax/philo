/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:09:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/05 20:38:39 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main!;D
*/

#include "philo.h"

t_bool			g_exit;

int				main(int ac, char *av[])
{
	pthread_t		philo[NB_PHILO + 1];
	pthread_t		timer;

	g_exit = FALSE;
	if (ac != 1)
		error(USAGE, *av);
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		error(SDL_INIT, NULL);
	SDL_WM_SetCaption("Philosmurf", NULL);
	SDL_WM_SetIcon(SDL_LoadBMP("img/smurf/smurf4.bmp"), NULL);
	if (pthread_create(&timer, NULL, timer_thread, \
				(void *)launch_threads(philo)))
		error(THR_CREATE, NULL);
	event_sdl();
	if (pthread_join(timer, NULL))
		error(THR_JOIN, NULL);
	join_threads(philo);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
