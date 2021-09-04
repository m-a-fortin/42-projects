/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:06:27 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/03 12:57:28 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <errno.h>

typedef struct s_fdcmd
{
	char	**cmd1;
	char	**cmd2;
	char	**env_path;
	char	*pathname1;
	char	*pathname2;
	char	*fds[2];

}				t_fdcmd;

int		main(int argc, char **argv, char *envp[]);
int		px_check_error_args(int argc, t_fdcmd *infos);
void	px_parsing_main(t_fdcmd *infos, char **argv, char *envp[]);
void	px_free(t_fdcmd *infos);
char	*px_find_path(t_fdcmd *infos, char *cmd);
void	px_error_cmd(t_fdcmd *infos);
void	px_pipe_error(t_fdcmd *infos, char error, int *fdpipe);
void	px_error_fd(t_fdcmd *infos, int fd);

#endif