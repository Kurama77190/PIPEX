/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_prossessus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:37:52 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/28 08:38:38 by sben-tay         ###   ########.fr       */
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
