/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:47:45 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/02 14:08:19 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd);
void	ft_error_msg_pross(char *msg_error);

void	ft_error_msg(char *msg_error)
{
	perror(msg_error);
	// ft_putstr_fd(msg_error, 2);
	exit(EXIT_FAILURE);
}

void	ft_error_msg_pross(char *msg_error)
{
	dprintf(2, "je suis passer ici");
	perror(msg_error);
	exit(EXIT_FAILURE);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		if (write(fd, &s[i], 1) == -1)
			return ;
		i++;
	}
}
