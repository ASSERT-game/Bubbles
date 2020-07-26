/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:38:32 by home              #+#    #+#             */
/*   Updated: 2020/07/25 20:21:26 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include <stdio.h>

# include <SDL_image.h>

# include "structs.h"
# include "window_config.h"

void		SDLU_start(t_display *dest);
void		SDLU_close(t_display *display);

void		process_user_input(t_game_context *game_state);
void		update_game_state(t_game_context *game_state);

void		draw_circles(t_game_context *game_state, t_display *display);

int			square_distance(int x, int y, int to_x, int to_y);

#endif
