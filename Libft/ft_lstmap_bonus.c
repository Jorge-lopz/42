/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorlopez <jorlopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:25:54 by jorlopez          #+#    #+#             */
/*   Updated: 2024/09/29 14:25:54 by jorlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (NULL);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew((*f)(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
