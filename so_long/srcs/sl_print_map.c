/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:09:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/08 16:08:24 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*sl_print_wall(t_image *image_data)
{

	= mlx_xpm_file_to_image()
}
void	sl_print_map_main(t_map *map_data, t_mlx *ptrs, t_image *image_data)
{
	int	height;
	int	width;
	int	x;
	int	y;
	int	img_index;

	x = 0;
	y = 0;
	while (map_data->line[x])
	{
		while (map_data->line[x][y])
		{
			if (map_data->line[x][y] == '1')
				sl_print_wall(image_data)
		}
	}
	ptrs->img = mlx_xpm_file_to_image(ptrs->mlx, "assets/link_front.xpm", &width, &height);
	printf("x:%d\ny:%d\n", x, y);
	mlx_put_image_to_window(ptrs->mlx, ptrs->win, ptrs->img, 0, 0);
}