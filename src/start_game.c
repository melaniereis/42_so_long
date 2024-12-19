/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:08:58 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/19 10:26:01 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	display_map(t_game *game);
void	display_textures(t_game *game, int y, int x);
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

void	display_textures(t_game *game, int y, int x)
{
	char	position = game->map[y][x];

	if (position == '1')
		set_texture(game, WALL, y * BITS, x * BITS);
	else if (position == '0')
		set_texture(game, BACKGROUND, y * BITS, x * BITS);
	else if (position == 'C')
	{
		if (game->gift_counter == 1)
		{
			set_texture(game, GIFT_1, y * BITS, x * BITS);
			game->gift_counter = ((game->gift_counter) % 8) + 1;
		}
		else if (game->gift_counter == 2)
		{
			set_texture(game, GIFT_2, y * BITS, x * BITS);
			game->gift_counter = ((game->gift_counter) % 8) + 1;
		}
		else if (game->gift_counter == 3)
		{
			set_texture(game, GIFT_3, y * BITS, x * BITS);
			game->gift_counter = ((game->gift_counter) % 8) + 1;
		}
		else if (game->gift_counter == 4)
		{
			set_texture(game, GIFT_4, y * BITS, x * BITS);
			game->gift_counter = ((game->gift_counter) % 8) + 1;
		}
		else if (game->gift_counter == 5)
		{
			set_texture(game, GIFT_5, y * BITS, x * BITS);
			game->gift_counter = ((game->gift_counter) % 8) + 1;
		}
		else if (game->gift_counter == 6)
		{
			set_texture(game, GIFT_6, y * BITS, x * BITS);
			game->gift_counter = ((game->gift_counter) % 8) + 1;
		}
		else if (game->gift_counter == 7)
		{
			set_texture(game, GIFT_7, y * BITS, x * BITS);
			game->gift_counter = ((game->gift_counter) % 8) + 1;
		}
		else if (game->gift_counter == 8)
		{
			set_texture(game, GIFT_8, y * BITS, x * BITS);
			game->gift_counter = ((game->gift_counter) % 8) + 1;
		}

	}
	else if (position == 'E')
		set_texture(game, EXIT, y * BITS, x * BITS);
	else if (position == 'K')
	{
		set_texture(game, GRINCH_1, y * BITS, x * BITS);
		game->grinch_counter = ((game->grinch_counter) % 5) + 1;
	}
	else if (position == 'P')
		set_texture(game, PLAYER_FRONT_1, y * BITS, x * BITS);
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

void	update_exit_texture(t_game *game)
{
	game->coordinates.y = 0;
	while (game->coordinates.y < game->rows)
	{
		game->coordinates.x = 0;
		while (game->coordinates.x < game->columns)
		{
			if (game->map[game->coordinates.y][game->coordinates.x] == 'E')
				set_texture(game, EXIT_SANTA, game->coordinates.y * BITS, game->coordinates.x * BITS);
			game->coordinates.x += 1;
		}
		game->coordinates.y += 1;
	}
}
void	update_grinch_texture(t_game *game)
{
	game->coordinates.y = 0;
	while (game->coordinates.y < game->rows)
	{
		game->coordinates.x = 0;
		while (game->coordinates.x < game->columns)
		{
			if (game->map[game->coordinates.y][game->coordinates.x] == 'K')
			{
				if (game->grinch_counter == 1)
				{
					set_texture(game, GRINCH_1, game->coordinates.y * BITS, game->coordinates.x * BITS);
					game->grinch_counter = ((game->grinch_counter) % 5) + 1;
				}
				else if (game->grinch_counter == 2)
				{
					set_texture(game, GRINCH_2, game->coordinates.y * BITS, game->coordinates.x * BITS);
					game->grinch_counter = ((game->grinch_counter) % 5) + 1;
				}
				else if (game->grinch_counter == 3)
				{
					set_texture(game, GRINCH_3, game->coordinates.y * BITS, game->coordinates.x * BITS);
					game->grinch_counter = ((game->grinch_counter) % 5) + 1;
				}
				else if (game->grinch_counter == 4)
				{
					set_texture(game, GRINCH_4, game->coordinates.y * BITS, game->coordinates.x * BITS);
					game->grinch_counter = ((game->grinch_counter) % 5) + 1;
				}
				else if (game->grinch_counter == 5)
				{
					set_texture(game, GRINCH_5, game->coordinates.y * BITS, game->coordinates.x * BITS);
					game->grinch_counter = ((game->grinch_counter) % 5) + 1;
				}
			}
			game->coordinates.x += 1;
		}
		game->coordinates.y += 1;
	}
}