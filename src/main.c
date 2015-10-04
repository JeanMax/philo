/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:09:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/04 04:34:57 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main!;D
*/

#include "philo.h"

t_bool			g_exit;

int				main(int ac, char **av, char **ae)
{
	pthread_t		philo[NB_PHILO + 1];
	pthread_t		timer;

	g_exit = FALSE;
	if (ac != 1)
		error(USAGE, *av);
	if (!*ae)
		error(ENV, NULL);

	//init SDL
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		error(SDL_INIT, NULL);
	SDL_WM_SetIcon(SDL_LoadBMP("img/smurf/smurf4.bmp"), NULL);
	SDL_WM_SetCaption("Philosmurf", NULL);


	//timer thread
	if (pthread_create(&timer, NULL, timer_thread, \
					   (void *)launch_threads(philo)))
		error(THR_CREATE, NULL);

	event_sdl();

	join_threads(philo);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
