/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:13:44 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/15 18:18:37 by sben-tay         ###   ########.fr       */
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
		if (ft_search_path_cmd(data, i) == ERROR)
			return (ERROR);
	}
	if (ft_absolut_path_cmd(data->argv[i]))
	{
		if (ft_exec_absolut_path_cmd(data, i) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
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
	}
	return (SUCCESS);
}

/* *********************************** */
/*  🌟 SEARCH_PATH_CMD_AND_EXECVE 🌟  */
/* *********************************** */

int	ft_search_path_cmd(t_pipex *data, int i)
{
	if (data->envp[0] == NULL)
		return (ft_error_msg(data->argv[i]), ERROR);
	data->cmd = ft_split(data->argv[i], ' ');
	if (data->cmd[0] == NULL)
		return (ft_error_msg("Error split"), ERROR);
	data->path = get_cmd(data, i);
	if (data->path == NULL)
	{
		free_split(data->cmd);
		return (ERROR);
	}
	if (execve(data->path, data->cmd, data->envp) == ERROR)
	{
		free_split(data->cmd);
		free(data->path);
		ft_error_msg("execve");
	}
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
		return (NULL);
	if (access(tmp[0], F_OK) == SUCCESS)
		if (access(tmp[0], X_OK) == SUCCESS)
			return (free_split(tmp), true);
	return (false);
}
