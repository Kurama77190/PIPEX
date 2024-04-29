/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error_without_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:49:29 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/29 18:52:04 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* ******************************* */
/*  🌟 MSG_ERROR_WITHOUT_ENVP 🌟  */
/* ******************************* */

void	ft_error_permission_envp(char *cmd)
{
	char	**tmp;

	if (ft_strchr(cmd, ' ') != NULL)
	{
		tmp = ft_split(cmd, ' ');
		if (!cmd)
			return ;
		ft_dprintf(2, "env: ‘%s’: Permission denied\n", tmp[0]);
	}
	else
		ft_dprintf(2, "env: ‘%s’: Permission denied\n", cmd);
}

int	ft_error_cmd_envp(char *cmd)
{
	ft_dprintf(2, "env: ‘%s’: No such file or directory\n", cmd);
	return (ERROR);
}
