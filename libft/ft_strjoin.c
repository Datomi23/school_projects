/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:41:39 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/01/08 16:40:22 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		k;
	int		len1;

	len1 = ft_strlen(s1);
	i = 0;
	k = 0;
	str = (char *)malloc((ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (!str)
		return (NULL);
	while (s1[i] && i <= len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k] && i >= len1)
	{
		str[i] = s2[k++];
		i++;
	}
	str[i] = '\0';
	if (!str)
		return (NULL);
	return (str);
}
