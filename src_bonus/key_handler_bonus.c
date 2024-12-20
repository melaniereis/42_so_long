/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:21:13 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 12:12:34 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	key_handler(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		ft_printf("'ESC' pressed, leaving the game! See you next time!\n");
		ft_quit_game(game);
	}
	if ((key == XK_Up || key == 'w') && (game->map[game->player_position.y - 1]
			[game->player_position.x] != '1'))
		move_up(game);
	if ((key == XK_Down || key == 's')
		&& (game->map[game->player_position.y + 1]
			[game->player_position.x] != '1'))
		move_down(game);
	if ((key == XK_Right || key == 'd') && (game->map[game->player_position.y]
			[game->player_position.x + 1] != '1'))
		move_right(game);
	if ((key == XK_Left || key == 'a') && (game->map[game->player_position.y]
			[game->player_position.x - 1] != '1'))
		move_left(game);
	return (0);
}
