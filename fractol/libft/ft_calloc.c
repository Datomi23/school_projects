/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:39:02 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/01/08 16:37:51 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*array;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	i = nmemb * size;
	array = malloc(i);
	if (!array)
		return (0);
	else
		ft_bzero(array, i);
	return (array);
}
// int main()
// {
// 	char *str;
// 	char *str2;

// 	str = ft_calloc(0, 0);
// 	str2 = calloc(0, 0);
// 	printf("%s\n", str);
// 	printf("%s\n", str2);
// 	return (0);
// }