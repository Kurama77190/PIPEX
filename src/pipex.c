/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:52:24 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/25 18:04:06 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_pipex(char **argv, char **envp)
{
    int fd[2];
    pid_t child_pid;
    int status;
	int fd_in = open(argv[1], O_RDONLY);
	if(fd_in == ERROR)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	
    if (pipe(fd) == ERROR)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
	if ((child_pid = fork()) == ERROR)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		close(fd[0]);
		close(STDOUT_FILENO);
		dup(fd[1]);
		close(fd[1]);
		if (execve(get_cmd(get_path(envp), argv, 2), ft_split(argv[2], ' '), envp) == ERROR)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(fd[1]);
		close(STDIN_FILENO);
		dup(fd[0]);
		close(fd[0]);
		int fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        if (fd_out == ERROR)
        {
            perror("open");
            exit(EXIT_FAILURE);
        }
		dup2(fd[0], STDOUT_FILENO);
		if (execve(get_cmd(get_path(envp), argv, 3), ft_split(argv[3], ' '), envp) == ERROR)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		wait(&status);
		if (status == -1)
		{
			ft_error_msg("Error executing command: cmd1");
			exit(EXIT_FAILURE);
		}
	}
    return (SUCCESS);
}
