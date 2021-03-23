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
		(char *)strerror(errno); // Faire une fonction ft_error ? Ex : ft_error(Command, "fork")
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (execve(cmd[0], cmd, NULL) == -1)
			(char *)strerror(errno); // Faire une fonction ft_error?
		exit(EXIT_FAILURE);
	}

}

static void	get_absolute_path(char **cmd)
{
	char	*path;
	char	*bin;
	char	**path_split;
	int	i;

	path = ft_strdup(getenv("PATH"));
	bin = NULL;
	path_split = NULL;
	i = 0;
	if (path == NULL)
		path = ft_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	if (cmd[0][0] != '/' && ft_strncmp(cmd[0], "./", 2) != 0)
	{
		path_split = ft_split(path, ':');
		free(path); //Apres un split, liberer directement la chane de caractere
		path = NULL;
		while (path_split[i])
		{
			if(!(bin = (char *)malloc(sizeof(char) * (ft_strlen(path_split[i]) + ft_strlen(cmd[0]) + 1))))
				exit(EXIT_FAILURE); //changer pour une fonction ft_error
			ft_strcat(bin, path_split[i]);
			ft_strcat(bin, "/");
			ft_strcat(bin, cmd[0]);

			if (access(bin, F_OK) == 0)
				break;
			free(bin);
			bin = NULL;
			i++;
		}
		free_array(path_split);
		free(cmd[0]);
		cmd[0] = bin;
		//printf("%s", cmd[0]);
	}
	else 
	{
		free(path);
		path = NULL; //Pour free proprement : d'abord on free puis on met a NULL
	}

}

int	main(int argc, char **argv, char **envp) // envp represente l'environnement du programme
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
	//	printf("cmd = %s\n", line);
		cmd = ft_split(line, 32);
		if (cmd[0] == NULL)
			printf("Command not found\n");
		else if (is_built_in(cmd[0]) == 0)
		{
			get_absolute_path(cmd);
			exec_cmd(cmd);
		}
		else
			exec_built_in(cmd);
		write(1, "$> ", 3);
		free_array(cmd);
	}
	if (ret < 0)
	{
		(char *)strerror(errno);
		//Traiter sortie erreur
	}
	printf("Bye \n");
	free(line);
}
