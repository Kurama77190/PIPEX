/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:03 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/29 19:12:33 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* ********************* */
/* ⚙️ MAIN PROGRAMME ⚙️ */
/* ********************* */

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		exit_code;

	if (argc != 5)
		return (ft_error_arguments(), 1);
	initializing_data(&data, argc, argv, envp);
	exit_code = ft_pipex(&data);
	ft_lstclear(&data.data_pid, free);
	return (exit_code);
}

/* ********************* */
/*   🥇 MAIN PIPEX 🥇   */
/* ********************* */

int	ft_pipex(t_pipex *data)
{
	int		pipe;
	int		i;

	i = 2;
	pipe = 77190;
	while (i <= (data->argc - 2) && pipe != ERROR)
	{
		if (i == 2)
			pipe = ft_setup_first_children(data, i);
		if (i == (data->argc - 2))
		{
			pipe = ft_setup_last_children(data, i);
			break ;
		}
		i++;
	}
	ft_setup_status_pid(data);
	return (data->return_exit_code);
}
