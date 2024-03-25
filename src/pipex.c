/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:52:24 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/23 16:06:05 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_pipex(int infile, char **argv, char **envp)
{
    int fd[2]; // Pour pipe
    char **cmd1;
    // char **cmd2;
    char *path_cmd1;
    // char *path_cmd2;
    pipe(fd);
    if (fork() == 0)
    {
        dup2(infile, STDOUT_FILENO); // Rediriger stdout vers le pipe
        close(fd[0]); // Fermer l'extrémité de lecture
        cmd1 = ft_split(argv[3], ' '); // Diviser la commande 1 en mots
        path_cmd1 = get_cmd(get_path(envp), cmd1); // Trouver le chemin de la commande 1
        execve(path_cmd1, cmd1, envp); // Exécuter cmd1
    }
    free_split(cmd1);
    free(path_cmd1);
    return (SUCCESS);
}
