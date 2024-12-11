/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:24:46 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/11 11:25:51 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int is_map_name_ok(char *map_name)
{
    if (ft_strncmp(map_name + ft_strlen(map_name) - 4, ".ber", 4) != 0)
    {
        ft_printf("Error\nMap extension is wrong!\n");
		return (0);
    }
    return (1);
}
