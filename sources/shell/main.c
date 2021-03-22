#include "../../includes/minishell.h"

static void	exec_cmd(char **cmd)
{
	pid_t	pid;
	int	status;

	pid = 0;
	status = 0;
	pid = fork();
	if (pid == -1)
	{
		//ft_error(Command, "fork");
		(char *)strerror(errno);
	}
	else if (pid > 0)
	{

	}

}

int	main(int argc, char **argv)
{
	char	*line;
	int	ret;
	char	**cmd;
	int	i;

	i = 0;
	line = NULL;
	write(1, "$> ", 3);
	while((ret = get_next_line(0, &line)) > 0)
	{
		printf("cmd = %s\n", line);
		cmd = ft_split(line, 32);
		if (cmd[0] == NULL)
			printf("Command not found\n");
		else
			exec_cmd(cmd);
		write(1, "$> ", 3);
	}
	if (ret < 0)
	{
		//Traiter sortie erreur
	}
	printf("Bye \n");
	free(line);
}
