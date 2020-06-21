/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/06/20 22:43:49 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_context_initialize(t_game_state *game_state, t_display *display)
{
	game_state->active = true;
	game_state->playing = true;
	game_state->texture = IMG_LoadTexture(display->renderer, "resources/tictactoe_texture.png");
	bzero(game_state->map, sizeof(game_state->map));

	game_state->src_rect = carve_tictactoe_texture();

	game_state->AI_switch = false;
	game_state->AI_turn = NONE;

	reset_selection(game_state);

	game_state->turn = 0;
}

int	main(int aa, char **args)
{
	t_display		display;
	t_game_state	game_state;

	SDLU_start(&display);
	game_context_initialize(&game_state, &display);
	if (aa == 2 && strcmp(args[1], "AI") == 0)
		AI_initialize(&game_state);

	printf("AI: %d\n", game_state.AI_turn);

	while (game_state.active == true)
	{
		process_user_input(&game_state);

		update_game(&game_state);

		draw_game_state(&game_state, &display);
		draw_grid(&game_state, &display);
		draw_hover_tile(&game_state, &display);

		// if (game_state.playing = false)
		// 	draw_win_state();

		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);
	}
	SDLU_close(&display);
	printf("Thank you for playing.\n");
	return (0);
}
