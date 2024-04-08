/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:55:41 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/08 18:59:07 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// LAST FOLDER FOR STORING THE FUNCTIONS RELATED TO THE PATH

// static void	msg_free_error(char **commands, char **path);
static void	free_success(char **commands, char **path);
static bool	access_success(char *cmd_path);

char	**get_path(char **envp)
{
	int		i;
	char	*env;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == SUCCESS)
		{
			env = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (envp[i] == NULL)
		return (NULL);	
	else
		path = ft_split_envp(env, ':');
	if (!path)
		return (NULL);
	return (path);
}

char	*get_cmd(char **argv, char **envp, int i)
{
	char	**path;
	char	*cmd_path;
	char	**commands;
	int		index_tab;

	index_tab = 0;
	commands = ft_split(argv[i], ' ');
	if (commands == NULL)
		return (NULL);
	path = get_path(envp);
	if (!path)
		return (free_split(commands), NULL);
	while (path[index_tab])
	{
		cmd_path = ft_strjoin(path[index_tab], commands[0]);
		if (access_success(cmd_path))
			return (free_success(commands, path), cmd_path);
		index_tab++;
		free(cmd_path);
	}
	ft_error_cmd(commands, path);
	return (NULL);
}

static bool	access_success(char *cmd_path)
{
	if (access(cmd_path, F_OK) == SUCCESS && \
		access(cmd_path, X_OK) == SUCCESS)
		return (true);
	return (false);
}

// static void	msg_free_error(char **commands, char **path)
// {
// 	perror(commands[0]);
// 	free_split(commands);
// 	free_split(path);
// }

static void	free_success(char **commands, char **path)
{
	free_split(commands);
	free_split(path);
}
