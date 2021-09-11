/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_pathing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:15:37 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/10 20:35:16 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_change_enemy_pos(t_main *structs)
{
	int	index;
	int	y;

	index = 0;
	while (structs->map_data->line[index])
	{
		y = 0;
		if (ft_char_search(structs->map_data->line[index], 'X') == 1)
		{
			while(structs->map_data->line[index][y])
			{
				if (structs->map_data->line[index][y] == 'X')
					sl_enemy_pathing(structs->map_data, index, y);
				y++;
			}
		}
		index++;
	}
}

void	sl_enemy_pathing(t_map *map_data, int x, int y)
{
	if ((map_data->line[x][y + 1] == '0' || map_data->line[x][y + 1] == 'P')
		&& map_data->line[x][y + 2] == '0')
	{
		map_data->line[x][y] = '0';
		map_data->line[x][y + 1] = 'X';
		return ;
	}
	if ((map_data->line[x][y - 1] == '0' || map_data->line[x][y - 1] == 'P')
		&& map_data->line[x][y - 2] == '0')
	{
		map_data->line[x][y] = '0';
		map_data->line[x][y - 1] = 'X';
		return ;
	}
	if ((map_data->line[x + 1][y] == '0' || map_data->line[x + 1][y] == 'P')
		&& map_data->line[x + 2][y] == '0')
	{
		map_data->line[x][y] = '0';
		map_data->line[x + 1][y] = 'X';
		return ;
	}
	sl_enemy_pathing(map_data, x, y);
}

void sl_enemy_pathing2(t_map *map_data, int x, int y)
{
	if ((map_data->line[x - 1][y] == '0' || map_data->line[x - 1][y] == 'P')
		&& map_data->line[x - 2][y] == '0')
	{
		map_data->line[x][y] = '0';
		map_data->line[x + 1][y] = 'X';
		return ;
	}
	if (map_data->line[x + 1][y] == '0')
	{
		map_data->line[x][y] = '0';
		map_data->line[x + 1][y] = 'X';
		return ;
	}
	if (map_data->line[x][y + 1] == '0')
	{
		map_data->line[x][y] = '0';
		map_data->line[x][y + 1] = 'X';
		return ;
	}
	sl_enemy_pathing3(map_data, x, y);
}

void	sl_enemy_pathing3(t_map *map_data, int x, int y)
{
	if (map_data->line[x - 1][y] == '0')
	{
		map_data->line[x][y] = '0';
		map_data->line[x - 1][y] = 'X';
		return ;
	}
	if (map_data->line[x][y - 1] == '0')
	{
		map_data->line[x][y] = '0';
		map_data->line[x][y - 1] = 'X';
		return ;
	}
}
