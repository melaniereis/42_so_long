/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:08:58 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/16 14:44:34 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	display_map(t_game *game);
void	display_textures(t_game *game, int y, int x);
char	*get_gift_texture_filename(int gift_counter);
void	set_texture(t_game *game, char *texture_dir, int y, int x);

void	start_game(t_game *game)
{
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
		game->columns * BITS, game->rows * BITS, "so_long");
	if (game->win_ptr == NULL)
		return ;
	display_map (game);
	//mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &key_handler, game);
	//mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask,
		//&ft_quit_game, game);
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

void	display_textures(t_game *game, int y, int x)
{
	static int gift_counter = 1;
	char	position = game->map[y][x];

	if (position == '1')
		set_texture(game, "./textures/WALL.xpm", y * BITS, x * BITS);
	else if (position == '0')
		set_texture(game, "./textures/BACKGROUND.xpm", y * BITS, x * BITS);
	else if (position == 'C')
	{
		if (gift_counter == 1)
		{
			set_texture(game, "./textures/GIFT_1.xpm", y * BITS, x * BITS);
			gift_counter = ((gift_counter) % 8) + 1;
		}
		else if (gift_counter == 2)
		{
			set_texture(game, "./textures/GIFT_2.xpm", y * BITS, x * BITS);
			gift_counter = ((gift_counter) % 8) + 1;
		}
		else if (gift_counter == 3)
		{
			set_texture(game, "./textures/GIFT_3.xpm", y * BITS, x * BITS);
			gift_counter = ((gift_counter) % 8) + 1;
		}
		else if (gift_counter == 4)
		{
			set_texture(game, "./textures/GIFT_4.xpm", y * BITS, x * BITS);
			gift_counter = ((gift_counter) % 8) + 1;
		}
		else if (gift_counter == 5)
		{
			set_texture(game, "./textures/GIFT_5.xpm", y * BITS, x * BITS);
			gift_counter = ((gift_counter) % 8) + 1;
		}
		else if (gift_counter == 6)
		{
			set_texture(game, "./textures/GIFT_6.xpm", y * BITS, x * BITS);
			gift_counter = ((gift_counter) % 8) + 1;
		}
		else if (gift_counter == 7)
		{
			set_texture(game, "./textures/GIFT_7.xpm", y * BITS, x * BITS);
			gift_counter = ((gift_counter) % 8) + 1;
		}
		else if (gift_counter == 8)
		{
			set_texture(game, "./textures/GIFT_8.xpm", y * BITS, x * BITS);
			gift_counter = ((gift_counter) % 8) + 1;
		}

	}
	else if (position == 'E')
		set_texture(game, "./textures/EXIT.xpm", y * BITS, x * BITS);
	else if (position == 'P')
		set_texture(game, "./textures/SANTA_FRONT_1.xpm", y * BITS, x * BITS);
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