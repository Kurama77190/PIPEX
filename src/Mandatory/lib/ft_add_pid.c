/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 03:46:24 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/28 07:16:21 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pid	*new_node(pid_t new_pid);

void	ft_add_pid(t_pipex *data, pid_t new_pid)
{
	t_pid	*current;

	if (data->data_pid == NULL)
	{
		data->data_pid = new_node(new_pid);
	}
	else
	{
		current = data->data_pid;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node(new_pid);
	}
}

t_pid	*new_node(pid_t new_pid)
{
	t_pid	*new_node;

	new_node = malloc(sizeof(t_pid));
	if (new_node == NULL)
	{
		perror("Failed to allocate memory for new PID node");
		return (NULL);
	}
	new_node->pid = new_pid;
	new_node->status = -1;
	new_node->next = NULL;
	return (new_node);
}
