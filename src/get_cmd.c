/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:55:41 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/23 15:37:43 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_cmd(char **path, char **cmd)
{
	int		index;
	char	*check;

	index = 0;
	while(path[index])
	{
		printf("je suis rentrer dans la boucle\n");
		check = ft_strjoin(path[index], cmd[0]);
		printf("mon check est : %s\n", check);
		if (access(check, F_OK) == SUCCESS)
		{
			printf("je suis rentrer F_OK\n");

			if(access(check, X_OK) == SUCCESS)
			{
				printf("je suis rentrer X_OK\n");
				free_split(path);
				return (check);
			}
			else
				perror(cmd[0]);
		}
		index ++;
		free(check);
	}
	free_split(path);
	perror(cmd[0]);
	return (NULL);
}

