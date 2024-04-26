/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:03 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/26 04:23:57 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* ********************* */
/* ⚙️ MAIN PROGRAMME ⚙️ */
/* ********************* */

void	print_error_msg(t_pipex *data, int i, int index_pid);

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
	int		index_pid;

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
	i = 2;
	index_pid = 0;
	while (index_pid < (data.argc - 3))
	{
		print_error_msg(&data, i, index_pid);
		index_pid++;
		i++;
	}
	return (data.return_code);
}

void	print_error_msg(t_pipex *data, int i, int index_pid)
{
	int		status;

	waitpid(data->pid[index_pid], &status, 0);
	if (WIFEXITED(status))
	{
		data->return_code = WEXITSTATUS(status);
		if (data->return_code == 126)
			ft_error_permission(data->argv[i]);
		else if (data->return_code == 127)
			ft_error_cmd(data->argv[i]);
	}
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