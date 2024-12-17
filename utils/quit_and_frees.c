/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_and_frees.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:05:26 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/17 09:24:59 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/so_long.h"

static void	free_map(char **map, t_game *game);
static void	free_all(t_game *game);

int	ft_quit_game(t_game *game)
{
	free_all(game);
	exit(0);
}


static void	free_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	if (!map[0])
	{
		free (game->map);
		return ;
	}
	while (i < game->rows - 1)
		free(game->map[i++]);
	free(game->map);
}
static void	free_map_copy(char **map, t_game *game)
{
	int	i;

	i = 0;
	if (!map[0])
	{
		free (game->map_copy);
		return ;
	}
	while (i < game->rows - 1)
		free(game->map_copy[i++]);
	free(game->map_copy);
}

static void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map, game);
	if (game->map_copy)
		free_map_copy(game->map_copy, game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->img.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free (game);
}
