/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcivetta <fcivetta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:37:38 by fcivetta          #+#    #+#             */
/*   Updated: 2020/11/26 14:20:23 by fcivetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*trim;

	i = 0;
	trim = NULL;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != NULL && i < len)
		i++;
	while ((ft_strrchr(set, s1[len]) != NULL) && len > i)
		len--;
	trim = ft_substr(s1, i, len - i + 1);
	return (trim);
}
