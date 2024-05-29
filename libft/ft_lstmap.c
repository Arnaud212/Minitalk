/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:40:05 by agiraud           #+#    #+#             */
/*   Updated: 2021/06/10 17:04:25 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*begin;

	if (lst)
	{
		tmp = lst;
		begin = ft_lstnew(f(tmp->content));
		if (begin == NULL)
			return (NULL);
		tmp = tmp->next;
		while (tmp)
		{
			new = ft_lstnew(f(tmp->content));
			if (new == NULL)
			{
				ft_lstclear(&begin, del);
				return (NULL);
			}
			ft_lstadd_back(&begin, new);
			tmp = tmp->next;
		}
		return (begin);
	}
	return (NULL);
}
