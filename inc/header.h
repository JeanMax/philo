/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/01 04:51:10 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H

# define MAX_LIFE 100
# define EAT_T 2
# define REST_T 1
# define THINK_T 1
# define TIMEOUT 4
# define NB_PHILO 3

# define WIN_HEIGHT 400
# define WIN_WIDTH 600
# define WIN_BPP 32

/*
** enum
*/
enum e_rror
{
	USAGE,
	ENV,
	THR_CREATE,
	THR_JOIN,
	SDL_INIT,
	SDL_SETVIDEO
};

enum e_state
{
	REST,
	EAT,
	THINK
};

/*
** include
*/
# include "libft.h"
# include "SDL.h"
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

/*
** global
extern  pthread_t       philo[NB_PHILO + 1];
*/

/*
** struct def
*/
typedef struct s_philo	t_philo;
struct	s_philo
{
	pthread_mutex_t	*r_stick;
	pthread_mutex_t	*l_stick;
	size_t			life;
	char			state;
	size_t			id;
};

/*
** prototypes
**	-error.c
*/
void			error(char e, char *msg);

/*
**	-draw.c
*/
void			time_loop(void);
void			event_sdl(void);

/*
**	-state.c
*/
void			rest(t_philo *ph);
void			eat(t_philo *ph);
//void			think(t_philo *ph);

/*
**	-threads.c
*/
void			*philo_thread(void *arg);
void			launch_threads(pthread_t *philo);
void			join_threads(pthread_t *philo);


#endif
