/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:45:47 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/28 18:23:19 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return ;
	if (write(fd, &s[i], len) == -1)
		return ;
}
