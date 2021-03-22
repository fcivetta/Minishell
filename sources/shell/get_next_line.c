#include "../../includes/minishell.h"

int		ft_linelen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}

int		append_next_line(char **str, int fd, char **line)
{
	int		len;
	char	*tmp;

	len = ft_linelen(str[fd]);
	if (str[fd][len] == '\n')
	{
		if (!(*line = ft_substr(str[fd], 0, len)))
			return (-1);
		if (!(tmp = ft_strdup(str[fd] + len + 1)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	return (1);
}

int		return_value_get_next_line(int ret, char **str, int fd, char **line)
{
	if (ret < 0)
		return (-1);
	else if (str[fd] == NULL && ret == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (append_next_line(str, fd, line));
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	static char		*str[FD_SIZE];
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while (((ret = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[ret] = '\0';
		if (str[fd] == NULL)
		{
			if (!(str[fd] = ft_strdup(buff)))
				return(-1);
		}
		else
		{
			if (!(tmp = ft_strjoin(str[fd], buff)))
				return (-1);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (return_value_get_next_line(ret, str, fd, line));
}
