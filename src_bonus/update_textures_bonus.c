/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_textures_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:16:34 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 12:13:57 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	set_grinch_texture(t_game *game, int y, int x);
static void	check_and_update_grinch(t_game *game, int y, int x);

void	update_exit_texture(t_game *game)
{
	game->coordinates.y = 0;
	while (game->coordinates.y < game->rows)
	{
		game->coordinates.x = 0;
		while (game->coordinates.x < game->columns)
		{
			if (game->map[game->coordinates.y][game->coordinates.x] == 'E')
				set_texture(game, EXIT_SANTA, game->coordinates.y * BITS,
					game->coordinates.x * BITS);
			game->coordinates.x += 1;
		}
		game->coordinates.y += 1;
	}
}

void	update_grinch_texture(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			check_and_update_grinch(game, y, x);
			x++;
		}
		y++;
	}
}

static void	set_grinch_texture(t_game *game, int y, int x)
{
	if (game->grinch_counter == 1)
		set_texture(game, GRINCH_1, y * BITS, x * BITS);
	else if (game->grinch_counter == 2)
		set_texture(game, GRINCH_2, y * BITS, x * BITS);
	else if (game->grinch_counter == 3)
		set_texture(game, GRINCH_3, y * BITS, x * BITS);
	else if (game->grinch_counter == 4)
		set_texture(game, GRINCH_4, y * BITS, x * BITS);
	else if (game->grinch_counter == 5)
		set_texture(game, GRINCH_5, y * BITS, x * BITS);
	game->grinch_counter = (game->grinch_counter % 5) + 1;
}

static void	check_and_update_grinch(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'K')
		set_grinch_texture(game, y, x);
}
