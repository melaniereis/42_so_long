/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:00:48 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 12:13:25 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	move_up(t_game *game)
{
	move_player(game, 0, -1, 0);
}

void	move_down(t_game *game)
{
	move_player(game, 1, 1, 0);
}

void	move_right(t_game *game)
{
	move_player(game, 2, 0, 1);
}

void	move_left(t_game *game)
{
	move_player(game, 3, 0, -1);
}
