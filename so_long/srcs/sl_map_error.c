/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:49:06 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/14 19:09:49 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		sl_map_standards(char **map, t_main *structs)
{
	int	index;
	int	player;
	int	exit;

	index = 0;
	player = 0;
	exit = 0;
	while (map[index])
	{
		player += ft_char_search(map[index], 'P');
		exit += ft_char_search(map[index], 'E');
		structs->link->collect_goal += ft_char_search(map[index], 'C');
		index++;
	}
	if (player == 0 || exit == 0 || structs->link->collect_goal == 0 || player > 1)
		return (-1);
	else
		return (1);
}

void	sl_valid_map_limit(t_map *map_data, t_main *structs)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (map_data->line[0][y])
	{
		if (map_data->line[0][y] != '1' || map_data->line[map_data->x][y] != '1')
			sl_map_invalid(structs);
		y++;
	}
	while (map_data->line[x])
	{
		if (map_data->line[x][0] != '1' || map_data->line[x][map_data->y] != '1')
				sl_map_invalid(structs);
		x++;
	}
}

int	sl_map_asset_valid(t_map *map_data)
{
	int	x;
	int y;

	x = 0;
	while (map_data->line[x])
	{
		y = 0;
		while (map_data->line[x][y])
		{
			if (map_data->line[x][y] != '1' && map_data->line[x][y] != '0'
				&& map_data->line[x][y] != '0' && map_data->line[x][y] != 'E'
					&& map_data->line[x][y] != 'P' && map_data->line[x][y] != 'C'
						&& map_data->line[x][y] != 'X')
				return (-1);
			y++;
		}
		x++;
	}
	return (0);
}

void	sl_map_error_main(t_main *structs)
{
	sl_valid_map_limit(structs->map_data, structs);
	if (sl_map_standards(structs->map_data->line, structs) == -1)
		sl_map_invalid(structs);
	if (sl_map_asset_valid(structs->map_data) == -1)
		sl_map_invalid(structs);
}