/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:46:23 by home              #+#    #+#             */
/*   Updated: 2020/06/20 22:54:34 by home             ###   ########.fr       */
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

int	make_choice_list(int *dest, char *board)
{
	int	i;
	int	at;

	i = 0;
	at = 0;
	while (i < 9)
	{
		if (board[i] == NONE)
		{
			dest[at] = i;
			at++;
		}
		i++;
	}
	return (at);
}

void	do_action(int choice, char *board, int turn, char player_type)
{
	char	player;
	char	opponent;

	if (player_type == X_TURN)
	{
		player = X_TEX;
		opponent = O_TEX;
	}
	else
	{
		player = O_TEX;
		opponent = X_TEX;
	}

	if (turn % 2 == 0)
		board[choice] = player;
	else
		board[choice] = opponent;
}

void	undo_action(int choice, char *board, int turn, char player)
{
	board[choice] = NONE;
	(void)turn;
	(void)player;
}

void	print_board(char *board)
{
	printf("%.3s\n", &board[0]);
	printf("%.3s\n", &board[3]);
	printf("%.3s\n", &board[6]);
}

int	min_max(t_game_state *board, int depth, int *choice_dest)
{
	int	i;
	int	choice;
	int	result;
	int	current_desirability;
	int	total_choices;
	int	choice_list[9];

	i = 0;
	choice = -1;
	if (depth % 2 == 0)
		result = -3000;
	else
		result = 3000;
	total_choices = make_choice_list(choice_list, board->map);

	if (depth >= 10 || total_choices == 0)
	{
		if (win_state(board->map) == true)
		{
			if (depth % 2 == 1)
				return (1);
			else
				return (-1);
		}
		else
			return (0);
	}

	while (i < total_choices)
	{
		do_action(choice_list[i], board->map, depth, board->AI_turn);
		if (win_state(board->map) == true)
		{
			if (depth % 2 == 0)
				current_desirability = 1;
			else
				current_desirability = -1;
		}
		else
			current_desirability = min_max(board, depth + 1, choice_dest);

		if (depth % 2 == 0)
		{
			if (current_desirability > result)
			{
				result = current_desirability;
				choice = choice_list[i];
			}
		}
		else
		{
			if (current_desirability < result)
				result = current_desirability;
		}

		undo_action(choice_list[i], board->map, depth, board->AI_turn);
		i++;
	}

	if (depth == 0 && choice != -1)
		*choice_dest = choice;
	return (result);
}

void	AI_select_turn(t_game_state *game_state)
{
	int	x;
	int	y;

	int	i;
	i = 0;

	min_max(game_state, 0, &i);
	// while (i < 9 && game_state->map[i] != NONE)
	// 	i++;

	x = (i % 3) * 64;
	y = (i / 3) * 64;

	game_state->select_x = x;
	game_state->select_y = y;

	printf("TURN: %d at (%d, %d)\n", i, x, y);
}
