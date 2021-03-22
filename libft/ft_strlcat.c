/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:44:39 by fcivetta          #+#    #+#             */
/*   Updated: 2020/11/23 16:19:38 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_strlen(char *str, size_t dstsize)
{
	size_t i;

	i = 0;
	while (str[i] && i < dstsize)
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_size_strlen(dst, dstsize) + ft_strlen(src);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[i])
		i++;
	while (i + j < dstsize - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (len);
}
