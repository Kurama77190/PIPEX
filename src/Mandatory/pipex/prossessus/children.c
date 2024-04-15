/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:20:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/15 18:33:50 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd_and_path(t_pipex *data);

/* ******************************* */
/* 	 👶 SETUP FIRST CHILDREN 👶   */
/* ******************************* */

int	ft_setup_first_children(t_pipex *data, int i)
{
	data->fd_in = open(data->argv[i - 1], O_RDONLY);
	if (data->fd_in == ERROR)
		return (ft_error_msg(data->argv[i - 1]), ERROR);
	if (pipe(data->fd) == ERROR)
		return (ft_error_msg("pipe"));
	data->pid = fork();
	if (data->pid == ERROR)
		return (ft_error_msg("fork"));
	if (data->pid == 0)
	{
		close(data->fd[0]);
		dup2(data->fd_in, STDIN_FILENO);
		close(data->fd_in);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[1]);
		ft_exec_cmd(data, i);
	}
	free_cmd_and_path(data);
	close(data->fd[1]);
	close(data->fd_in);
	return (SUCCESS);
}

/* ******************************* */
/*   👶  SETUP LAST CHILDREN 👶    */
/* ******************************* */

int	ft_setup_last_children(t_pipex *data, int i)
{
	data->fd_out = open(data->argv[data->argc - 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out == ERROR)
		return (ft_error_msg("open"));
	data->pid = fork();
	if (data->pid == ERROR)
		return (ft_error_msg("fork"));
	if (data->pid == 0)
	{
		close(data->fd[1]);
		dup2(data->fd_out, STDOUT_FILENO);
		close(data->fd_out);
		dup2(data->fd[0], STDIN_FILENO);
		close(data->fd[0]);
		ft_exec_cmd(data, i);
	}
	free_cmd_and_path(data);
	close(data->fd[0]);
	close(data->fd_out);
	return (SUCCESS);
}

void	free_cmd_and_path(t_pipex *data)
{
	if (data->cmd)
		free_split(data->cmd);
	if (data->path)
		free(data->path);
}
