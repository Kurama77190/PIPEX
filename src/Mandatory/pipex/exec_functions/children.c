/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:20:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/04 18:35:04 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	ft_exec_first_cmd(char **argv, char **envp, int fd[], int i)
{
	int		fd_in;
	pid_t	pid;

	if((fd_in = open(argv[i - 1], O_RDONLY)) == ERROR)		
		return (ft_error_msg(argv[i - 1]), ERROR);
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

int	ft_exec_last_cmd(int argc, char **argv, char **envp, int fd[], int i)
{
	int		fd_out;
	pid_t	pid;
	
	if ((fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == ERROR)
		return (ft_error_msg("open"), ERROR);
	if ((pid = fork()) == ERROR)
		return (ft_error_msg("fork"), ERROR);
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		ft_exec_cmd(argv, envp, i);
	}
	close(fd_out);
	close(fd[0]);
	return (SUCCESS);
}

int	ft_exec_cmd(char **argv, char **envp, int i)
{
	if (!ft_path_exist(argv[i]))
	{
		if (!envp[0])
		{
			ft_error_msg("Error: environement not found\n");
			exit(EXIT_FAILURE);
		}
		if(ft_not_real_path(argv, envp, i) == SUCCESS)
			return(SUCCESS);
		else
			return(ERROR);
	}
	else
	{
		if(ft_real_path(argv, envp, i) == SUCCESS)
			return (SUCCESS);
		else
			return (ERROR);
		
	}
	return(SUCCESS);
}
