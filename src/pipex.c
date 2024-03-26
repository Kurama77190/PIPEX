/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:52:24 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/26 18:22:05 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_pipex(int argc, char **argv, char **envp)
{
    (void)argc; // pour le bonus
	int fd[2];
    pid_t child_pid;
    int status;
	char *path;
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
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		path = get_cmd(argv,envp, 2);
		if (execve(path, ft_split(argv[2], ' '), envp) == ERROR)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		free(path);
		close(fd_in);
		close(fd[1]);
	}
	else
	{
		path = get_cmd(argv, envp, 3);
		printf("%s\n", path);
		int fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        if (fd_out == ERROR)
        {
            perror("open");
            exit(EXIT_FAILURE);
        }
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		
		
		if (execve(path, ft_split(argv[3], ' '), envp) == ERROR)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		free(path);
		wait(&status);
		if (status == -1)
		{
			ft_error_msg("Error executing command: cmd1");
			exit(EXIT_FAILURE);
		}
	}
    return (SUCCESS);
}
