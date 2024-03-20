/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:03 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/20 18:48:15 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	int i = 0;
	char	**path;
	path = get_path(envp);
	printf("voici mon path_spliter :\n");
	while (path[i])
	{
		printf("%s\n", path[i]);
		i++;
	}
	printf("\n");
	return 0;
}
