/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:24:06 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/10 16:51:11 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_line_count(t_map *map_data)
{
	int		count;
	int		ret;
	char	buf[2];

	count = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = read(map_data->fd, buf, 1);
		if (ret < 0)
		{
			close(map_data->fd);
			return (-1);
		}
		buf[1] = '\0';
		if (buf[0] == '\n')
		count++;
	}
	close(map_data->fd);
	if (count == 1)
		sl_map_invalid(map_data);
	return (count + 1);
}

void	sl_get_map(t_map *map_data, char *file_name, int line_count)
{
	int	ret;
	int	index;
	int	len;

	len = 0;
	ret = 1;
	index = 0;
	map_data->fd = open(file_name, O_RDONLY);
	map_data->line = calloc(line_count + 1, sizeof(map_data->line));
	ret = get_next_line(map_data->fd, &map_data->line[index]);
	map_data->y = ft_strlen(map_data->line[index]);
	index++;
	while (ret > 0)
	{
		ret = get_next_line(map_data->fd, &map_data->line[index]);
		len = ft_strlen(map_data->line[index]);
		if (len != map_data->y)
			sl_map_invalid(map_data);
		index++;
	}
	map_data->x = line_count - 1;
	map_data->nb_tiles = (map_data->x + 1) * map_data->y;
	map_data->y--;
	close(map_data->fd);
}

void	sl_parse_map_main(t_map *map_data, char **argv, int argc)
{
	int	line_count;
	
	line_count = 0;
	if (argc != 2)
	{
		write(1,
			"Incorrect # of arguments Use: ./so_long \"name of map file\".ber\n",
			63);
		free(map_data);
		exit (0);
	}
	map_data->fd = open(argv[1], O_RDONLY);
	if (map_data->fd == -1)
		sl_fd_error(map_data, argv);
	else
		line_count = sl_line_count(map_data);
	sl_get_map(map_data, argv[1], line_count);
	sl_map_error_main(map_data);
}
