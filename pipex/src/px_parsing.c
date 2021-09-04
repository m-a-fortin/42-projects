/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:29:13 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/03 13:00:45 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	px_parsing_path(t_fdcmd *infos, char *envp[])
{
	int	x;

	x = 0;
	while (envp[x])
	{
		if (envp[x][0] == 'P' && envp[x][1] == 'A' && envp[x][2] == 'T' &&
			envp[x][3] == 'H' && envp[x][4] == '=')
			break ;
		x++;
	}
	while (*envp[x] != '/')
		envp[x]++;
	infos->env_path = ft_split(envp[x], ':');
}

char	*px_find_path(t_fdcmd *infos, char *cmd)
{
	int		done;
	int		index;
	char	*path;

	done = 1;
	index = 0;
	while (infos->env_path[index])
	{
		path = ft_strjoin(infos->env_path[index], cmd);
		done = access(path, F_OK);
		if (done == 0)
			return (path);
		free(path);
		index++;
	}
	if (done != 0)
		px_error_cmd(infos);
	return ("NEVERGOINGTOHAPPEN");
}

void	px_parsing_main(t_fdcmd *infos, char **argv, char *envp[])
{	
	int		index;
	char	*cmd_name1;
	char	*cmd_name2;

	index = 0;
	infos->fds[0] = argv[1];
	infos->fds[1] = argv[4];
	infos->cmd1 = ft_split(argv[2], ' ');
	infos->cmd2 = ft_split(argv[3], ' ');
	cmd_name1 = ft_strjoin("/", infos->cmd1[0]);
	cmd_name2 = ft_strjoin("/", infos->cmd2[0]);
	px_parsing_path(infos, envp);
	infos->pathname1 = px_find_path(infos, cmd_name1);
	infos->pathname2 = px_find_path(infos, cmd_name2);
	free(cmd_name1);
	free(cmd_name2);
}
