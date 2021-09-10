/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:28:46 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/10 16:39:19 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_player_image(t_main *structs)
{
	int	width;
	int	height;

	structs->link->front1 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_front.xpm", &width, &height);
	structs->link->front2 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_front1.xpm", &width, &height);
	structs->link->front3 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_front2.xpm", &width, &height);
	structs->link->left1 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_left.xpm", &width, &height);
	structs->link->left2 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_left1.xpm", &width, &height);
	structs->link->left3 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_left2.xpm", &width, &height);
	structs->link->right1 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_right1.xpm", &width, &height);
	structs->link->right2 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_right2.xpm", &width, &height);
	structs->link->right3 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_right3.xpm", &width, &height);
	structs->link->back1 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_back.xpm", &width, &height);
	structs->link->back2 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_back1.xpm", &width, &height);
	structs->link->back3 = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/link_back2.xpm", &width, &height);
}

void	sl_player_main(t_main *structs)
{
	int	x;
	int	y;

	x = 0;
	sl_player_image(structs);
	while (structs->map_data->line[x])
	{
		y = 0;
		while (structs->map_data->line[x][y])
		{
			if (structs->map_data->line[x][y] == 'P')
			{
				sl_print_tile(structs, structs->tiles->floor, x, y);
				sl_print_tile(structs, structs->link->front1, x, y);
			}
			y++;
		}
		x++;
	}
}