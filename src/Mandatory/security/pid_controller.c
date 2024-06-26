/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:28:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/29 19:11:11 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_return_last_ifexited(t_pipex *data);

/* ******************************************** */
/*  ⚙️ SEARCH_LAST_PID'S_STATUS_FOR_RETURN ⚙️  */
/* ******************************************** */

void	ft_setup_status_pid(t_pipex *data)
{
	int		status;
	pid_t	pid;
	t_pid	*current;

	pid = waitpid(-1, &status, 0);
	while (pid != -1)
	{
		current = data->data_pid;
		while (current != NULL)
		{
			if (current->pid == pid)
			{
				current->status = status;
				break ;
			}
			current = current->next;
		}
		pid = waitpid(-1, &status, 0);
	}
	ft_return_last_ifexited(data);
}

static void	ft_return_last_ifexited(t_pipex *data)
{
	t_pid	*current;

	current = data->data_pid;
	while (current != NULL)
	{
		data->return_exit_code = WEXITSTATUS(current->status);
		current = current->next;
	}
	if (data->return_exit_code == 0 && data->fdout_no_w == -1)
		data->return_exit_code = 1;
}
