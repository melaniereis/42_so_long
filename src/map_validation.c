/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:24:46 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/20 11:34:45 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_map_name_ok(char *map_name)
{
	size_t	len;
	char	*dot_position;
	char	*file_name;

	len = ft_strlen(map_name);
	file_name = ft_strrchr(map_name, '/');
	if (!file_name)
		file_name = map_name;
	else
		file_name++;
	len = ft_strlen(file_name);
	if (ft_strncmp(file_name, ".ber", 4) == 0)
		return (ft_printf("Error\nInvalid map filename!"),
			ft_printf(" Put name before '.ber'\n"), 0);
	if (ft_strncmp(file_name + len - 4, ".ber", 4) != 0)
		return (ft_printf("Error\nMap extension is wrong!"),
			ft_printf(" Needs to end with '.ber'\n"), 0);
	dot_position = ft_strchr(file_name, '.');
	if (dot_position && dot_position != file_name + len - 4)
		return (ft_printf("Error\nInvalid map filename!"),
			ft_printf(" Only use one '.ber' at the end\n"), 0);
	return (1);
}

int	is_map_valid(t_game *game)
{
	if (!is_map_rectangular(game))
		return (ft_printf ("Error\nMap is not rectangular!\n"),
			0);
	else if (!is_there_exit_n_player(game))
		return (ft_printf ("Error\nThere is a problem with Exit or Player!\n"),
			0);
	else if (!is_there_collectible(game))
		return (ft_printf ("Error\nThere is no Collectibles!\n"),
			0);
	else if (!are_there_walls(game))
		return (ft_printf ("Error\nMap's walls are incorret!\n"),
			0);
	else if (!are_char_in_map_valid(game))
		return (ft_printf ("Error\nInvalid character in map detected!\n"),
			0);
	else if (!is_there_path(game))
		return (ft_printf ("Error\nPlayer can't get all collectibles"),
			ft_printf(" and go to exit!\n"), 0);
	return (1);
}
