/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:06:30 by fcivetta          #+#    #+#             */
/*   Updated: 2020/11/17 11:07:49 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = src;
	while (i < len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (src);
}
