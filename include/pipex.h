/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:06 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/29 14:59:48 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../external/DPRINTF/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERROR -1
# define SUCCESS 0

typedef struct s_pid
{
	pid_t			pid;
	int				status;
	struct s_pid	*next;
}					t_pid;

typedef struct s_pipex
{
	int				fd[2];
	int				fd_in;
	int				fd_out;
	int				argc;
	int				return_exit_code;
	int				fdout_no_w;
	char			**cmd;
	char			**argv;
	char			**envp;
	char			*path;
	pid_t			pid_tmp;
	t_pid			*data_pid;
}					t_pipex;

/*============================__FT_PIPEX__============================*/

void	check_fd_out_writable(t_pipex *data);

void	ft_setup_status_pid(t_pipex *data);

char	**get_path(t_pipex *data);

char	*get_cmd(t_pipex *data, int i);

int		ft_pipex(t_pipex *data);

int		ft_setup_first_children(t_pipex *data, int i);

int		ft_setup_last_children(t_pipex *data, int i);

int		ft_exec_cmd(t_pipex *data, int i);

int		ft_search_path_cmd(t_pipex *data, int i);

int		ft_exec_absolut_path_cmd(t_pipex *data, int i);

/*============================__LIB_FT__============================*/

void	ft_lstclear(t_pid **lst, void (*del)(void *));

void	ft_add_pid(t_pipex *data, pid_t new_pid);

char	*ft_strchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	**ft_split_envp(char const *s, char c);

char	**ft_split(char const *s, char c);

char	*ft_strjoin(char *s1, char *s2);

void	free_split(char **strs);

void	ft_putstr_fd(char *s, int fd);

bool	ft_only_space(char *str);

/*============================__MSG_ERROR__============================*/

void	*ft_memset(void *b, int c, size_t len);

void	ft_error_cmd(char *cmd);

void	ft_error_permission(char *cmd);

void	ft_error_file_directory(char *cmd);

int		ft_error_msg(char *msg_error);

void	ft_error_arguments(void);

/*=====================__INITIALIZING_STRUCTURE__=====================*/

void	initializing_data(t_pipex *data, int argc, char **argv, char **envp);

#endif