/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:24:06 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/07 17:33:43 by mafortin         ###   ########.fr       */
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

int	sl_line_count(t_map *map_data)
{

}

void	sl_get_map(t_map *map_data)
{
	int	ret;
	int	index;
	int	line_count;

	ret = 1;
	index = 0;
	line_count = sl_line_count(map_data);
	while (ret > 0)
	{
		ret = get_next_line(map_data->fd, &map_data->line[index]);
		printf("%s\n", map_data->line[index]);
		index++;
	}
	map_data->line[index] = "\0";
}

void	sl_map_main(t_map *map_data, char **argv, int argc)
{
	if (argc != 2)
	{
		write(1,
			"Incorrect # of arguments Use: ./so_long \"name of map file\".ber\n",
			63);
		free(map_data);
		exit (0);
	}
	else
		map_data->fd = open(argv[1], O_RDONLY);
	if (map_data->fd == -1)
		sl_fd_error(map_data, argv);
	else
		sl_get_map(map_data);
	int index = 0;
	while (map_data->line)
	{
		printf("%s\n", map_data->line[index]);
		index++;
	}
}
