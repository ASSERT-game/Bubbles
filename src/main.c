/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/07/25 20:25:58 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_context_initialize(t_game_context *game_state)
{
	game_state->active = true;
	game_state->game_over = false;

	game_state->ticks = 0;

	game_state->circle_cap = 10;
	game_state->circle_at = 0;
	game_state->circles = calloc(game_state->circle_cap, sizeof(*(game_state->circles)));

	srand(time(NULL));
}

int	main(void)
{
	t_display		display;
	t_game_context	game_state;

	SDLU_start(&display);
	game_context_initialize(&game_state);

	game_state.circle_at = 1;
	game_state.circles[0].y = 300;
	game_state.circles[0].x = 200;
	game_state.circles[0].r = 50;

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
