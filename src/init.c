/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 03:56:21 by mcanal            #+#    #+#             */
/*   Updated: 2015/10/04 18:05:49 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** init some sdl stuffs
*/

#include "philo.h"

static void	fade_sticks(t_sdl *sdl)
{
	int	i;

	i = -1;
	while (++i < 7)
		SDL_SetColorKey(*(sdl->sticks + i), SDL_SRCCOLORKEY,			\
					SDL_MapRGB((*(sdl->sticks + i))->format, 255, 255, 255));
	sdl->rice = SDL_LoadBMP("img/rice.bmp");
	sdl->rice_pos.x = (Sint16)(WIN_WIDTH / 2.2);
	sdl->rice_pos.y = (Sint16)(WIN_HEIGHT / 2.5);
	SDL_SetColorKey(sdl->rice, SDL_SRCCOLORKEY,				\
				SDL_MapRGB(sdl->rice->format, 255, 255, 255));
}

void		init_sticks(t_sdl *sdl)
{
	sdl->sticks = malloc(sizeof(SDL_Surface *) * 7); //TODO: free
	sdl->sticks_pos = malloc(sizeof(SDL_Rect) * 7); //TODO: free
	*sdl->sticks = SDL_LoadBMP("img/stick/stick4.bmp");
	sdl->sticks_pos->x = (Sint16)STICK0_X;
	sdl->sticks_pos->y = (Sint16)STICK0_Y;
	*(sdl->sticks + 1) = SDL_LoadBMP("img/stick/stick5.bmp");
	(sdl->sticks_pos + 1)->x = (Sint16)STICK1_X;
	(sdl->sticks_pos + 1)->y = (Sint16)STICK1_Y;
	*(sdl->sticks + 2) = SDL_LoadBMP("img/stick/stick6.bmp");
	(sdl->sticks_pos + 2)->x = (Sint16)STICK2_X;
	(sdl->sticks_pos + 2)->y = (Sint16)STICK2_Y;
	*(sdl->sticks + 3) = SDL_LoadBMP("img/stick/stick0.bmp");
	(sdl->sticks_pos + 3)->x = (Sint16)STICK3_X;
	(sdl->sticks_pos + 3)->y = (Sint16)STICK3_Y;
	*(sdl->sticks + 4) = SDL_LoadBMP("img/stick/stick1.bmp");
	(sdl->sticks_pos + 4)->x = (Sint16)STICK4_X;
	(sdl->sticks_pos + 4)->y = (Sint16)STICK4_Y;
	*(sdl->sticks + 5) = SDL_LoadBMP("img/stick/stick2.bmp");
	(sdl->sticks_pos + 5)->x = (Sint16)STICK5_X;
	(sdl->sticks_pos + 5)->y = (Sint16)STICK5_Y;
	*(sdl->sticks + 6) = SDL_LoadBMP("img/stick/stick3.bmp");
	(sdl->sticks_pos + 6)->x = (Sint16)STICK6_X;
	(sdl->sticks_pos + 6)->y = (Sint16)STICK6_Y;
	fade_sticks(sdl);
}

