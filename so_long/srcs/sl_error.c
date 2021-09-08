/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:49:10 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/08 13:05:11 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_fd_error(t_map *map_data, char **argv)
{
	char	*error_msg;

	error_msg = ft_strjoin("Oh Oh, Une Erreur -> ", argv[1]);
	perror(error_msg);
	write(1, "Ne pas oublier le .ber a la fin du nom de la map\n", 49);
	free(error_msg);
	free(map_data);
	exit(0);
}

void	sl_map_invalid(t_map *map_data)
{
	ft_putstr_fd("Oh Oh, la map ne respecte pas les normes\n", 1);
	ft_free_tab(map_data->line);
	free(map_data);
	exit (0);
}

void	sl_exit(t_map *map_data, t_mlx *ptrs)
{
	ft_free_tab(map_data->line);
	if (map_data)
		free(map_data);
	if (ptrs)
		free(ptrs);
	exit (0);
}
