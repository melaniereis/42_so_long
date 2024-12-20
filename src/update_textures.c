/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:16:34 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 13:15:18 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
