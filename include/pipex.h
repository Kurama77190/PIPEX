/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:06 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/04 18:13:35 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../include/pipex.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ERROR -1
#define SUCCESS 0

/*============================__FT_PIPEX__================================*/

char	**get_path(char **envp);

char    *get_cmd(char **argv, char **envp, int i);

int		ft_pipex(int argc, char **argv, char **envp);

void	ft_error_msg(char *msg_error);

void	ft_error_msg_pross(char *msg_error);

int	ft_exec_first_cmd(char **argv, char **envp, int fd[], int i);

int	ft_exec_last_cmd(int argc, char **argv, char **envp, int fd[], int i);

int	ft_exec_cmd(char **argv, char **envp, int i);

int ft_not_real_path(char **argv, char **envp, int i);

int	ft_real_path(char **argv, char **envp, int i);

bool	ft_path_exist(char *argv);

void	ft_error_msg(char *msg_error);

void	ft_error_msg_pross(char *msg_error);;


/*============================__LIB_FT__============================*/

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	**ft_split_envp(char const *s, char c);

char	**ft_split(char const *s, char c);

size_t	ft_strlen(char *str);

char	*ft_strjoin(char *s1, char *s2);

void	free_split(char **strs);

void	ft_putstr_fd(char *s, int fd);

#endif