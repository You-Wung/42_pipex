/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 23:58:55 by tyou              #+#    #+#             */
/*   Updated: 2021/01/09 15:15:59 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *ret;
	t_list *nxt;

	if (lst == NULL)
		return (NULL);
	if (!(nxt = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	ret = nxt;
	while (lst)
	{
		if (!(nxt = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&ret, del);
			ft_lstclear(&lst, del);
			break ;
		}
		ft_lstadd_back(&ret, nxt);
		lst = lst->next;
	}
	return (ret);
}
