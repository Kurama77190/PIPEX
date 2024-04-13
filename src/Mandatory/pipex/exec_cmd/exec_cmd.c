/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:13:44 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/12 23:18:57 by sben-tay         ###   ########.fr       */
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
		if (ft_search_path_cmd(argv, envp, i) == ERROR)
			return (ERROR);
	}
	if (ft_absolut_path_cmd(argv[i]))
	{
		if (ft_exec_absolut_path_cmd(argv, envp, i) == ERROR)
			return (ERROR);	
	}
	return (SUCCESS);
}

/* ********************************* */
/*  🌟 EXECVE_WITH_ABSOLUT_PATH 🌟  */
/* ********************************* */

int	ft_exec_absolut_path_cmd(char **argv, char **envp, int i)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv[i], ' ');
	if (!cmd)
		return (ERROR);
	path = argv[i];
	if (!path)
	{
		free_split(cmd);
		return (ERROR);
	}
	if (execve(cmd[0], cmd, envp) == ERROR)
		ft_error_msg("execve");
	free_split(cmd);
	return (SUCCESS);
}

/* *********************************** */
/*  🌟 SEARCH_PATH_CMD_AND_EXECVE 🌟  */
/* *********************************** */

int	ft_search_path_cmd(char **argv, char **envp, int i)
{
	char	**cmd;
	char	*path;

	if (!envp[0])
		return (ft_error_msg(argv[i]), ERROR);
	cmd = ft_split(argv[i], ' ');
	if (!cmd)
		return (ft_error_msg("Error split"), ERROR);
	path = get_cmd(argv, envp, i);
	if (!path)
	{
		free_split(cmd);
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
	char	**tmp;

	tmp = ft_split(argv, ' ');
	if (!tmp)
		return NULL;
	if (access(tmp[0], F_OK) == SUCCESS)
		if (access(tmp[0], X_OK) == SUCCESS)
			return (free_split(tmp), true);
	return (false);
}
