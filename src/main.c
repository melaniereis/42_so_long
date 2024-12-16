/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:32:43 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/16 14:45:31 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;

	if (argc == 2 && is_map_name_ok(argv[1]))
	{
		game = init();
		fd = open (argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error\n There was a problem while opening the map file!\n");
			//return (ft_quit_game(game));
		}
		game->map_name = argv[1];
		set_map_values(game);
		if (!is_map_valid(game))
			printf("Problem\n");//ft_quit_game(game);
		start_game(game);
	}
}
