/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:03 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/21 18:58:57 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/* *************************** */
/* 			MAIN PROGRAMME	   */
/* *************************** */

int main(int argc, char **argv, char **envp)
{
	// if (!envp || argc < 3)
	// {
	// 	return (1);
	// }
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
	printf("test function 'get_cmd' : %s", get_cmd(get_path(envp), "teste"));
	return 0;
}


/* *************************** */
/* 			NOTE PROJECT	   */
/* *************************** */

/*
	- PARSING ...
*/


/* *************************** */
/* 		COMMANDS TEST ERROR	   */
/* *************************** */

/*
	-
*/