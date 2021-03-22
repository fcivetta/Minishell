/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:05:24 by fcivetta          #+#    #+#             */
/*   Updated: 2020/12/10 16:26:15 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lennb(long long n)
{
	int		len;

	len = 0;
	if (n < 0)
		len++;
	while (n % 10 != n)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(long long n)
{
	char		*ptr;
	long long	len;

	len = ft_lennb(n);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	ptr[len--] = '\0';
	while (n % 10 != n)
	{
		ptr[len--] = n % 10 + 48;
		n = n / 10;
	}
	ptr[len] = n + 48;
	return (ptr);
}
