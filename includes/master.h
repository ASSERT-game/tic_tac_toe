/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 03:57:35 by home              #+#    #+#             */
/*   Updated: 2020/06/19 04:01:38 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

#include <stdio.h>
#include <SDL_image.h>

#include "structs.h"
#include "window_config.h"
#include "texture_id.h"

void		SDLU_start(t_display *dest);
void		SDLU_close(t_display *display);

SDL_Rect	*carve_tictactoe_texture();

void		draw_hover_tile(t_game_state *game_state, t_display *display);
void		draw_grid(t_game_state *game_state, t_display *display);
void		draw_game_state(t_game_state *game_state, t_display *display);

void		process_user_input(t_game_state *game_state);
void		update_game(t_game_state *game_state);

bool		win_state(t_game_state *game_state);

void		reset_selection(t_game_state *game_state);

int			screen_to_board(int x, int y);
void		get_loc(int i, int *x, int *y);

#endif
