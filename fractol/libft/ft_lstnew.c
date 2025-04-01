/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 10:07:46 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/01/10 22:16:42 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
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
