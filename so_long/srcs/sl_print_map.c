/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:09:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/10 17:04:52 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_print_tile(t_main *structs, void *tile, int x, int y)
{
	x *= 75;
	y *= 75;

	mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, tile, y, x);
}

void	sl_print_loop(t_main *structs, int x, int y)
{
	while (structs->map_data->line[x])
	{
		y = 0;
		while (structs->map_data->line[x][y])
		{
			if (structs->map_data->line[x][y] == '1')
				sl_print_tile(structs, structs->tiles->wall, x, y);
			if (structs->map_data->line[x][y] == 'E')
			{
				sl_print_tile(structs, structs->tiles->floor, x, y);
				sl_print_tile(structs, structs->tiles->exit, x, y);
			}
			if (structs->map_data->line[x][y] == 'C')
			{
				sl_print_tile(structs, structs->tiles->floor, x, y);
				sl_print_tile(structs, structs->tiles->key, x, y);
			}
			if (structs->map_data->line[x][y] == '0')
				sl_print_tile(structs, structs->tiles->floor, x , y);
			y++;
			structs->ptrs->img_index++;
		}
		x++;
	}
}

int	sl_print_map(t_main *structs)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	structs->ptrs->img_index = 0;
	sl_print_loop(structs, x , y);
	return (1);
}

void	sl_check_assets(t_main *structs)
{
	if (open("assets/xpm/floor.xpm", O_RDONLY) < 0)
	{
		ft_putstr_fd("Oh Oh, tu as jouer avec les assets. FAIT PAS CA!\n", 1);
		sl_exit(structs);
	}
	if (open("assets/xpm/wall.xpm", O_RDONLY) < 0)
	{
		ft_putstr_fd("Oh Oh, tu as jouer avec les assets. FAIT PAS CA!\n", 1);
		sl_exit(structs);
	}
	if (open("assets/xpm/chest.xpm", O_RDONLY) < 0)
	{
		ft_putstr_fd("Oh Oh, tu as jouer avec les assets. FAIT PAS CA!\n", 1);
		sl_exit(structs);
	}
	if (open("assets/xpm/key.xpm", O_RDONLY) < 0)
	{
		ft_putstr_fd("Oh Oh, tu as jouer avec les assets. FAIT PAS CA!\n", 1);
		sl_exit(structs);
	}

}
void	sl_print_map_main(t_main *structs)
{
	int	width;
	int	height;
	int	width_win;
	int	height_win;

	width_win = (structs->map_data->y + 1) * 75;
	height_win = (structs->map_data->x + 1) * 75;
	sl_check_assets(structs);
	structs->ptrs->mlx = mlx_init();
	structs->ptrs->win = mlx_new_window(structs->ptrs->mlx, width_win, height_win, "Link to the so_long");
	structs->tiles->floor = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/floor.xpm", &width, &height);
	structs->tiles->wall = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/wall.xpm", &width, &height);
	structs->tiles->exit = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/chest.xpm", &width, &height);
	structs->tiles->key = mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/key.xpm", &width, &height);
	mlx_loop_hook(structs->ptrs->mlx, sl_print_map, structs);
}
