/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:06:52 by fcivetta          #+#    #+#             */
/*   Updated: 2020/11/25 09:22:50 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	long		nb;

	i = 1;
	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	while (nb / i >= 10)
		i = i * 10;
	while (i != 0)
	{
		ft_putchar_fd(nb / i + 48, fd);
		nb = nb % i;
		i = i / 10;
	}
}
