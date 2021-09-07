/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:24:06 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/07 18:39:13 by hpst             ###   ########.fr       */
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
	return (count + 1);
}

void	sl_get_map(t_map *map_data, char *file_name, int line_count)
{
	int	ret;
	int	index;

	ret = 1;
	index = 0;
	map_data->fd = open(file_name, O_RDONLY);
	map_data->line = calloc(line_count, sizeof(map_data->line));
	while (ret > 0)
	{
		ret = get_next_line(map_data->fd, &map_data->line[index]);
		printf("%s\n", map_data->line[index]);
		index++;
	}	
}

void	sl_map_main(t_map *map_data, char **argv, int argc)
{
	int	line_count;
	
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
		line_count = sl_line_count(map_data);
	sl_get_map(map_data, argv[1], line_count);
	int index = 0;
	while (map_data->line)
	{
		printf("%s\n", map_data->line[index]);
		index++;
	}
}
