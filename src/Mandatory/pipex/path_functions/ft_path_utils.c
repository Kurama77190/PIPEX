/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:13:44 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/04 11:21:51 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	ft_real_path(char **argv, char **envp, int i);
int ft_not_real_path(char **argv, char **envp, int i);

int	ft_real_path(char **argv, char **envp, int i)
{
	char *path;
	char **cmd;

	cmd = ft_split(argv[i], ' ');
	if (!cmd)
		return (ft_error_msg("Error split"), ERROR);
	path = argv[i];
	if (!path)
	{
		free_split(cmd);
		exit (1);
		return (ERROR);
	}
	if (execve(path, cmd, envp) == ERROR)
	{
		free_split(cmd);
		free(path);
		ft_error_msg("execve");
	}
	free_split(cmd);
	return (SUCCESS);
}

int ft_not_real_path(char **argv, char **envp, int i)
{
	char **cmd;
	char *path;
	
	cmd = ft_split(argv[i], ' ');
	if (!cmd)
		return (ft_error_msg("Error split"), ERROR);
	path = get_cmd(argv, envp, i);
	if (!path)
	{
		free_split(cmd);
		exit(1);
		return (ERROR);
	}
	if (execve(path, cmd, envp) == ERROR)
	{
		free_split(cmd);
		free(path);
		ft_error_msg("execve");
	}
	free_split(cmd);
	free(path);
	return (SUCCESS);
}
