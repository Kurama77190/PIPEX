/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:13:44 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/26 04:21:31 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* ************************************ */
/*  🌟 CHECK_ABSOLUT_PATH_AND_EXEC 🌟  */
/* ************************************ */

int	ft_exec_cmd(t_pipex *data, int i)
{
	if (!ft_absolut_path_cmd(data->argv[i]))
	{
		if (ft_search_path_cmd(data, i) == SUCCESS)
			return (SUCCESS);
	}
	if (ft_absolut_path_cmd(data->argv[i]))
	{
		if (ft_exec_absolut_path_cmd(data, i) == SUCCESS)
			return (SUCCESS);
	}
	return (ERROR);
}

/* ********************************* */
/*  🌟 EXECVE_WITH_ABSOLUT_PATH 🌟  */
/* ********************************* */

int	ft_exec_absolut_path_cmd(t_pipex *data, int i)
{
	data->cmd = ft_split(data->argv[i], ' ');
	if (data->cmd == NULL)
		return (ERROR);
	data->path = data->argv[i];
	if (data->path == NULL)
	{
		free_split(data->cmd);
		return (ERROR);
	}
	if (execve(data->cmd[0], data->cmd, data->envp) == ERROR)
	{
		ft_error_msg("execve");
		free_split(data->cmd);
		return (ERROR);
	}
	return (SUCCESS);
}

/* *********************************** */
/*  🌟 SEARCH_PATH_CMD_AND_EXECVE 🌟  */
/* *********************************** */

int	ft_search_path_cmd(t_pipex *data, int i)
{
	if (ft_only_space(data->argv[i]) || data->argv[i][0] == '\0')
		return (ERROR);
	if (data->argv[i][0] == '/')
	{
		if (access(data->argv[i], F_OK) == SUCCESS)
			exit(126);
		exit(127);
	}
	data->cmd = ft_split(data->argv[i], ' ');
	if (data->cmd[0] == NULL)
		return (ft_error_msg("Error split"), ERROR);
	data->path = get_cmd(data, i);
	if (data->path == NULL)
	{
		free_split(data->cmd);
		exit(127);
	}
	if (execve(data->path, data->cmd, data->envp) == ERROR)
	{
		free(data->path);
		free_split(data->cmd);
		ft_error_msg("execve");
		return (ERROR);
	}
	return (SUCCESS);
}

/* **************************** */
/*  🌟 CHECKER_ABOSULT_CMD 🌟  */
/* **************************** */

bool	ft_absolut_path_cmd(char *argv)
{
	char	**tmp;

	if (argv[0] == '\0')
		return (false);
	tmp = ft_split(argv, ' ');
	if (tmp == NULL)
		return (NULL);
	if (access(tmp[0], F_OK) == SUCCESS)
	{
		if (access(tmp[0], X_OK) == SUCCESS)
			return (free_split(tmp), true);
	}
	free_split(tmp);
	return (false);
}
