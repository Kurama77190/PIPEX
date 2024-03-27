/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:04:01 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/27 15:53:36 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **get_path(char **envp)
{
	int		i;
	char	*env;
	char	**path;
	if (!envp[0])
		return NULL;
	i = 0;
	while(envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == SUCCESS)
		{
			env = envp[i] + 5;
			break ;
		}
		i++;
	}
	path = ft_split_envp(env, ':');
	if (!path)
	{
		free(path);	
		return NULL;
	}
	return (path);
}

// fonction qui verifie si dans cmd1 et cmd2 se trouve le path exact si envp est NULL (env - i).
