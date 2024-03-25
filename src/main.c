/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:03 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/23 16:04:59 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/* *************************** */
/* 			MAIN PROGRAMME	   */
/* *************************** */


int main (int argc, char **argv, char **envp)
{
	(void)argc;
	int infile;
	infile = open(argv[1], O_RDONLY);
	ft_pipex(infile, argv, envp);
	return 0;
}


// int main(int argc, char **argv, char **envp)
// {
// 	// if (!envp || argc != 5)
// 	// {
// 	// 	stderr("Error: Invalid arguments\n");
// 	// 	return (ERROR);
// 	// }
// 	(void)argc;
// 	(void)argv;
// 	char	*path;
// 	path = get_cmd(get_path(envp), argv, 1);
// 	printf("\n");
// 	printf("test function 'get_cmd' : %s", path);
// 	free(path);
// 	return 0;
// }

/* *************************** */
/* 		  NOTE PROJECT	       */
/* *************************** */

/*
	- PARSING ...
	- FOUND PATH OF ALL FUNCTION OK ! With get_cmd
	- 
*/


/* *************************** */
/* 		COMMANDS TEST ERROR	   */
/* *************************** */

/*
	-
*/
