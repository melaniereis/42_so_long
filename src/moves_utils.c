/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:58:28 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 13:23:57 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	handle_exit_collision(t_game *game, int new_y, int new_x);

void	move_conditions(t_game *game)
{
	if (game->map[game->player_position.y][game->player_position.x] == 'C')
	{
		game->map[game->player_position.y][game->player_position.x] = '0';
		game->coin_bag += 1;
		if (game->coin_bag == game->collectibles)
			update_exit_texture(game);
	}
	if (game->map[game->player_position.y][game->player_position.x] == 'E')
	{
		if (game->coin_bag == game->collectibles)
		{
			ft_printf("\nSANTA COLLECTED ALL THE GIFT! YOU WON!\n\n");
			ft_quit_game(game);
		}
	}
	game->moves += 1;
	ft_printf("Number of moves: %d\n", game->moves);
}

void	move_player(t_game *game, int dy, int dx)
{
	int		new_y;
	int		new_x;
	char	next_pos;

	new_y = game->player_position.y + dy;
	new_x = game->player_position.x + dx;
	next_pos = game->map[new_y][new_x];
	if (next_pos == 'E')
	{
		handle_exit_collision(game, new_y, new_x);
		return ;
	}
	set_player_texture(game, new_y * BITS, new_x * BITS);
	set_texture(game, BACKGROUND, game->player_position.y * BITS,
		game->player_position.x * BITS);
	game->player_position.y = new_y;
	game->player_position.x = new_x;
	move_conditions(game);
}

static void	handle_exit_collision(t_game *game, int new_y, int new_x)
{
	if (game->coin_bag == game->collectibles)
	{
		set_texture(game, EXIT_SANTA, new_y * BITS, new_x * BITS);
		game->player_position.y = new_y;
		game->player_position.x = new_x;
		move_conditions(game);
	}
}
