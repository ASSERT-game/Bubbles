/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 02:38:19 by home              #+#    #+#             */
/*   Updated: 2020/07/25 20:30:46 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	mirror_valid_cir_pixel(t_bubble *circle, t_display *display, int x_at, int y_at)
{
	SDL_RenderDrawPoint(display->renderer, circle->x + x_at, circle->y + y_at);

	SDL_RenderDrawPoint(display->renderer, circle->x + x_at, circle->y - y_at);

	SDL_RenderDrawPoint(display->renderer, circle->x - x_at, circle->y + y_at);
	SDL_RenderDrawPoint(display->renderer, circle->x - x_at, circle->y - y_at);
}

void	draw_circle(t_bubble *circle, t_display *display)
{
	int	x_at;
	int	y_at;

	x_at = 0;
	y_at = -(circle->r);
	SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	while (x_at <= circle->r)
	{
		if (square_distance(x_at, y_at, 0, 0) > circle->r * circle->r)
			y_at++;
		else
			x_at++;

		mirror_valid_cir_pixel(circle, display, x_at, y_at);
	}

	SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

void	draw_circles(t_game_context *game_state, t_display *display)
{
	int	i;

	i = 0;
	while (i < game_state->circle_at)
	{
		draw_circle(&(game_state->circles[i]), display);
		i++;
	}
}
