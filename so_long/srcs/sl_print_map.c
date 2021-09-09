/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:09:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/08 21:54:10 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_print_tile(t_mlx *ptrs, char *file_name, int x, int y)
{
	int		height;
	int		width;
	int		index;

	index = ptrs->img_index;
	x *= 75;
	y *= 75;
	ptrs->images[index] = mlx_xpm_file_to_image(ptrs->mlx, file_name, &height, &width);
	mlx_put_image_to_window(ptrs->mlx, ptrs->win, ptrs->images[index], y, x);
	ptrs->img_index++;
}
void	sl_print_map_main(t_map *map_data, t_mlx *ptrs)
{
	int	x;
	int	y;

	x = 0;
	ptrs->img_index = 0;
	while (map_data->line[x])
	{
		y = 0;
		while (map_data->line[x][y])
		{
			if (map_data->line[x][y] == '1')
				sl_print_tile(ptrs, "assets/xpm/wall.xpm", x, y);
			if (map_data->line[x][y] == '0')
				sl_print_tile(ptrs, "assets/xpm/floor.xpm", x, y);
			y++;
			ptrs->img_index++;
		}
		x++;
	}
}