/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:14:01 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/01/10 22:16:37 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			(*new).next = *lst;
		*lst = new;
	}
}
// int main()
// {
// 	t_list *list;
// 	t_list *new;

// 	list = ft_lstnew("ciao");
// 	new = ft_lstnew("mondo");
// 	ft_lstadd_front(&list, new);
// 	printf("%s\n", list->content);
// 	printf("%s\n", list->next->content);
// 	return (0);
// }
