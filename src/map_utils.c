/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:08:46 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 11:07:23 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int		count_rows(t_game *game);
void	fill_map(int fd, t_game *game);
int		count_columns_per_row(t_game *game, int row);

void	set_map_values(t_game *game)
{
	int	fd;

	game->rows = count_rows(game);
	if (game->rows == 0)
	{
		ft_printf("Error\nMap is empty!\n");
		ft_quit_game(game);
	}
	fd = open(game->map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nThere is an issue with the map file!\n");
		return ;
	}
	fill_map(fd, game);
	game->columns = count_columns_per_row(game, 1);
	close(fd);
}

int	count_rows(t_game *game)
{
	int		fd;
	int		rows;
	char	*buff;

	fd = open(game->map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nUnable to open the map!\n");
		return (0);
	}
	rows = 0;
	buff = get_next_line(fd);
	while (buff)
	{
		free(buff);
		rows++;
		buff = get_next_line(fd);
	}
	close(fd);
	free(buff);
	return (rows);
}

void	fill_map(int fd, t_game *game)
{
	int		i;
	char	*line;

	game->map = malloc(sizeof(char *) * (game->rows + 1));
	game->map_copy = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map || !game->map_copy)
		return ;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = ft_strdup(line);
		game->map_copy[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = 0;
	game->map_copy[i] = 0;
	free(line);
}

int	count_columns_per_row(t_game *game, int row)
{
	if (!ft_strchr(game->map[row - 1], '\n'))
		return (ft_strlen(game->map[row - 1]) + 1);
	else
		return (ft_strlen(game->map[row - 1]));
}
