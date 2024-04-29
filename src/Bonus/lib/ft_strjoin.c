/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:04:11 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/09 16:38:40 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_strlen_join(const char *str);

char	*ft_strjoin(char *s1, char *s2)
{
	size_t			i;
	size_t			j;
	char			*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * \
	(ft_strlen_join(s1) + ft_strlen_join(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	ft_strlen_join(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
