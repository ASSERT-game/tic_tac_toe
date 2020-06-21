/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:46:23 by home              #+#    #+#             */
/*   Updated: 2020/06/20 18:59:59 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	AI_initialize(t_game_state *game_state)
{
	int	num1;
	int	num2;

	srand(time(NULL));
	game_state->AI_switch = true;

	num1 = rand();
	num2 = rand();
	if (num1 > num2)
		game_state->AI_turn = X_TURN;
	else
		game_state->AI_turn = O_TURN;
}

void	AI_select_turn(t_game_state *game_state)
{
	int	x;
	int	y;

	int	i;
	i = 0;
	while (i < 9 && game_state->map[i] != NONE)
		i++;

	x = (i % 3) * 64;
	y = (i / 3) * 64;

	game_state->select_x = x;
	game_state->select_y = y;

	printf("TURN: %d at (%d, %d)\n", i, x, y);
}
