/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:45:06 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/16 23:57:32 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_msg(char *msg_error)
{
	ft_dprintf(2, "bash: %s: %s\n", msg_error, strerror(errno));
	return (ERROR);
}

void	ft_error_arguments(void)
{
	ft_dprintf(2, "Error: expected 4 arguments\n");
	exit(EXIT_FAILURE);
}

void	ft_error_cmd(pid_t pid, bool flag, char *cmd)
{
	if (flag)
	{
		waitpid(pid, NULL, 0);
		ft_dprintf(2, "bash: %s: command not found\n", cmd);
		exit(127);
	}
	else
	{
		ft_dprintf(2, "bash: %s: command not found\n", cmd);
		exit(0);
	}
}

// isoler les messages erreurs : fork, open, 