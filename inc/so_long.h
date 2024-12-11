/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:24:46 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/11 11:25:51 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/Libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_game
{
	char	**map;
	char	**map_copy;
	char	*map_name;

	int		moves;
	int		rows;
	int		columns;
	int		collect;
	int		coin_bag;
	int		collect_check;
	int		exit_check;

    t_point	player_position;
	t_point	coordinates;

    void	*mlx_ptr;
	void	*win_ptr;

	t_img	img;

	t_point	img_size;
}			t_game;


#endif