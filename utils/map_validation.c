/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:24:46 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/19 11:24:26 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int is_map_name_ok(char *map_name)
{
    size_t len = ft_strlen(map_name);
    char *dot_position;
    char *file_name;
    
    // Extract the actual file name (after the last '/')
    file_name = ft_strrchr(map_name, '/');
    if (!file_name)
        file_name = map_name;
    else
        file_name++;  // Skip the '/' to get the actual file name
    
    len = ft_strlen(file_name);

    // Check if the filename is too short or starts with ".ber"
    if (ft_strncmp(file_name, ".ber", 4) == 0)
    {
        ft_printf("Error\nInvalid map filename! It should have a name before '.ber'\n");
        return (0);
    }

    // Check if the filename ends with ".ber"
    if (ft_strncmp(file_name + len - 4, ".ber", 4) != 0)
    {
        ft_printf("Error\nMap extension is wrong! It should end with '.ber'\n");
        return (0);
    }

    // Check for the first dot in the filename (excluding the final ".ber" part)
    dot_position = ft_strchr(file_name, '.');
    if (dot_position && dot_position != file_name + len - 4)
    {
        ft_printf("Error\nInvalid map filename! It should only have one '.ber' at the end\n");
        return (0);
    }

    return (1);
}

int is_map_valid(t_game *game)
{
    if (!is_there_exit_n_player(game))
    {
        ft_printf ("Error\nThere is a problem with Exit or Player!\n");
		return (0);
    }
    else if (!is_there_collectible(game))
    {
        ft_printf ("Error\nThere is no Collectibles!\n");
		return (0);
    }
    else if (!is_map_rectangular(game))
    {
        ft_printf ("Error\nMap is not rectangular!\n");
		return (0);
    }
    else if (!are_there_walls(game))
    {
        ft_printf ("Error\nMap's walls are incorret!\n");
		return (0);
    }
    else if (!are_char_in_map_valid(game))
    {
        ft_printf ("Error\nInvalid character in map detected!\n");
		return (0);
    }
    else if (!is_there_path(game))
    {
        ft_printf ("Error\nPlayer can't get all collectibles and go to exit!\n");
		return (0);
    }
    return (1);
}

int is_there_exit_n_player(t_game *game)
{
    int x;
    int y;
    int e;
    int p;

    y = 0;
    e = 0;
    p = 0;
    while (y < game->rows)
    {
        x = 0;
        while (x < game->columns)
        {
            if (game->map[y][x] == 'E')
                e++;
            if (game->map[y][x] == 'P')
                p++; 
            x++;
        }
        y++;
    }
    if (e != 1 || p != 1)
        return (0);
    return (1);
}

int is_there_collectible(t_game *game)
{
    int x;
    int y;
    int c;

    y = 0;
    c = 0;
    while (y < game->rows)
    {
        x = 0;
        while (x < game->columns)
        {
            if (game->map[y][x] == 'C')
                c++;
            x++;
        }
        y++;
    }
    if (c < 1)
        return (0);
    game->collectibles = c;
    return (1);
}

int is_map_rectangular(t_game *game)
{
    int column_size_per_row;
    int y;

    y = 1;
    while (y <= game->rows)
    {
        column_size_per_row = count_columns_per_row(game, y);
        if (game->columns != column_size_per_row)
            return (0);
        y++;
    }
    return (1);
}

int are_there_walls(t_game *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->columns)
    {
        if (game->map[0][x] != '1' || game->map[game->rows - 1][x] != '1')
            return (0);
        x++;
    }
    y = 0;
    while (y < game->rows)
    {
        if (game->map[y][0] != '1' || game->map[y][game->columns - 1] != '1')
            return (0);
        y++;
    }
    return (1);
}

int are_char_in_map_valid(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->rows)
    {
        x = 0;
        while (x < game->columns)
        {
            if (game->map[y][x] != 'E' && game->map[y][x] != 'P'
               && game->map[y][x] != 'C' && game->map[y][x] != '1'
               && game->map[y][x] != '0' && game->map[y][x] != '\0'
               && game->map[y][x] != '\n' && game->map[y][x] != 'K')
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}
