/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:03 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/26 01:08:19 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* ********************* */
/* ⚙️ MAIN PROGRAMME ⚙️ */
/* ********************* */

char	**get_path(t_pipex *data);

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
		return (ft_error_arguments(), 1);
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
	data.cmd = NULL;
	data.path = NULL;
	return (ft_pipex(data));
}

/* ********************* */
/*   🥇 MAIN PIPEX 🥇   */
/* ********************* */

int	ft_pipex(t_pipex data)
{
	int		pipe;
	int		i;
	int		status;
	size_t	index_pid;

	i = 2;
	pipe = 77190;
	index_pid = 0;
	while (i <= data.argc - 2 && pipe != ERROR)
	{
		if (i == 2)
			pipe = ft_setup_first_children(&data, i, index_pid);
		if (i == (data.argc - 2))
		{
			pipe = ft_setup_last_children(&data, i, index_pid);
			break ;
		}
		index_pid++;
		i++;
	}
	while (wait(&status) > 0)
	{
		if (WIFEXITED(status))
			data.return_code = WEXITSTATUS(status);
		// printf("Exit status: %d\n", data.return_code);
	}
	return (data.return_code);
}

/* **************** */
/*   NOTE PROJECT   */
/* **************** */

/*
	- PARSING ...
	- FOUND PATH OF ALL FUNCTION OK ! With get_cmd
	- COMMANDS CHECK FILE DESCRIPTOR OPEN OR CLOSE :valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all 
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
	- TODO: CHANGER WAIT PAR WAIT PID. LES ENFANTS NE S ATTENDS PAS. RISQUE DE SUPERPOSITION.
	- FIXME: OK ! WAITPID IMPLEMENTED.

	- TODO: EXECVE LIBERE LA MEMOIRE DES POINTEURS DONNER EN PARAMETRE, ADAPTER LE CODE EN CONSEQUENCES
	- FIXME: EXECVE NE LIBERE PAS LA MEMOIRE DES PARAMETRES DONNER ! ATTENTION ! FIXED.

	
	- TODO: WRITE LES MESSAGES D ERREUR DANS STDERR
	- FIXME: FIXED
	
	- TODO: GERER LE CAS OU LES CMD SONT VIDES (WHITESPACE) ou NULL
	- FIXME: FIXED
	
	- TODO: GERER LE CAS OU LES CMD N ONT PAS LES DROITS D EXECUSSION CODE EXIT (126)
	- FIXME: EN COURS...

	- TODO: GERER LE CODE ERREUR QUAND L ENVIRONEMENT EST VIDE
	- FIXME: EN COURS...

	- TODO: GERER LE CAS DE CETTE COMMANDE :./pipex Makefile yes cati outf
	- FIXME: EN COURS...
	
	- TODO: RESTRUCTURER LES FONCTIONS PROCESSUS DE CHILDREN.C
	- FIXME: EN COURS...
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