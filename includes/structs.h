/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 03:05:42 by home              #+#    #+#             */
/*   Updated: 2020/07/30 19:19:42 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct	s_display
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}				t_display;

typedef	struct	s_bubble
{
	double		x;
	double		y;

	int			r;

	double		vel_x;
	double		vel_y;

	double		imp_x;
	double		imp_y;
}				t_bubble;

typedef struct	s_game_context
{
	bool		active;
	bool		game_over;

	SDL_Renderer	*renderer;

	int			ticks;

	int			circle_cap;
	int			circle_at;
	t_bubble	*circles;

}				t_game_context;

#endif
