/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_conditions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:34:10 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 13:11:36 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_there_exit_n_player(t_game *game)
{
	int	x;
	int	y;
	int	e;
	int	p;

	y = 0;
	e = 0;
	p = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'E')
				e++;
			if (game->map[y][x] == 'P')
				p++;
			x++;
		}
		y++;
	}
	if (e != 1 || p != 1)
		return (0);
	return (1);
}

int	is_there_collectible(t_game *game)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	c = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (c < 1)
		return (0);
	game->collectibles = c;
	return (1);
}

int	is_map_rectangular(t_game *game)
{
	int	column_size_per_row;
	int	y;

	y = 1;
	while (y <= game->rows)
	{
		column_size_per_row = count_columns_per_row(game, y);
		if (game->columns != column_size_per_row)
			return (0);
		if (column_size_per_row == 1)
		{
			ft_printf ("Error\nMap has empty lines!\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	are_there_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->columns - 1)
	{
		if (game->map[0][x] != '1' || game->map[game->rows - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < game->rows)
	{
		if (game->map[y][0] != '1' || game->map[y][game->columns - 2] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	are_char_in_map_valid(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] != 'E' && game->map[y][x] != 'P'
				&& game->map[y][x] != 'C' && game->map[y][x] != '1'
				&& game->map[y][x] != '0' && game->map[y][x] != '\0'
				&& game->map[y][x] != '\n')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
