/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:22:49 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/03 12:59:31 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	px_check_error_args(int argc, t_fdcmd *infos)
{
	if (argc != 5)
	{
		write(1, "Incorrect # of arguments Use: FILE1 CMD1 CMD2 FILE2", 52);
		px_free(infos);
		exit (-1);
	}
	return (0);
}

void	px_error_cmd(t_fdcmd *infos)
{
	perror("Oh Oh Une Erreur");
	px_free(infos);
	exit(0);
}

void	px_error_fd(t_fdcmd *infos, int fd)
{	
	perror("Oh Oh Une Erreur");
	close (fd);
	px_free(infos);
	exit (0);
}

void	px_pipe_error(t_fdcmd *infos, char error, int *fdpipe)
{
	if (error == 'P')
		perror("Oh Oh Une Erreur");
	if (error == 'F')
		perror("Oh Oh Une Erreur");
	close(fdpipe[0]);
	close(fdpipe[1]);
	px_free(infos);
	exit(0);
}

void	px_free(t_fdcmd *infos)
{
	if (infos->env_path)
		ft_free_tab(infos->env_path);
	if (infos->pathname1)
		free(infos->pathname1);
	if (infos->pathname2)
		free(infos->pathname2);
	if (infos->cmd1)
		ft_free_tab(infos->cmd1);
	if (infos->cmd2)
		ft_free_tab(infos->cmd2);
	if (infos)
		free(infos);
	return ;
}
