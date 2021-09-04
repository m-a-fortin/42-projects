/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:05:49 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/03 12:59:22 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	px_fork_in(t_fdcmd *infos, int *pipefd, char *envp[])
{
	int		fd;

	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close (pipefd[1]);
	fd = open(infos->fds[0], O_RDONLY);
	if (fd < 0)
		px_error_fd(infos, fd);
	dup2(fd, 0);
	close (fd);
	if (execve(infos->pathname1, infos->cmd1, envp) == -1)
	{
		perror("Error");
		px_free(infos);
		exit(0);
	}
}

void	px_fork_out(t_fdcmd *infos, int *pipefd, char *envp[])
{
	int	fd;

	wait(0);
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	fd = open(infos->fds[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		px_error_fd(infos, fd);
	dup2(fd, 1);
	close (fd);
	if (execve(infos->pathname2, infos->cmd2, envp) == -1)
	{
		perror("Error");
		px_free(infos);
		exit(0);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_fdcmd	*infos;
	int		fdpipe[2];
	int		pid;

	infos = malloc(sizeof(t_fdcmd));
	px_check_error_args(argc, infos);
	px_parsing_main(infos, argv, envp);
	if (pipe(fdpipe) == -1)
		px_pipe_error(infos, 'P', fdpipe);
	pid = fork();
	if (pid == -1)
		px_pipe_error(infos, 'F', fdpipe);
	if (pid == 0)
		px_fork_in(infos, fdpipe, envp);
	else if (pid > 0)
		px_fork_out(infos, fdpipe, envp);
	px_free(infos);
}
