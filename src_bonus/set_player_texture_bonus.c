/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_texture_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:52:35 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 12:13:45 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	set_player_up_texture(t_game *game, int y, int x);
static void	set_player_down_texture(t_game *game, int y, int x);
static void	set_player_right_texture(t_game *game, int y, int x);
static void	set_player_left_texture(t_game *game, int y, int x);

void	set_player_texture(t_game *game, int direction, int y, int x)
{
	if (direction == 0)
		set_player_up_texture(game, y, x);
	else if (direction == 1)
		set_player_down_texture(game, y, x);
	else if (direction == 2)
		set_player_right_texture(game, y, x);
	else
		set_player_left_texture(game, y, x);
	game->santa_counter = (game->santa_counter % 4) + 1;
}

static void	set_player_up_texture(t_game *game, int y, int x)
{
	if (game->santa_counter == 1)
		set_texture(game, PLAYER_BACK_1, y, x);
	else if (game->santa_counter == 2)
		set_texture(game, PLAYER_BACK_2, y, x);
	else if (game->santa_counter == 3)
		set_texture(game, PLAYER_BACK_3, y, x);
	else
		set_texture(game, PLAYER_BACK_4, y, x);
}

static void	set_player_down_texture(t_game *game, int y, int x)
{
	if (game->santa_counter == 1)
		set_texture(game, PLAYER_FRONT_2, y, x);
	else if (game->santa_counter == 2)
		set_texture(game, PLAYER_FRONT_3, y, x);
	else if (game->santa_counter == 3)
		set_texture(game, PLAYER_FRONT_4, y, x);
	else
		set_texture(game, PLAYER_FRONT_1, y, x);
}

static void	set_player_right_texture(t_game *game, int y, int x)
{
	if (game->santa_counter == 1)
		set_texture(game, PLAYER_RIGHT_1, y, x);
	else if (game->santa_counter == 2)
		set_texture(game, PLAYER_RIGHT_2, y, x);
	else if (game->santa_counter == 3)
		set_texture(game, PLAYER_RIGHT_3, y, x);
	else
		set_texture(game, PLAYER_RIGHT_4, y, x);
}

static void	set_player_left_texture(t_game *game, int y, int x)
{
	if (game->santa_counter == 1)
		set_texture(game, PLAYER_LEFT_1, y, x);
	else if (game->santa_counter == 2)
		set_texture(game, PLAYER_LEFT_2, y, x);
	else if (game->santa_counter == 3)
		set_texture(game, PLAYER_LEFT_3, y, x);
	else
		set_texture(game, PLAYER_LEFT_4, y, x);
}
