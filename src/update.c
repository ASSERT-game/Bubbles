/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:52:34 by home              #+#    #+#             */
/*   Updated: 2020/07/25 20:45:53 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void		boundary_check(t_bubble *bubble)
{
	int 	rad;

	rad = bubble->r;
	if (bubble->x - rad < 0 || bubble->x + rad > WIN_WIDTH)
		bubble->vel_x *= -1;

	if (bubble->y - rad < 0 || bubble->y + rad > WIN_HEIGHT)
		bubble->vel_y *= -1;
}

void		update_circles(t_game_context *game_state)
{
	int			i;
	t_bubble	*bubble;

	i = 0;
	while (i < game_state->circle_at)
	{
		bubble = &(game_state->circles[i]);

		bubble->x += bubble->vel_x;
		bubble->y += bubble->vel_y;

		boundary_check(bubble);
		i++;
	}
}

void		update_game_state(t_game_context *game_state)
{
	update_circles(game_state);

	game_state->ticks++;
}
