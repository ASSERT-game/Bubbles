/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:52:34 by home              #+#    #+#             */
/*   Updated: 2020/07/30 19:25:00 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void		boundary_check(t_bubble *bubble)
{
	int 	rad;

	rad = bubble->r;
	if (bubble->x - rad <= 0 && bubble->vel_x < 0)
		bubble->vel_x *= -1;

	if (bubble->x + rad >= WIN_WIDTH  && bubble->vel_x > 0)
		bubble->vel_x *= -1;

	if (bubble->y - rad <= 0 && bubble->vel_y < 0)
		bubble->vel_y *= -1;

	if (bubble->y + rad >= WIN_HEIGHT && bubble->vel_y > 0)
		bubble->vel_y *= -1;
}

bool		bubbles_collide(t_bubble *bubble1, t_bubble *bubble2)
{
	int	x1;
	int	y1;
	int	r1;

	int	x2;
	int	y2;
	int	r2;

	x1 = bubble1->x;
	y1 = bubble1->y;
	r1 = bubble1->r;

	x2 = bubble2->x;
	y2 = bubble2->y;
	r2 = bubble2->r;

	if (square_distance(x1, y1, x2, y2) <= (r1 + r2) * (r1 + r2))
		return (true);
	else
		return (false);
}

void		collide_bubbles(t_game_context *game_state, t_bubble *bubble)
{
	int	i;
	int	d_x;
	int	d_y;
	int	count;

	i = 0;
	count = 0;
	while (i < game_state->circle_at)
	{
		if (&(game_state->circles[i]) != bubble)
		{
			if (bubbles_collide(bubble, &(game_state->circles[i])) == true)
			{
				d_x = bubble->x - game_state->circles[i].x;
				d_y = bubble->y - game_state->circles[i].y;

				normal_velocity(bubble, d_x, d_y, &game_state->circles[i].imp_x, &game_state->circles[i].imp_y);
				tangent_velocity(bubble, d_x, d_y, &bubble->imp_x, &bubble->imp_y);

				// printf("Ow %f, %f\n", game_state->circles[i].imp_x, game_state->circles[i].imp_x);
				// usleep(170000);
				count++;
			}
		}
		i++;
	}

	if (count == 0)
	{
		bubble->imp_x = bubble->vel_x;
		bubble->imp_y = bubble->vel_y;
	}

	if (count >= 2)
		printf(RED"BIG OOF\n"COLOR_RESET);
}

void		use_impluse(t_bubble *bubble)
{
	bubble->vel_x = bubble->imp_x;
	bubble->vel_y = bubble->imp_y;

	bubble->imp_x = 0;
	bubble->imp_y = 0;
}

void		update_circles(t_game_context *game_state)
{
	int			i;
	t_bubble	*bubble;

	i = 0;
	while (i < game_state->circle_at)
	{
		bubble = &(game_state->circles[i]);
		collide_bubbles(game_state, bubble);
		i++;
	}

	i = 0;
	while (i < game_state->circle_at)
	{
		bubble = &(game_state->circles[i]);
		use_impluse(bubble);
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
