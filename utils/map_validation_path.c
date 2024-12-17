/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:38:34 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/17 17:15:53 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
void	set_player_position(t_game *game);
void	flood_fill(t_game *game, int x, int y);

int	is_there_path(t_game *game)
{
	set_player_position(game);
	flood_fill(game, game->player_position.x, game->player_position.y);
	if (game->exit_check != 1 || game->collect_check != game->collectibles)
		return (0);
	return (1);
}

void	set_player_position(t_game *game)
{
	int x;
    int y;

    y = 0;
    while (y < game->rows)
    {
        x = 0;
        while (x < game->columns)
        {
            if (game->map[y][x] == 'P')
            {
                game->player_position.x = x;
                game->player_position.y = y;
                break;
            }
            x++;
        }
        y++;
    }
}

void	flood_fill(t_game *game, int x, int y)
{
	char **map_copy;

	if (x < 0 || x >= game->columns || y < 0 || y >= game->rows)
			return ;
	map_copy = game->map_copy;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return ;
	if (map_copy[y][x] == 'E')
	{
		if (game->collect_check == game->collectibles)
			game->exit_check++;
    }
	if (map_copy[y][x] == 'C')
		game->collect_check++;
	if (map_copy[y][x] != '1')
		map_copy[y][x] = 'F';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}
