/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:55:41 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/26 01:22:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// LAST FOLDER FOR STORING THE FUNCTIONS RELATED TO THE PATH

static int	checker_access(char *cmd_path, char **commands, char **path_env);

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
		if (checker_access(cmd_path, commands, path_env) == SUCCESS)
			return (cmd_path);
		index_tab++;
		free(cmd_path);
	}
	free_split(commands);
	free_split(path_env);
	return (NULL);
}

static int	checker_access(char *cmd_path, char **commands, char **path_env)
{
	if (access(cmd_path, F_OK) == SUCCESS)
	{
		if (access(cmd_path, X_OK) == ERROR)
		{
			free(cmd_path);
			free_split(commands);
			free_split(path_env);
			exit(126);
		}
		free_split(commands);
		free_split(path_env);
		return (SUCCESS);
	}
	else
		return (ERROR);
}