void		init_smurfs(t_sdl *sdl)
{
	sdl->smurfs = malloc(sizeof(SDL_Surface *) * 7); //TODO: free
	sdl->smurfs_pos = malloc(sizeof(SDL_Rect) * 7); //TODO: free
	*sdl->smurfs = SDL_LoadBMP("img/smurf/smurf5.bmp");
	sdl->smurfs_pos->x = (Sint16)SMURF0_X;
	sdl->smurfs_pos->y = (Sint16)SMURF0_Y;
	*(sdl->smurfs + 1) = SDL_LoadBMP("img/smurf/smurf1.bmp");
	(sdl->smurfs_pos + 1)->x = (Sint16)SMURF1_X;
	(sdl->smurfs_pos + 1)->y = (Sint16)SMURF1_Y;
	*(sdl->smurfs + 2) = SDL_LoadBMP("img/smurf/smurf4.bmp");
	(sdl->smurfs_pos + 2)->x = (Sint16)SMURF2_X;
	(sdl->smurfs_pos + 2)->y = (Sint16)SMURF2_Y;
	*(sdl->smurfs + 3) = SDL_LoadBMP("img/smurf/smurf6.bmp");
	(sdl->smurfs_pos + 3)->x = (Sint16)SMURF3_X;
	(sdl->smurfs_pos + 3)->y = (Sint16)SMURF3_Y;
	*(sdl->smurfs + 4) = SDL_LoadBMP("img/smurf/smurf2.bmp");
	(sdl->smurfs_pos + 4)->x = (Sint16)SMURF4_X;
	(sdl->smurfs_pos + 4)->y = (Sint16)SMURF4_Y;
	*(sdl->smurfs + 5) = SDL_LoadBMP("img/smurf/smurf3.bmp");
	(sdl->smurfs_pos + 5)->x = (Sint16)SMURF5_X;
	(sdl->smurfs_pos + 5)->y = (Sint16)SMURF5_Y;
	*(sdl->smurfs + 6) = SDL_LoadBMP("img/smurf/smurf0.bmp");
	(sdl->smurfs_pos + 6)->x = (Sint16)SMURF6_X;
	(sdl->smurfs_pos + 6)->y = (Sint16)SMURF6_Y;
}

void		init_lives(t_sdl *sdl)
{
	sdl->lives = malloc(sizeof(SDL_Surface *) * 7); //TODO: free
	sdl->lives_pos = malloc(sizeof(SDL_Rect) * 7); //TODO: free
	*(sdl->lives + 0) = SDL_CreateRGBSurface(SDL_HWSURFACE, LIFE_ARGS);
	(sdl->lives_pos + 0)->x = (Sint16)SMURF0_X + 10;
	(sdl->lives_pos + 0)->y = (Sint16)SMURF0_Y + 105;
	*(sdl->lives + 1) = SDL_CreateRGBSurface(SDL_HWSURFACE, LIFE_ARGS);
	(sdl->lives_pos + 1)->x = (Sint16)SMURF1_X + 10;
	(sdl->lives_pos + 1)->y = (Sint16)SMURF1_Y + 105;
	*(sdl->lives + 2) = SDL_CreateRGBSurface(SDL_HWSURFACE, LIFE_ARGS);
	(sdl->lives_pos + 2)->x = (Sint16)SMURF2_X + 10;
	(sdl->lives_pos + 2)->y = (Sint16)SMURF2_Y + 105;
	*(sdl->lives + 3) = SDL_CreateRGBSurface(SDL_HWSURFACE, LIFE_ARGS);
	(sdl->lives_pos + 3)->x = (Sint16)SMURF3_X + 10;
	(sdl->lives_pos + 3)->y = (Sint16)SMURF3_Y + 105;
	*(sdl->lives + 4) = SDL_CreateRGBSurface(SDL_HWSURFACE, LIFE_ARGS);
	(sdl->lives_pos + 4)->x = (Sint16)SMURF4_X + 10;
	(sdl->lives_pos + 4)->y = (Sint16)SMURF4_Y + 105;
	*(sdl->lives + 5) = SDL_CreateRGBSurface(SDL_HWSURFACE, LIFE_ARGS);
	(sdl->lives_pos + 5)->x = (Sint16)SMURF5_X - 10;
	(sdl->lives_pos + 5)->y = (Sint16)SMURF5_Y + 105;
	*(sdl->lives + 6) = SDL_CreateRGBSurface(SDL_HWSURFACE, LIFE_ARGS);
	(sdl->lives_pos + 6)->x = (Sint16)SMURF6_X + 10;
	(sdl->lives_pos + 6)->y = (Sint16)SMURF6_Y + 105;
}
