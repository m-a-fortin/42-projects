/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:49:06 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/10 17:01:41 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		sl_map_standards(char **map)
{
	int	index;
	int	player;
	int	exit;
	int	collect;

	index = 0;
	player = 0;
	exit = 0;
	collect = 0;
	while (map[index])
	{
		player += ft_char_search(map[index], 'P');
		exit += ft_char_search(map[index], 'E');
		collect += ft_char_search(map[index], 'C');
		index++;
	}
	if (player == 0 || exit == 0 || collect == 0 || player > 1)
		return (-1);
	else
		return (1);
}

void	sl_valid_map_limit(t_map *map_data)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (map_data->line[0][y])
	{
		if (map_data->line[0][y] != '1' || map_data->line[map_data->x][y] != '1')
			sl_map_invalid(map_data);
		y++;
	}
	while (map_data->line[x])
	{
		if (map_data->line[x][0] != '1' || map_data->line[x][map_data->y] != '1')
				sl_map_invalid(map_data);
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
			{
				printf("Invalid:%c\n", map_data->line[x][y]);
				return (-1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	sl_map_error_main(t_map *map_data)
{
	sl_valid_map_limit(map_data);
	if (sl_map_standards(map_data->line) == -1)
		sl_map_invalid(map_data);
	if (sl_map_asset_valid(map_data) == -1)
		sl_map_invalid(map_data);
}