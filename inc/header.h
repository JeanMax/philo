/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 03:34:47 by mcanal           ###   ########.fr       */
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
# define WIN_SIZE 600
# define ESC 65307
# define ENTER 65293
# define NUM_PLUS 65451
# define NUM_MINUS 65453
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define PAGE_UP 65365
# define PAGE_DOWN 65366
# define SPACE 32
# define ONE 65457
# define TWO 65458
# define THREE 65459
# define FOUR 65460
# define FIVE 65461
# define SIX 65462
# define L_CTRL 65507
# define LEFT_CLICK 1
# define RIGHT_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define USAGE 1
# define USAGE_MSG "Usage: ./philo"
# define IMG_PTR 2
# define IMG_PTR_MSG "Error while creating img pointer."
# define PUT_PIX 3
# define PUT_PIX_MSG "Error while trying to put pixel out of image."
# define MLX_INI 4
# define MLX_INI_MSG "Error while launching mlx."
# define MLX_WIN 5
# define MLX_WIN_MSG "Error while creating new window."
# define MLX_DATA 6
# define MLX_DATA_MSG "Error while getting mlx data adress."
# define THR_CRE 7
# define THR_CRE_MSG "Error while creating thread."
# define THR_JOI 8
# define THR_JOI_MSG "Error while joining thread."

/*
** include
*/
# include "../libft/inc/libft.h"
# include <X11/X.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

/*
** struct def
*/
typedef struct s_env	t_env;
struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				x_len;
	int				endian;
	char			*data;
	t_char			hooking;
};

/*
** prototypes
*/
void	error(t_char c);
int		key_hook(int key, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		mouse_move(int x, int y, t_env *e);
int		ex_hook(t_env *e);
int		loop_hook(t_env *e);
void	put_pixel_to_img(t_env *e, int x, int y, int color);

#endif
