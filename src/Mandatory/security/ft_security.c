/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:45:06 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/03 17:47:18 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_msg_pross(char *msg_error);

void	ft_error_msg(char *msg_error)
{
	perror(msg_error);
	exit(EXIT_FAILURE);
}

void	ft_error_msg_pross(char *msg_error)
{
	perror(msg_error);
	exit(EXIT_FAILURE);
}

bool	ft_path_exist(char *argv)
{
	return (access(argv, F_OK) == SUCCESS && access(argv, X_OK) == SUCCESS);
}
