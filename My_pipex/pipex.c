#include "pipex.h"

char	*ft_path(char *cmd, char **env)
{
	int     i;
	char    **all_paths;
	char    *piece_path;
	char    *res;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	all_paths = ft_split(env[i] +5, ':');
	i = 0;
	while (all_paths[i])
	{
		piece_path = ft_strjoin(all_paths[i], "/");
		res = ft_strjoin(piece_path, cmd);
		if (access(res, F_OK) == 0) 
			return (res);
		else
			free(res);
		i++;
	}
	exit(0);
}

void	ft_get_cmd(char *argv, char **env)
{
	char    **cmd;
	char    *path;

	cmd = ft_split(argv, ' ');
	path = ft_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
	{	
		perror("Command error");
		exit(1);
	}
}

void	ft_parent_process(char **argv, char **env, int *fd)
{
	int fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
	{
		write(2, "Permission denied error", 23);
		write(2, argv[4], ft_strlen(argv[4]));
		write(2, "\n", 1);
		exit(1);
	}
	dup2(fd[0], 0);
	dup2(fd_out, 1);
	close(fd[1]);
	ft_get_cmd(argv[3], env);
}

void	ft_child_process(char **argv, char **env, int *fd)
{
	if (access(argv[1], F_OK) != 0)
	{
		write(2, "No such file or directory error", 31);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
		exit(1);
	}
	if (access(argv[1], R_OK) != 0)
	{
		write(2, "Permission denied error", 23);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
		exit(1);
	}
	dup2(fd[1], 1);
	dup2(open(argv[1], O_RDONLY), 0);
	close(fd[0]);
	ft_get_cmd(argv[2], env);
}

int		main(int argc, char **argv, char **env)
{
	int		pid;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("Pipe error");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Fork error");
			exit(1);
		}
		if (pid == 0)
			ft_child_process(argv, env, fd);
		waitpid(pid, 0, 0);
		ft_parent_process(argv, env, fd);
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}
