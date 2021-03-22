/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:47:21 by fcivetta          #+#    #+#             */
/*   Updated: 2020/11/24 15:20:48 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*alist;
	t_list	*new_list;
	t_list	*tmp_old_list;

	if (!lst || !f)
		return (NULL);
	tmp_old_list = lst;
	if (!(new_list = ft_lstnew(f(tmp_old_list->content))))
		return (NULL);
	alist = new_list;
	tmp_old_list = tmp_old_list->next;
	while (tmp_old_list)
	{
		if (!(new_list->next = ft_lstnew(f(tmp_old_list->content))))
		{
			ft_lstclear(&alist, del);
			return (NULL);
		}
		new_list = new_list->next;
		tmp_old_list = tmp_old_list->next;
	}
	return (alist);
}
