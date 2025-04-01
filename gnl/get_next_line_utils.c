/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi < dadeyemi@student.42firenze.i    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:32:03 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/02/08 16:42:51 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s == NULL || start > s_len || len == 0)
		return (NULL);
	if (len > s_len || len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len + 1)
		ptr[i++] = '\0';
	i = 0;
	while (i < len && s[start] != '\0')
	{
		ptr[i++] = s[start];
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, const char *s2)
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
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	if (!s)
		return (NULL);
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

char	*ft_substr_free(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s == NULL || start > s_len)
		return (NULL);
	if (len > s_len || len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < len + 1)
		ptr[i++] = '\0';
	i = 0;
	while (i < len && s[start] != '\0')
	{
		ptr[i++] = s[start];
		start++;
	}
	ptr[i] = '\0';
	free((char *)s);
	s = ptr;
	return (ptr);
}
