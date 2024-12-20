/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:08:58 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 13:52:21 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	display_map(t_game *game);
void	display_textures(t_game *game, int y, int x);

void	start_game(t_game *game)
{
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(game->columns - 1) * BITS, game->rows * BITS, "so_long");
	if (game->win_ptr == NULL)
		return ;
	display_map (game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &key_handler, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask,
		&ft_quit_game, game);
	mlx_loop(game->mlx_ptr);
}

void	display_map(t_game *game)
{
	game->coordinates.y = 0;
	while (game->coordinates.y < game->rows)
	{
		game->coordinates.x = 0;
		while (game->coordinates.x < game->columns)
		{
			display_textures(game, game->coordinates.y, game->coordinates.x);
			game->coordinates.x += 1;
		}
		game->coordinates.y += 1;
	}
}
