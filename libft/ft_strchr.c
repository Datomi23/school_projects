/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:41:29 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/01/08 16:40:10 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	while (s[i])
	{
		ret = (char *)s + i;
		if (s[i] == (unsigned char)c)
			return (ret);
		i++;
	}
	ret = (char *)s + i;
	if (s[i] == '\0' && (unsigned char)c == s[i])
		return (ret);
	else
		return (NULL);
}
