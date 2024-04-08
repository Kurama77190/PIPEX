/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:45:06 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/08 14:58:29 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_msg(char *msg_error)
{
	ft_putstr_fd("bash: ", 2);
	perror(msg_error);
	return (ERROR);
}

void	ft_error_arguments(void)
{
	ft_putstr_fd("Error: expected 4 arguments\n", 2);
	exit(EXIT_FAILURE);
}

char	*ft_error_cmd(char **commands, char **path)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(commands[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_split(commands);
	free_split(path);
	return (NULL);
}

// isoler les messages erreurs : fork, open, 