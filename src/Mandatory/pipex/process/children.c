/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:20:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/31 16:16:14 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* ******************************* */
/* 		👶 SETUP FIRST CHILDREN 👶   */
/* ******************************* */

int	ft_setup_first_children(t_pipex *data, int i)
{
	data->fd_in = open(data->argv[i - 1], O_RDONLY);
	if (pipe(data->fd) == ERROR)
		return (ft_error_msg("pipe"));
	if (data->fd_in == ERROR)
		return (ft_error_msg(data->argv[i - 1]), close(data->fd[1]));
	if (fork_and_add_pid(data) == ERROR)
		return (ERROR);
	if (data->pid_tmp == 0)
	{
		close(data->fd[0]);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[1]);
		dup2(data->fd_in, STDIN_FILENO);
		close(data->fd_in);
		if (ft_exec_cmd(data, i) == ERROR)
			exit(1);
	}
	close(data->fd[1]);
	if (data->fd_in != ERROR)
		close(data->fd_in);
	return (SUCCESS);
}

/* ******************************* */
/*   👶  SETUP LAST CHILDREN 👶   */
/* ******************************* */

int	ft_setup_last_children(t_pipex *data, int i)
{
	data->fd_out = open(data->argv[data->argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out == ERROR)
		return (ft_error_msg(data->argv[data->argc - 1]), close(data->fd[0]));
	if (fork_and_add_pid(data) == ERROR)
		return (ERROR);
	if (data->pid_tmp == 0)
	{
		close(data->fd[1]);
		dup2(data->fd_out, STDOUT_FILENO);
		close(data->fd_out);
		dup2(data->fd[0], STDIN_FILENO);
		close(data->fd[0]);
		if (ft_exec_cmd(data, i) == ERROR)
		{
			ft_lstclear(&data->data_pid, free);
			exit(1);
		}
	}
	close(data->fd[0]);
	if (data->fd_out != ERROR)
		close(data->fd_out);
	return (SUCCESS);
}
