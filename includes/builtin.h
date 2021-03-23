#ifndef BUILTIN_H
# define BUILTIN_H

int	is_built_in(char *cmd);

void	exec_built_in(char **built_in);

void		built_in_cd(char *path);

void		built_in_pwd(void);

#endif
