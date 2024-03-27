/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:55:41 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/27 17:21:19 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	msg_free_error(char **commands, char **path);
static void	msg_free_success(char **commands, char **path);

char *get_cmd(char **argv, char **envp, int i)
{
	char	**path;
	char	*cmd_path;
	char	**commands;
	int		index_tab;
	
	index_tab = 0;
	if ((commands = ft_split(argv[i], ' ')) == NULL)
		return (free_split(commands), NULL);
	if ((path = get_path(envp)) == NULL)
		return (NULL);
	while(path[index_tab])
	{
		cmd_path = ft_strjoin(path[index_tab], commands[0]);
		if (access(cmd_path, F_OK) == SUCCESS && access(cmd_path, X_OK) == SUCCESS)
				return (msg_free_success(commands, path), cmd_path);
		index_tab++;
		free(cmd_path);
	}	
	msg_free_error(commands, path);
	return NULL;
}

static void	msg_free_error(char **commands, char **path)
{
	perror(commands[0]);
	free_split(commands);
	free_split(path);
}

static void	msg_free_success(char **commands, char **path)
{
	free_split(commands);
	free_split(path);
}











// static void	free_path_perror(char **path, char *cmd);
// satic void	free_path_cmd_success(char **cmd_, char **path);

// char *get_cmd(char **path, char **cmd, int i)
// {
// 	int		index;
// 	char	*path_cmd;
// 	char	**cmd_;

// 	cmd_ = ft_split(cmd[i], ' ');
// 	index = 0;
// 	if (!path)
// 		return NULL;
// 	while(path[index])
// 	{
// 		path_cmd = ft_strjoin(path[index], cmd_[0]);
// 		if (access(path_cmd, F_OK) == SUCCESS)
// 		{
// 			if(access(path_cmd, X_OK) == SUCCESS)
// 			{
// 				free_path_cmd_success(cmd_, path);
// 				return (path_cmd);
// 			}
// 		}
// 		index ++;
// 		free(path_cmd);
// 	}
// 	free_path_perror(path, cmd);
// 	return (NULL);
// }

// static void	free_path_perror(char **path, char *cmd)
// {
// 	free_split(path);
// 	perror(cmd);
// }

// static void	free_path_cmd_success(char **cmd_, char **path)
// {
// 	free_split(cmd_);
// 	free_split(path);
// }