/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:55:41 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/21 16:57:44 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_cmd(char **path, char *cmd)
{
	int		index;
	char	*check;
	index = 0;
	while(path[index])
	{
		check = ft_strjoin(path[index], cmd);
		if (access(check, F_OK) == 0)
		{
			if(access(check, X_OK) == 0)
				return ("FOUND_&_EXEC_OK");
			else
				perror(cmd);
		}
		index ++;
	}
	perror(cmd);
	return (NULL);
}
