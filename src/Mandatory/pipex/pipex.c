/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:52:24 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/04 19:54:04 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <limits.h>

int		ft_exec_cmd(char **argv, char **envp, int i);
int		ft_exec_first_cmd(char **argv, char **envp, int fd[], int i);
int		ft_exec_last_cmd(int argc, char **av, char **envp, int fd[], int i);
bool	ft_path_exist(char *argv);
int		ft_real_path(char **argv, char **envp, int i);
int		ft_not_real_path(char **argv, char **envp, int i);


int		ft_pipex(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pipe;
	int		status;
	int		i;

	i = 1;
	pipe = 42;
	while (i++ < argc - 2 && pipe != ERROR)
	{
		if (i == 2)
			pipe = ft_exec_first_cmd(argv, envp, fd, i);
		// else if (i > 2 && i < argc - 2)
		// 	ft_exec_multi_cmd(argv, emvp, fd, i);
		else if (i == argc - 2)	
			pipe = ft_exec_last_cmd(argc, argv, envp, fd, i);
	}
	while (wait(&status) > 0)
		;
	return (0);
}
