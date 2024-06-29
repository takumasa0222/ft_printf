/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:11:12 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/10 06:42:35 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	ret = (t_list *)malloc(1 * sizeof(t_list));
	if (!ret)
		return (NULL);
	current = ret;
	while (current)
	{
		current->content = (t_list *)f(lst->content);
		current->next = NULL;
		if (lst->next)
		{
			current->next = (t_list *)malloc(1 * sizeof(t_list));
			if (!current->next)
				return (ft_lstclear(&ret, del), NULL);
			lst = lst->next;
		}
		current = current->next;
	}
	return (ret);
}
