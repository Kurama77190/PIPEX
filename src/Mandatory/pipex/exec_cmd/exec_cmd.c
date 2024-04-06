/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:13:44 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/06 17:15:21 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* ************************************ */
/*  🌟 CHECK_ABSOLUT_PATH_AND_EXEC 🌟  */
/* ************************************ */

int	ft_exec_cmd(char **argv, char **envp, int i)
{
	if (!ft_absolut_path_cmd(argv[i]))
	{
		// if (!envp[0])
		// {
		// 	ft_error_msg("Error: environement not found\n");
		// 	exit(EXIT_FAILURE);
		// }
		if (ft_search_path_cmd(argv, envp, i) == SUCCESS)
			return (SUCCESS);
		else
			return (ERROR);
	}
	else
	{
		if (ft_exec_real_path_cmd(argv, envp, i) == SUCCESS)
			return (SUCCESS);
		else
			return (ERROR);
	}
	return (SUCCESS);
}

/* ********************************* */
/*  🌟 EXECVE_WITH_ABSOLUT_PATH 🌟  */
/* ********************************* */

int	ft_exec_real_path_cmd(char **argv, char **envp, int i)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv[i], ' ');
	if (!cmd)
		return (ft_error_msg("Error split"), ERROR);
	path = argv[i];
	if (!path)
	{
		free_split(cmd);
		return (ERROR);
	}
	if (execve(path, cmd, envp) == ERROR)
		ft_error_msg("execve");
	free_split(cmd);
	return (SUCCESS);
}

/* *********************************** */
/*  🌟 SEARCH_PATH_CMD_FOR_EXECVE 🌟  */
/* *********************************** */

int	ft_search_path_cmd(char **argv, char **envp, int i)
{
	char	**cmd;
	char	*path;

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

/* **************************** */
/*  🌟 CHECKER_ABOSULT_CMD 🌟  */
/* **************************** */

bool	ft_absolut_path_cmd(char *argv)
{
	return (access(argv, F_OK) == SUCCESS && access(argv, X_OK) == SUCCESS);
}
