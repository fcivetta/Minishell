#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include "./parsing.h"
# include "./utils.h"
# include "./builtin.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdbool.h>
# include <linux/limits.h> 

# define BUFFER_SIZE 2048
# define FD_SIZE 256
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define true 1
# define false 0

int	get_next_line(int fd, char **line);

#endif
