/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 03:18:55 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/01 04:59:07 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle SDL stuffs
*/

#include "header.h"

void			event_sdl(void)
{
	SDL_Event event;

	while (TRUE)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			break ;
	}
	SDL_Quit();
	exit(EXIT_SUCCESS);
}

static void		*timer_thread(void *arg)
{
	size_t		t;
	SDL_Surface	*screen;

	screen = (SDL_Surface *)arg;
	t = TIMEOUT;
	while (t--)
	{
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 150, 0, 0)); //bg
		SDL_Flip(screen); //refresh
		sleep(1);
	}
	ft_debugnbr("TIMEOUT", 42); //debug
	SDL_Quit();
	exit(EXIT_SUCCESS);
}

void			time_loop(void)
{
	pthread_t		timer;
	SDL_Surface		*screen;

	//init SDL
	//screen = NULL; //useless?
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		error(SDL_INIT, NULL);
	if (!(screen = SDL_SetVideoMode(WIN_WIDTH, WIN_HEIGHT, WIN_BPP, \
						SDL_HWSURFACE | SDL_DOUBLEBUF)))
		error(SDL_SETVIDEO, NULL); //SDL_GetError());
	SDL_WM_SetCaption("Zboub", NULL);

	//timer thread
	if (pthread_create(&timer, NULL, timer_thread, (void *)screen))
		error(THR_CREATE, NULL);

}
