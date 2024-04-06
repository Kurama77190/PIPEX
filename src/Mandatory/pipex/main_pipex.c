/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:52:24 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/06 16:47:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* ********************* */
/* 🥇 MAIN PROGRAMME 🥇 */
/* ********************* */

int	ft_pipex(t_pipex data)
{
	int		pipe;
	int		i;

	i = 1;
	pipe = 77190;
	while (i++ < data.argc - 2 && pipe != ERROR)
	{
		if (i == 2)
			pipe = ft_setup_first_children(&data, i);
		else
			pipe = ft_setup_last_children(&data, i);
	}
	while (wait(data.status) > 0)
		;
	return (0);
}

// else if (i > 2 && i < argc - 2)
// 	ft_exec_multi_cmd(argv, emvp, fd, i);