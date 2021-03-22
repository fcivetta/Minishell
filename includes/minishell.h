#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include "./parsing.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

# define BUFFER_SIZE 2048
# define FD_SIZE 256

int	get_next_line(int fd, char **line);

#endif
