/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:03 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/26 17:08:39 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/* *************************** */
/* 			MAIN PROGRAMME	   */
/* *************************** */


int main (int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_error_msg("Error: expected 4 arguments\n");
		exit(EXIT_FAILURE);
	}
	if (!envp[0])
	{
		ft_error_msg("Error: environement not found\n");
		exit(EXIT_FAILURE);
	}
	// printf("PATH CMD1 : %s", get_cmd(argv, envp, 2));
	// return (9);
	ft_pipex(argc, argv, envp);
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
	- COMMANDS CHECK FILE DESCRIPTOR OPEN OR CLOSE : valgrind --track-fds=yes --trace-children=yes.
	- IMPLEMENT 2 CHILDREN. THEN GO IMPLEMENT BONUS PARTY.

*/


/* *************************** */
/* 		COMMANDS TEST ERROR	   */
/* *************************** */

/*
	-
*/
