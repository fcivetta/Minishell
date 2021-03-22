/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:13:32 by fcivetta          #+#    #+#             */
/*   Updated: 2020/11/26 14:21:12 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char*)haystack;
	if (needle[i] == '\0')
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == needle[j])
		{
			while (str[i + j] == needle[j] && str[i + j] && i + j < len)
			{
				if (needle[j + 1] == '\0')
					return (str + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
