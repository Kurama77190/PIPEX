/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:32:18 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/28 08:33:50 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
}
