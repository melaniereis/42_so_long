/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:47:47 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 13:28:23 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	display_wall_background_exit(t_game *game, int y, int x, char position)
{
	if (position == '1')
		set_texture(game, WALL, y * BITS, x * BITS);
	else if (position == '0')
		set_texture(game, BACKGROUND, y * BITS, x * BITS);
	else if (position == 'E')
		set_texture(game, EXIT, y * BITS, x * BITS);
}

void	display_gift(t_game *game, int y, int x)
{
	set_texture(game, GIFT_1, y * BITS, x * BITS);
}

void	display_player(t_game *game, int y, int x)
{
	set_texture(game, PLAYER_FRONT_1, y * BITS, x * BITS);
}

void	display_textures(t_game *game, int y, int x)
{
	char	position;

	position = game->map[y][x];
	display_wall_background_exit(game, y, x, position);
	if (position == 'C')
		display_gift(game, y, x);
	if (position == 'P')
		display_player(game, y, x);
}

void	set_texture(t_game *game, char *texture_dir, int y, int x)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	game->img.mlx_img = mlx_xpm_file_to_image (game->mlx_ptr, texture_dir,
			&game->img_size.x, &game->img_size.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.mlx_img, x, y);
}
