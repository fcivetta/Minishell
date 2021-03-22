/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:19:52 by fcivetta          #+#    #+#             */
/*   Updated: 2020/11/24 15:23:45 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_del;
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	to_del = *lst;
	tmp = to_del;
	while (to_del != NULL)
	{
		tmp = to_del->next;
		del(to_del->content);
		free(to_del);
		to_del = tmp;
	}
	*lst = NULL;
}
