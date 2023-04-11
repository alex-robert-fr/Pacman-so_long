/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:45:57 by alrobert          #+#    #+#             */
/*   Updated: 2022/10/25 17:44:29 by alrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst != NULL)
	{
		if (!list)
			list = ft_lstnew(f(lst->content));
		else
		{
			tmp = ft_lstnew(f(lst->content));
			if (!tmp)
				ft_lstclear(&list, del);
			ft_lstadd_back(&list, tmp);
		}
		lst = lst->next;
	}
	return (list);
}
