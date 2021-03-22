/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:34:15 by fcivetta          #+#    #+#             */
/*   Updated: 2020/11/17 11:31:09 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = src;
	i = 0;
	if (n > 0)
	{
		while (i < n)
			dest[i++] = 0;
	}
}
