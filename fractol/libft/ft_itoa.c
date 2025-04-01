/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:39:40 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/01/11 03:49:16 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	long	i;
	long	nb;

	nb = n;
	i = 0;
	if (nb > 0)
	{
		while (nb >= 1)
		{
			nb /= 10;
			i++;
		}
	}
	else
	{
		i = 1;
		while (nb < 0)
		{
			nb /= 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	y;
	long	z;

	if (n < 0)
	{
		y = n;
		y = -y;
	}
	else
		y = n;
	z = get_digits(n);
	str = malloc(sizeof(char) * (z + 1));
	if (!str)
		return (NULL);
	str[z--] = '\0';
	while (z >= 0)
	{
		str[z] = (y % 10) + 48;
		y /= 10;
		z--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
// int main()
// {
// 	printf("%s\n", ft_itoa(-13444));
// 	return (0);
// }
