#include "../../includes/minishell.h"

void	free_array(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = 0;
	while(src[j])
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return(dest);
}
