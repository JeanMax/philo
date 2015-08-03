/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/08/03 15:42:21 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H

# define MAX_LIFE 100
# define EAT_T 5
# define REST_T 5
# define TIMEOUT 120

/*
** enum
*/
enum e_zboub
{
	USAGE,
	THR_CREATE,
	THR_JOIN
};

/*
** include
*/
# include "../libft/inc/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

/*
** struct def
*/
typedef struct s_ob	t_ob;
struct	s_ob
{
	pthread_mutex_t	baguette[7];
	int				test;
	int				which_bag;
};

/*
** prototypes
*/
void		error(char e, char *msg);

#endif
