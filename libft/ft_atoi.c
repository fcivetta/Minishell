/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:44:43 by fcivetta          #+#    #+#             */
/*   Updated: 2020/11/24 15:32:49 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	nb;
	int			sign;
	int			i;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = str[i] == '-' ? -sign : sign;
		i++;
	}
	if (str[i] && (str[i] < 48 || 57 < str[i]))
		return (0);
	while (48 <= str[i] && str[i] <= 57)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (sign * nb);
}
