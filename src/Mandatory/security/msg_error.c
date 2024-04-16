/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:45:06 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/16 02:26:15 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_msg(char *msg_error)
{
	ft_printf("bash: %s: %s\n", msg_error, strerror(errno));
	return (ERROR);
}

void	ft_error_arguments(void)
{
	ft_putstr_fd("Error: expected 4 arguments\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_cmd(char *cmd)
{
	dprintf(2, "bash: %s: command not found\n", cmd);
	exit(127);
}


// isoler les messages erreurs : fork, open, 