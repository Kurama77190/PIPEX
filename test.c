/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:58:59 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/27 01:28:33 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/samy/42projet/PIPEX/include/pipex.h"


static size_t	ft_strlen_join(const char *str);

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		if (write(fd, &s[i], 1) == -1)
			return ;
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t			i;
	size_t			j;
	char			*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * \
	(ft_strlen_join(s1) + ft_strlen_join(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	ft_strlen_join(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


void	ft_error_cmd(char *cmd)
{
	char	*tmp;
	char	*msg;

	tmp = ft_strjoin("bash: ", cmd);
	if (!tmp)
		return ;
	msg = ft_strjoin(tmp, ": command not found\n");
	if (!msg)
	{
		free(tmp);
		return ;
	}
	ft_putstr_fd(msg, 2);
	free(tmp);
	free(msg);
}

int main(void)
{
    char    *cmd = "caca";
        ft_error_cmd(cmd);
    char *check_in_source = ft_strjoin("./", "test");
    if (access(check_in_source, F_OK) == SUCCESS)
        printf("OK!\n");
}
