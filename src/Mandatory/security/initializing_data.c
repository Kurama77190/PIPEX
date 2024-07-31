/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:32:18 by sben-tay          #+#    #+#             */
/*   Updated: 2024/07/31 16:02:59 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_fd_out_writable(t_pipex *data);

/* ******************** */
/*  ⚙️ DATA_PANNEL ⚙️  */
/* ******************** */

void	initializing_data(t_pipex *data, int argc, char **argv, char **envp)
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->cmd = NULL;
	data->path = NULL;
	data->data_pid = NULL;
	data->fd_in = -1;
	data->fd_out = -1;
	data->fd[0] = -1;
	data->fd[1] = -1;
	data->pid_tmp = -1;
	data->return_exit_code = -1;
	data->fdout_no_w = 0;
	check_fd_out_writable(data);
}

void	check_fd_out_writable(t_pipex *data)
{
	int	tmp;

	tmp = open(data->argv[data->argc - 1], O_WRONLY);
	if (tmp == ERROR)
	{
		if (errno == EACCES)
			data->fdout_no_w = -1;
	}
	if (tmp != ERROR)
		close(tmp);
	tmp = ft_strncmp(data->argv[2], "yes", 3);
	if (tmp == 0 && data->fdout_no_w == -1)
	{
		ft_error_permission(data->argv[data->argc - 1]);
		exit(1);
	}
	return ;
}
