/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:17:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/07 17:12:11 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map_data; //pas oublier de free map_data et close map_data->fd

	map_data = malloc(sizeof(t_map));
	sl_map_main(map_data, argv, argc);
	close (map_data->fd);
	return (0);
}
