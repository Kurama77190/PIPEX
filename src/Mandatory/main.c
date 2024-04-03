/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:03 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/03 17:06:41 by sben-tay         ###   ########.fr       */
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
		ft_putstr_fd("Error: expected 4 arguments\n", 2);
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
	- ESTEREGG : 42 | "ma tete va serrer."
	- PARSING OK ! NEED TO STORE AND SORT THE FUNCTIONS
	02/04/24
	- REDIRECTION : OK
	- ERREUR ARGUMENTS OK
	- MEMORY LEAKS CHILD AND FD OK
	- GOOD MESSAGE ERROR ... IN WORKING
*/


/* *************************** */
/* 		COMMANDS TEST ERROR	   */
/* *************************** */

/*
	- Comparer le comportement de mon pipex avec le comportement de : bash --posix 
	- Comparer le comportement de mon pipex sans l'environement et de PATH :env -i | unset PATH
	- le meilleur teste de comportement : ./pipex /dev/stdin ls cat /dev/stdout
*/
