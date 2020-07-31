/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/07/30 19:31:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_context_initialize(t_game_context *game_state)
{
	game_state->active = true;
	game_state->game_over = false;

	game_state->ticks = 0;

	game_state->circle_cap = 20;
	game_state->circle_at = 0;
	game_state->circles = calloc(game_state->circle_cap, sizeof(*(game_state->circles)));

	srand(time(NULL));
}

void	spawn_bubble(t_bubble *dest, int x, int y, int r, int vel_x, int vel_y)
{
	dest->x = x;
	dest->y = y;

	dest->vel_x = vel_x;
	dest->vel_y = vel_y;

	dest->r = r;
}

int	main(void)
{
	t_display		display;
	t_game_context	game_state;

	SDLU_start(&display);
	game_context_initialize(&game_state);

	game_state.renderer = display.renderer;

	game_state.circle_at = 10;

	spawn_bubble(&game_state.circles[0], 500, 700, 30, 7, 1);

	game_state.circles[0].vel_y = 12;

	spawn_bubble(&game_state.circles[1], 500, 500, 30, 0, 0);
	spawn_bubble(&game_state.circles[2], 470, 433, 30, 0, 0);
	spawn_bubble(&game_state.circles[3], 535, 440, 30, 0, 0);

	spawn_bubble(&game_state.circles[4], 620, 631, 30, 3, 2);
	spawn_bubble(&game_state.circles[5], 400, 100, 30, 1, 2);
	spawn_bubble(&game_state.circles[6], 143, 462, 30, 3, 1);

	spawn_bubble(&game_state.circles[7], 820, 100, 30, 3, 2);
	spawn_bubble(&game_state.circles[8], 100, 320, 30, 3, 2);
	spawn_bubble(&game_state.circles[9], 800, 820, 30, 3, 2);

	// spawn_bubble(&game_state.circles[9],  100, 820, 30, 3, 2);
	// spawn_bubble(&game_state.circles[10], 200, 520, 30, 5, 1);
	// spawn_bubble(&game_state.circles[11], 900, 720, 30, 3, 2);

	while (game_state.active == true)
	{
		process_user_input(&game_state);

		update_game_state(&game_state);

		draw_circles(&game_state, &display);

		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);

	}
	SDLU_close(&display);
	return (0);
}
