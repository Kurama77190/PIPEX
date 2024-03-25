/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:55:41 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/25 18:00:59 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_cmd(char **path, char **cmd, int i)
{
	int		index;
	char	*check;

	index = 0;
	if (!path)
		return NULL;
	while(path[index])
	{
		check = ft_strjoin(path[index], cmd[i]);
		if (access(check, F_OK) == SUCCESS)
		{
			if(access(check, X_OK) == SUCCESS)
			{
				free_split(path);
				return (check);
			}
			else
				perror(cmd[i]);
		}
		index ++;
		free(check);
	}
	free_split(path);
	perror(cmd[i]);
	return (NULL);
}
