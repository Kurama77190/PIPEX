/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:37:52 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/29 15:06:31 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fork_and_add_pid(t_pipex *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == ERROR)
	{
		if (data->fd_out != -1)
			close(data->fd_out);
		if (data->fd_in != -1)
			close(data->fd_in);
		return (ft_error_msg("fork"));
	}
	else if (pid > 0)
		ft_add_pid(data, pid);
	else if (pid == 0)
		data->pid_tmp = pid;
	return (SUCCESS);
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
	close(tmp);
	tmp = ft_strncmp(data->argv[2], "yes", 3);
	if (tmp == 0 && data->fdout_no_w == -1)
	{
		ft_error_permission(data->argv[data->argc - 1]);
		// while (wait(NULL))
		// 	;
		exit(1);
	}
	return ;
}
