/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:24:46 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/17 12:17:58 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define BITS 48
# define WALL "./textures/WALL.xpm"
# define BACKGROUND "./textures/BACKGROUND.xpm"
# define EXIT "./textures/EXIT.xpm"
# define EXIT_SANTA "./textures/EXIT_SANTA.xpm"
# define GIFT_1 "./textures/GIFT_1.xpm"
# define GIFT_2 "./textures/GIFT_2.xpm"
# define GIFT_3 "./textures/GIFT_3.xpm"
# define GIFT_4 "./textures/GIFT_4.xpm"
# define GIFT_5 "./textures/GIFT_5.xpm"
# define GIFT_6 "./textures/GIFT_6.xpm"
# define GIFT_7 "./textures/GIFT_7.xpm"
# define GIFT_8 "./textures/GIFT_8.xpm"
# define PLAYER_FRONT_1 "./textures/SANTA_FRONT_1.xpm"
# define PLAYER_FRONT_2 "./textures/SANTA_FRONT_2.xpm"
# define PLAYER_FRONT_3 "./textures/SANTA_FRONT_3.xpm"
# define PLAYER_FRONT_4 "./textures/SANTA_FRONT_4.xpm"
# define PLAYER_BACK_1 "./textures/SANTA_BACK_1.xpm"
# define PLAYER_BACK_2 "./textures/SANTA_BACK_2.xpm"
# define PLAYER_BACK_3 "./textures/SANTA_BACK_3.xpm"
# define PLAYER_BACK_4 "./textures/SANTA_BACK_4.xpm"
# define PLAYER_LEFT_1 "./textures/SANTA_LEFT_1.xpm"
# define PLAYER_LEFT_2 "./textures/SANTA_LEFT_2.xpm"
# define PLAYER_LEFT_3 "./textures/SANTA_LEFT_3.xpm"
# define PLAYER_LEFT_4 "./textures/SANTA_LEFT_4.xpm"
# define PLAYER_RIGHT_1 "./textures/SANTA_RIGHT_1.xpm"
# define PLAYER_RIGHT_2 "./textures/SANTA_RIGHT_2.xpm"
# define PLAYER_RIGHT_3 "./textures/SANTA_RIGHT_3.xpm"
# define PLAYER_RIGHT_4 "./textures/SANTA_RIGHT_4.xpm"

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
	int		collectibles;
	int		coin_bag;
	int		collect_check;
	int		exit_check;
	int		santa_counter;
	int		gift_counter;

    t_point	player_position;
	t_point	coordinates;

    void	*mlx_ptr;
	void	*win_ptr;

	t_img	img;

	t_point	img_size;
}			t_game;

t_game  *init(void);
int    count_rows(t_game *game);
void  fill_map(int fd, t_game *game);
void  set_map_copy(int fd, t_game *game);
int    count_columns_per_row(t_game *game, int row);
void    set_map_values(t_game *game);
int is_map_name_ok(char *map_name);
int is_map_valid(t_game *game);
int is_there_exit_n_player(t_game *game);
int is_there_collectible(t_game *game);
int is_map_rectangular(t_game *game);
int are_there_walls(t_game *game);
int are_char_in_map_valid(t_game *game);
int is_there_path(t_game *game);
void	start_game(t_game *game);
int	ft_quit_game(t_game *game);
void	set_texture(t_game *game, char *texture_dir, int y, int x);
void	update_exit_texture(t_game *game);
int	key_handler(int key, t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);

#endif
