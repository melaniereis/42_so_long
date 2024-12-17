/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:32:43 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/17 12:19:05 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void    init_game(t_game *game);
static void    init_window(t_game *game);

t_game  *init(void)
{
    t_game  *game;

    game = malloc(sizeof(t_game));
    if (!game)
        return (NULL);
    init_game(game);
    init_window(game);
    return (game);
}

static void    init_game(t_game *game)
{
    game->map = NULL;
	game->map_copy = NULL;
	game->map_name = NULL;
	game->moves = 0;
	game->rows = 0;
	game->columns = 0;
	game->collectibles = 0;
	game->coin_bag = 0;
	game->collect_check = 0;
	game->exit_check = 0;
    game->player_position.x = 0;
    game->player_position.y = 0;
	game->coordinates.x = 0;
    game->coordinates.y = 0;
	game->santa_counter = 1;
    game->gift_counter = 1;
}

static void    init_window(t_game *game)
{
    game->mlx_ptr = mlx_init();
	game->win_ptr = NULL;
	game->img.mlx_img = NULL;
    game->img.addr = 0;
    game->img.bpp = 0;
    game->img.line_len = 0;
    game->img.endian = 0;
	game->img_size.x = 0;
    game->img_size.y = 0;
}
