/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:03 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/12 18:44:05 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipex(t_pipex data);

/* ********************* */
/* ⚙️ MAIN PROGRAMME ⚙️ */
/* ********************* */

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		return (ft_error_arguments(), 1);
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	ft_pipex(data);
	return (0);
}

/* ********************* */
/* 🥇 MAIN PROGRAMME 🥇 */
/* ********************* */

int	ft_pipex(t_pipex data)
{
	int		pipe;
	int		i;
	int		status;

	i = 2;
	pipe = 77190;
	while (i <= data.argc - 2 && pipe != ERROR)
	{
		if (i == 2)
			pipe = ft_setup_first_children(&data, i);
		if (i == data.argc - 2)
		{
			pipe = ft_setup_last_children(&data, i);
			break ;
		}
		// else
			// pipe = ft_setup_children(&data, i);
		i++;
	}
	while (wait(&status) > 0)
		;
	return (0);
}

/* **************** */
/*   NOTE PROJECT   */
/* **************** */

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
	- CHECK ALL MEMORY LEAKS... STARTING.
	- IMPLEMENT MULTI PIPE CHILDREN... STARTING.
	- IMPLEMENT
	
*/


/* *************************** */
/* 		COMMANDS TEST ERROR	   */
/* *************************** */

/*
	- Comparer le comportement de mon pipex avec le comportement de : bash --posix 
	- Comparer le comportement de mon pipex sans l'environement et de PATH :env -i | unset PATH
	- le meilleur teste de comportement : ./pipex /dev/stdin ls cat /dev/stdout
	- < /dev/stdin cat | cat > ./pipex = Comportement inatendu.
*/

/* *************************** */
/* 		NOTE MINISHELL 		   */
/* *************************** */

/*
	- EXPORT SANS ARGUMENTS EST UN COMPORTEMENT INDEFENIE (voir la dock exort)
*/

/* *************************** */
/* 		NOTE EARDOCK		   */
/* *************************** */

/*
	- EARDOCK CEST UN INFILE OUVERT DANS LE TERMINAL
	- LE EARDOCK DE PIPEX N EST PAS BON POUR MINISHELL !
	
*/