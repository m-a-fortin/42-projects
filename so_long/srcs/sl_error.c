/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:49:10 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/13 18:13:36 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_fd_error(t_map *map_data, char **argv)
{
	char	*error_msg;

	error_msg = ft_strjoin("Error\nOh Oh-> ", argv[1]);
	perror(error_msg);
	ft_putstr_fd("Ne pas oublier le .ber a la fin du nom de la map\n", 1);
	free(error_msg);
	free(map_data);
	exit(0);
}

void	sl_map_invalid(t_map *map_data)
{
	ft_putstr_fd("Error\nOh Oh, la map ne respecte pas les normes\n", 1);
	ft_free_tab(map_data->line);
	free(map_data);
	exit (0);
}

void	sl_destroy(t_mlx *ptrs, t_images *tiles)
{
	mlx_destroy_image(ptrs->mlx, tiles->exit);
	mlx_destroy_image(ptrs->mlx, tiles->floor);
	mlx_destroy_image(ptrs->mlx, tiles->wall);
	mlx_destroy_image(ptrs->mlx, tiles->key);
}

void	sl_exit(t_main *structs)
{
	sl_destroy(structs->ptrs, structs->tiles);
	ft_free_tab(structs->map_data->line);
	if (structs->link)
		free(structs->link);
	if (structs->bubble)
		free(structs->bubble);
	if (structs->map_data)
		free(structs->map_data);
	if (structs->ptrs)
		free(structs->ptrs);
	if (structs->tiles)
		free(structs->tiles);
	if (structs)
		free(structs);
	exit (0);
}
