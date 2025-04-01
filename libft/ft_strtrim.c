/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:47:35 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/01/08 16:41:51 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		fin;
	char	*ret;

	start = 0;
	fin = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	if (s1[start] == '\0')
		return (ft_substr(s1, start, 0));
	while (ft_strchr(set, s1[fin - 1]) && fin > start)
		fin--;
	ret = ft_substr(s1, start, fin - start);
	return (ret);
}
