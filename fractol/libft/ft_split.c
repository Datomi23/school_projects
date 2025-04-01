/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:38:35 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/01/08 16:40:05 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_conta_str(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static int	cont_l(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	p;
	char	**arr_arr;

	i = 0;
	k = 0;
	p = 0;
	arr_arr = (char **)malloc(sizeof(char *) * (ft_conta_str(s, c) + 1));
	while (s[p] != '\0')
	{
		while (s[p] == c)
			p++;
		if (s[p] != c && s[p] != '\0')
		{
			arr_arr[i] = (char *)malloc(sizeof(char)
					*(cont_l((s + p), c) + 1));
			while (s[p] != c && s[p] != '\0')
				arr_arr[i][k++] = s[p++];
			arr_arr[i++][k] = '\0';
			k = 0;
		}
	}
	arr_arr[i] = NULL;
	return (arr_arr);
}

	// if (!s || !arr_arr)
	// 	return (NULL);
	// 		if (!arr_arr[i])
	// 			{
	// 				while (i > 0)
	// 					free(arr_arr[--i]);
	// 				free(arr_arr);
	// 				return (NULL);
	// 			}