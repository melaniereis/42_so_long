/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:00:48 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/19 10:20:03 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_conditions(t_game *game)
{
	update_grinch_texture(game);
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
void	move_up(t_game *game)
{
	if (game->map[game->player_position.y - 1][game->player_position.x] == 'E')
	{
		if (game->coin_bag != game->collectibles)
			return ;
		game->player_position.y -= 1;
		move_conditions(game);
		return ;
	}
	if (game->map[game->player_position.y - 1][game->player_position.x] == 'K')
	{
		ft_printf("\nTHE GRINCH STOLE THE GIFTS! CHRISTMAS IS RUINED! YOU LOST!\n\n");
		ft_quit_game(game);
		return ;
	}
	if (game->santa_counter == 1)
	{
		set_texture(game, PLAYER_BACK_1, (game->player_position.y - 1) * BITS, (game->player_position.x) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 2)
	{
		set_texture(game, PLAYER_BACK_2, (game->player_position.y - 1) * BITS, (game->player_position.x) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 3)
	{
		set_texture(game, PLAYER_BACK_3, (game->player_position.y - 1) * BITS, (game->player_position.x) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 4)
	{
		set_texture(game, PLAYER_BACK_4, (game->player_position.y - 1) * BITS, (game->player_position.x) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	set_texture(game, BACKGROUND, (game->player_position.y) * BITS, (game->player_position.x) * BITS);
	game->player_position.y -= 1;
	move_conditions(game);
}

void	move_down(t_game *game)
{
	if (game->map[game->player_position.y + 1][game->player_position.x] == 'E')
	{
		if (game->coin_bag != game->collectibles)
			return ;
		set_texture(game, EXIT_SANTA, (game->player_position.y + 1) * BITS, (game->player_position.x) * BITS);
		game->player_position.y += 1;
		move_conditions(game);
		return ;
	}
	if (game->map[game->player_position.y + 1][game->player_position.x] == 'K')
	{
		ft_printf("\nTHE GRINCH STOLE THE GIFTS! CHRISTMAS IS RUINED! YOU LOST!\n\n");
		ft_quit_game(game);
		return ;
	}
	if (game->santa_counter == 1)
	{
		set_texture(game, PLAYER_FRONT_2, (game->player_position.y + 1) * BITS, (game->player_position.x) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 2)
	{
		set_texture(game, PLAYER_FRONT_3, (game->player_position.y + 1) * BITS, (game->player_position.x) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 3)
	{
		set_texture(game, PLAYER_FRONT_4, (game->player_position.y + 1) * BITS, (game->player_position.x) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 4)
	{
		set_texture(game, PLAYER_FRONT_1, (game->player_position.y + 1) * BITS, (game->player_position.x) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	set_texture(game, BACKGROUND, (game->player_position.y) * BITS, (game->player_position.x) * BITS);
	game->player_position.y += 1;
	move_conditions(game);
}

void	move_right(t_game *game)
{
	if (game->map[game->player_position.y][game->player_position.x + 1] == 'E')
	{
		if (game->coin_bag != game->collectibles)
			return ;
		set_texture(game, EXIT_SANTA, (game->player_position.y) * BITS, (game->player_position.x + 1) * BITS);
		game->player_position.x += 1;
		move_conditions(game);
		return ;
	}
	if (game->map[game->player_position.y][game->player_position.x + 1] == 'K')
	{
		ft_printf("\nTHE GRINCH STOLE THE GIFTS! CHRISTMAS IS RUINED! YOU LOST!\n\n");
		ft_quit_game(game);
		return ;
	}
	if (game->santa_counter == 1)
	{
		set_texture(game, PLAYER_RIGHT_1, (game->player_position.y) * BITS, (game->player_position.x + 1) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 2)
	{
		set_texture(game, PLAYER_RIGHT_2, (game->player_position.y) * BITS, (game->player_position.x + 1) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 3)
	{
		set_texture(game, PLAYER_RIGHT_3, (game->player_position.y) * BITS, (game->player_position.x + 1) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 4)
	{
		set_texture(game, PLAYER_RIGHT_4, (game->player_position.y) * BITS, (game->player_position.x + 1) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	set_texture(game, BACKGROUND, (game->player_position.y) * BITS, (game->player_position.x) * BITS);
	game->player_position.x += 1;
	move_conditions(game);
}

void	move_left(t_game *game)
{
	if (game->map[game->player_position.y][game->player_position.x - 1] == 'E')
	{
		if (game->coin_bag != game->collectibles)
			return ;
		set_texture(game, EXIT_SANTA, (game->player_position.y) * BITS, (game->player_position.x - 1) * BITS);
		game->player_position.x -= 1;
		move_conditions(game);
		return ;
	}
	if (game->map[game->player_position.y][game->player_position.x - 1] == 'K')
	{
		ft_printf("\nTHE GRINCH STOLE THE GIFTS! CHRISTMAS IS RUINED! YOU LOST!\n\n");
		ft_quit_game(game);
		return ;
	}
	if (game->santa_counter == 1)
	{
		set_texture(game, PLAYER_LEFT_1, (game->player_position.y) * BITS, (game->player_position.x - 1) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 2)
	{
		set_texture(game, PLAYER_LEFT_2, (game->player_position.y) * BITS, (game->player_position.x - 1) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 3)
	{
		set_texture(game, PLAYER_LEFT_3, (game->player_position.y) * BITS, (game->player_position.x - 1) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	else if (game->santa_counter == 4)
	{
		set_texture(game, PLAYER_LEFT_4, (game->player_position.y) * BITS, (game->player_position.x - 1) * BITS);
		game->santa_counter = ((game->santa_counter) % 4) + 1;
	}
	set_texture(game, BACKGROUND, (game->player_position.y) * BITS, (game->player_position.x) * BITS);
	game->player_position.x -= 1;
	move_conditions(game);
}