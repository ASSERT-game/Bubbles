/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 03:05:42 by home              #+#    #+#             */
/*   Updated: 2020/07/25 20:39:21 by home             ###   ########.fr       */
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
	int			x;
	int			y;

	int			r;

	int			vel_x;
	int			vel_y;
}				t_bubble;

typedef struct	s_game_context
{
	bool		active;
	bool		game_over;

	int			ticks;

	int			circle_cap;
	int			circle_at;
	t_bubble	*circles;

}				t_game_context;

#endif
