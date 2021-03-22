/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:57:57 by fcivetta          #+#    #+#             */
/*   Updated: 2021/02/25 16:34:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

static int	ft_count_wd(const char *s, char c)
{
	int	new_wd;
	int	wd;

	new_wd = 0;
	wd = 0;
	while (*s)
	{
		if (*s == c && new_wd == 1)
			new_wd = 0;
		if (*s != c && new_wd == 0)
		{
			new_wd = 1;
			wd++;
		}
		s++;
	}
	return (wd);
}

char		**ft_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		start;
	int		buff;

	if (!s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (ft_count_wd(s, c) + 1))))
		return (NULL);
	buff = 0;
	i = -1;
	while (++i < ft_count_wd(s, c))
	{
		while (*(s + buff) && *(s + buff) == c)
			buff++;
		start = buff;
		while (*(s + buff) && *(s + buff) != c)
			buff++;
		if (!(res[i] = (char *)malloc(sizeof(char) * (buff - start + 1))))
			return (free_all(res));
		ft_strlcpy(res[i], (char *)(s + start), buff - start + 1);
		buff++;
	}
	res[i] = NULL;
	return (res);
}
