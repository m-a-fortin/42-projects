/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:17:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/08 16:06:48 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map_data; //pas oublier de free map_data
	t_mlx	*ptrs;// pas oublier de free
	t_image	*image_data;

	ptrs = malloc(sizeof(t_mlx));
	map_data = malloc(sizeof(t_map));
	image_data = malloc(sizeof(t_image));
	sl_map_main(map_data, argv, argc);
	ptrs->mlx = mlx_init();
	ptrs->win = mlx_new_window(ptrs->mlx, 2500, 2500, "Link to the so_long");
	sl_print_map_main(map_data, ptrs);
	mlx_loop(ptrs->mlx);
	sl_exit(map_data, ptrs);
	return (0);
}
