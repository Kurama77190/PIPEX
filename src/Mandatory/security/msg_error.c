/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:45:06 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/06 17:57:39 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_msg(char *msg_error)
{
	ft_putstr_fd("bash: ", 2);
	perror(msg_error);
	// exit(EXIT_FAILURE);
	return (ERROR);
}

void	ft_error_arguments(void)
{
	ft_putstr_fd("Error: expected 4 arguments\n", 2);
	exit(EXIT_FAILURE);
}

char	*ft_error_cmd(char **commands, char **path, char **envp)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(commands[0], 2);
	if (!envp[0])
		ft_putstr_fd(": No such file directory\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
	free_split(commands);
	free_split(path);
	return (NULL);
}

// isoler les messages erreurs : fork, open, 