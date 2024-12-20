/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_textures_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:47:47 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 12:12:22 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
	if (game->gift_counter == 1)
		set_texture(game, GIFT_1, y * BITS, x * BITS);
	else if (game->gift_counter == 2)
		set_texture(game, GIFT_2, y * BITS, x * BITS);
	else if (game->gift_counter == 3)
		set_texture(game, GIFT_3, y * BITS, x * BITS);
	else if (game->gift_counter == 4)
		set_texture(game, GIFT_4, y * BITS, x * BITS);
	else if (game->gift_counter == 5)
		set_texture(game, GIFT_5, y * BITS, x * BITS);
	else if (game->gift_counter == 6)
		set_texture(game, GIFT_6, y * BITS, x * BITS);
	else if (game->gift_counter == 7)
		set_texture(game, GIFT_7, y * BITS, x * BITS);
	else if (game->gift_counter == 8)
		set_texture(game, GIFT_8, y * BITS, x * BITS);
	game->gift_counter = (game->gift_counter % 8) + 1;
}

void	display_grinch_player(t_game *game, int y, int x, char position)
{
	if (position == 'K')
	{
		set_texture(game, GRINCH_1, y * BITS, x * BITS);
		game->grinch_counter = (game->grinch_counter % 5) + 1;
	}
	else if (position == 'P')
		set_texture(game, PLAYER_FRONT_1, y * BITS, x * BITS);
}

void	display_textures(t_game *game, int y, int x)
{
	char	position;

	position = game->map[y][x];
	display_wall_background_exit(game, y, x, position);
	if (position == 'C')
		display_gift(game, y, x);
	else if (position == 'K' || position == 'P')
		display_grinch_player(game, y, x, position);
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
