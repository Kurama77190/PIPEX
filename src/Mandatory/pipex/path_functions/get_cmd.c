/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:55:41 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/15 21:43:44 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// LAST FOLDER FOR STORING THE FUNCTIONS RELATED TO THE PATH

static void	free_success(char **commands, char **path);
static bool	access_success(char *cmd_path);

char	**get_path(t_pipex *data)
{
	int		i;
	char	*env;
	char	**path_;

	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], "PATH", 4) == SUCCESS)
		{
			env = data->envp[i] + 5;
			break ;
		}
		i++;
	}
	if (data->envp[i] == NULL)
		return (NULL);
	else
		path_ = ft_split_envp(env, ':');
	if (path_ == NULL)
		return (NULL);
	return (path_);
}

char	*get_cmd(t_pipex *data, int i)
{
	char	**path_env;
	char	*cmd_path;
	char	**commands;
	int		index_tab;

	index_tab = 0;
	commands = ft_split(data->argv[i], ' ');
	if (commands == NULL)
		return (NULL);
	path_env = get_path(data);
	if (path_env == NULL)
		return (free_split(commands), NULL);
	while (path_env[index_tab])
	{
		cmd_path = ft_strjoin(path_env[index_tab], commands[0]);
		if (access_success(cmd_path))
			return (free_success(commands, path_env), cmd_path);
		index_tab++;
		free(cmd_path);
	}
	free_split(commands);
	free_split(path_env);
	return (NULL);
}

static bool	access_success(char *cmd_path)
{
	if (access(cmd_path, F_OK) == SUCCESS && \
		access(cmd_path, X_OK) == SUCCESS)
		return (true);
	return (false);
}

static void	free_success(char **commands, char **path)
{
	free_split(commands);
	free_split(path);
}
