/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/05 20:47:00 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

/*
** define
*/
# define PHILO_H

# define MAX_LIFE	9
# define EAT_T		2
# define REST_T		1
# define THINK_T	1
# define TIMEOUT	60

# define NB_PHILO	7
# define WIN_HEIGHT	700
# define WIN_WIDTH	700
# define WIN_BPP	32
# define LIFE_ARGS	80, 15, 32, 0, 0, 0, 0

# define SMURF0_X	(WIN_WIDTH / 2 - 50)
# define SMURF0_Y	(WIN_HEIGHT / 6 - 100 + 40)
# define SMURF1_X	(WIN_WIDTH * 4 / 6)
# define SMURF1_Y	(WIN_HEIGHT / 6 + 40)
# define SMURF2_X	(WIN_WIDTH * 4 / 6 + 50)
# define SMURF2_Y	(WIN_HEIGHT / 2 - 50 + 40)
# define SMURF3_X	(WIN_WIDTH * 4 / 6 - 50)
# define SMURF3_Y	(WIN_HEIGHT * 4 / 6 + 40)
# define SMURF4_X	(WIN_WIDTH / 6 + 50)
# define SMURF4_Y	(WIN_HEIGHT * 4 / 6 + 40)
# define SMURF5_X	(WIN_WIDTH / 6 - 50)
# define SMURF5_Y	(WIN_HEIGHT / 2 - 50 + 40)
# define SMURF6_X	(WIN_WIDTH / 6)
# define SMURF6_Y	(WIN_HEIGHT / 6 + 40)

# define STICK0_X	(390)
# define STICK0_Y	(30)
# define STICK1_X	(WIN_WIDTH / 1.65)
# define STICK1_Y	(WIN_HEIGHT / 2.4)
# define STICK2_X	(WIN_WIDTH / 1.6)
# define STICK2_Y	(WIN_HEIGHT / 1.8)
# define STICK3_X	(WIN_WIDTH / 2.1 + 20)
# define STICK3_Y	(WIN_HEIGHT / 1.7)
# define STICK4_X	(50)
# define STICK4_Y	(WIN_HEIGHT / 1.8)
# define STICK5_X	(10)
# define STICK5_Y	(WIN_HEIGHT / 2.4)
# define STICK6_X	(130)
# define STICK6_Y	(30)

# define STICK0_RX	(SMURF0_X - 50)
# define STICK0_RY	(STICK0_Y)
# define STICK1_RX	(STICK1_X)
# define STICK1_RY	(SMURF1_Y + 50)
# define STICK2_RX	(STICK2_X + 20)
# define STICK2_RY	(SMURF2_Y - 50)
# define STICK3_RX	(SMURF3_X + 30)
# define STICK3_RY	(STICK3_Y)
# define STICK4_RX	(SMURF4_X)
# define STICK4_RY	(SMURF4_Y - 60)
# define STICK5_RX	(STICK5_X)
# define STICK5_RY	(SMURF5_Y + 40)
# define STICK6_RX	(SMURF6_X - 60)
# define STICK6_RY	(SMURF6_Y - 70)

# define STICK0_LX	(SMURF1_X - 50)
# define STICK0_LY	(SMURF1_Y - 50)
# define STICK1_LX	(STICK1_X)
# define STICK1_LY	(SMURF2_Y + 40)
# define STICK2_LX	(SMURF3_X - 70)
# define STICK2_LY	(STICK2_Y + 30)
# define STICK3_LX	(SMURF4_X + 40)
# define STICK3_LY	(STICK3_Y)
# define STICK4_LX	(SMURF5_X - 40)
# define STICK4_LY	(SMURF5_Y - 50)
# define STICK5_LX	(SMURF6_X - 70)
# define STICK5_LY	(SMURF6_Y + 30)
# define STICK6_LX	(SMURF0_X - 50)
# define STICK6_LY	(SMURF0_Y - 60)

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
** enum
*/
enum	e_rror
{
	USAGE,
	ENV,
	THR_CREATE,
	THR_JOIN,
	SDL_INIT,
	SDL_SETVIDEO
};

enum	e_state
{
	REST,
	EAT,
	THINK
};

/*
** globad
*/
extern t_bool			g_exit;

/*
** struct def
*/
typedef struct s_philo	t_philo;
struct					s_philo
{
	pthread_mutex_t		*r_stick;
	pthread_mutex_t		*l_stick;
	int					life;
	char				state;
	size_t				id;
};

typedef struct s_sdl	t_sdl;
struct					s_sdl
{
	SDL_Rect			*smurfs_pos;
	SDL_Rect			*sticks_pos;
	SDL_Rect			*lives_pos;
	SDL_Rect			rice_pos;
	SDL_Surface			*screen;
	SDL_Surface			*rice;
	SDL_Surface			**smurfs;
	SDL_Surface			**sticks;
	SDL_Surface			**lives;
};

/*
** prototypes
**	-error.c
*/
void					error(char e, char *msg);

/*
**	-init.c
*/
void					init_smurfs(t_sdl *sdl);
void					init_sticks(t_sdl *sdl);
void					init_lives(t_sdl *sdl);

/*
**	-draw.c
*/
void					time_loop(t_sdl *sdl, t_philo **ph, t_bool think);
void					event_sdl(void);

/*
**	-move_eating_sticks.c
*/
void					move_eating_sticks(t_sdl *sdl, t_philo **ph);

/*
**	-move_thinking_sticks.c
*/
void					move_thinking_sticks(t_sdl *sdl, t_philo **ph);

/*
**	-state.c
*/
void					rest(t_philo *ph);
void					eat(t_philo *ph);

/*
**	-threads.c
*/
void					*philo_thread(void *arg);
void					*timer_thread(void *arg);
t_philo					**launch_threads(pthread_t *philo);
void					join_threads(pthread_t *philo);

#endif
