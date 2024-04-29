/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:00:06 by sben-tay          #+#    #+#             */
/*   Updated: 2024/04/28 09:00:17 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_lstclear(t_pid **lst, void (*del)(void *))
{
	t_pid	*current;

	if (!del || !lst || !*lst)
		return ;
	while (lst != NULL && *lst != NULL)
	{
		current = (*lst)->next;
		free(*lst);
		*lst = current;
	}
}
