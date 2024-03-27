/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:52:24 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/27 02:08:44 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <limits.h>

int		ft_exec_cmd(char **argv, char **envp, int i);
int		ft_exec_first_cmd(char **argv, char **envp, int fd[], int i);
int		ft_exec_last_cmd(int argc, char **av, char **envp, int fd[], int i);


int		ft_pipex(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pipe;
	int		status;
	int		i;

	i = 2;
	pipe = 42;
	printf("i = %d, argv = %s\n", i, argv[i]);
	while (i++ < argc - 2 && pipe != ERROR)
	{
		if (i == 2)
		{
			pipe = ft_exec_first_cmd(argv, envp, fd, i);
		}
		else
		{
			pipe = ft_exec_last_cmd(argc, argv, envp, fd, i);
			
		}
	}
	while (wait(&status) > 0)
		;
	return (0);
}

// a debugger
int	ft_exec_cmd(char **argv, char **envp, int i)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv[i], ' ');
	if (!cmd)
		return (free_split(cmd), ERROR);
	path = get_cmd(argv, envp, i);
	if (!path)
	{
		free_split(cmd);
		return (ft_error_msg(argv[i]), ERROR);
	}
	if (execve(path, cmd, envp) == ERROR)
	{
		free_split(cmd);
		free(path);
		ft_error_msg("execve");
	}
	free_split(cmd);
	free(path);
	return (0);
}

// a debbuger
int	ft_exec_first_cmd(char **argv, char **envp, int fd[], int i)
{
	int		fd_in;
	pid_t	pid;
	if((fd_in = open(argv[i - 1], O_RDONLY)) == ERROR)		
		return (ft_error_msg("open"), ERROR);
	if (pipe(fd) == ERROR)
		return (ft_error_msg("pipe"), ERROR);
	if ((pid = fork()) == ERROR)
		return (ft_error_msg("fork"), ERROR);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_exec_cmd(argv, envp, i);
	}
	close(fd[1]);
	close(fd_in);
	return (SUCCESS);
}

// a debbuger
int	ft_exec_last_cmd(int argc, char **argv, char **envp, int fd[], int i)
{
	pid_t	pid;
	int		fd_out;

	if ((pid = fork()) == ERROR)
		return (ft_error_msg("fork"), ERROR);
	if (pid == 0)
	{
		close(fd[1]);
		fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_out == ERROR)
		{
			return (ft_error_msg("open"), ERROR);
			exit(EXIT_FAILURE);
		}
		dup2(fd_out, STDIN_FILENO);
		close(fd_out);
		dup2(fd[0], STDOUT_FILENO);
		close(fd[0]);
		ft_exec_cmd(argv, envp, i);
	}
	close(fd_out);
	close(fd[0]);
	return (SUCCESS);
}
