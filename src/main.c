/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:09:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/05 23:37:31 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main!;D
*/

#include "header.h"

static void		think(t_philo *ph)
{
	(void)ph;
	ph->state = THINK;
	ph->life -= THINK_T;
	sleep(THINK_T);
}

static void		eat(t_philo *ph)
{
	ph->state = EAT;
	ph->life = MAX_LIFE;
	sleep(EAT_T);
}

static void		rest(t_philo *ph)
{
	ph->state = REST;
	ph->life -= REST_T;
	sleep(REST_T);
}

static void		*philo_thread(void *arg)
{
	t_philo		*ph;

	ph = (t_philo *)arg;
	ph->life = MAX_LIFE;
	ph->state = REST;
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
		{
			rest(ph);
		}
	}
	ft_debugnbr("DEAD", (int)&arg); //debug
	return (NULL);
}

static void	 event_sdl(void)
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

static void		launch_threads(pthread_t *philo)
{
	t_philo			ph[NB_PHILO];
	pthread_mutex_t stick[NB_PHILO];
	size_t			i;

	i = 0;
	while (i < NB_PHILO)	//init all mutex
		pthread_mutex_init(&(stick[i++]), NULL);
	i = 0;
	while (i < NB_PHILO)	//create all philo threads
	{
		ph[i].l_stick = &stick[i];
		ph[i].r_stick = &stick[i + 1 >= NB_PHILO ? 0 : i + 1];
		ph[i].id = i;
		if (pthread_create(&philo[i], NULL, philo_thread, (void *)&ph[i]))
			error(THR_CREATE, NULL);
		i++;
	}
}

static void		*timer_thread(void *arg)
{
	size_t		t;
	SDL_Surface	*screen;

	screen = (SDL_Surface *)arg;
	t = TIMEOUT;
	Uint8 test = 255;
	while (t--)
	{
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, test, 0, 0));
		SDL_Flip(screen); //refresh
		sleep(1);
		test -= 10;
	}
	ft_debugnbr("TIMEOUT", 42); //debug
	SDL_Quit();
	exit(EXIT_SUCCESS);
}

static void		time_loop(void)
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

static void		join_threads(pthread_t *philo)
{
	size_t			i;

	//wait for all threads to die
	i = 0;
	while (i < NB_PHILO)
		if (pthread_join(philo[i++], NULL))
			error(THR_JOIN, NULL);
	//TODO: kill timer thread? (detach)
}

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

	SDL_Quit();	
	return (EXIT_SUCCESS);
}
