/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeann <rdeann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:00:25 by rdeann            #+#    #+#             */
/*   Updated: 2021/12/25 18:00:25 by rdeann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

int	ft_heredoc(int fd, char *limiter, int pip)
{
	int		i;
	int		ret;
	char	*line;

	while (true)
	{
		i = 0;
		while (i++ < pip)
			ft_putstr_fd(STDOUT_FILENO, "pipe ");
		ft_putstr_fd(STDOUT_FILENO, "heredoc> ");
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == -1)
			break ;
		ret = ft_strcmp(line, limiter);
		if (ret)
			ft_putendl_fd(fd, line);
		ft_strdel(&line);
		if (ret == 0)
			break ;
	}
	return (ret);
}

void	pipex_heredoc(int ac, char **av, char **envp)
/*
	delay loshara code
*/
{
	int		i;
	int		status;
	int		tmpfd[2];
	int		pipefd[2];

	i = 2;
	while (i < ac - 1)
	{
		if (pipe(pipefd) == -1)
			error_handler("Failed to create a pipe.");
		if (i == 2)
			tmpfd[0] = piper_heredoc(pipefd[0], pipefd[1], av[2], ac - 5);
		else
		{	
			tmpfd[1] = pipefd[1];
			if (i == ac - 2)
				tmpfd[1] = open_outfile(av[ac - 1], 2);
			piper(tmpfd[0], tmpfd[1], av[i], envp);
			tmpfd[0] = pipefd[0];
		}
		i++;
	}
	while (waitpid(-1, &status, 0) > 0)
		;
}

void	pipex_bonus(int argc, char **argv, char **envp)
{
	int		i;
	int		status;
	int		tmpfd[2];
	int		filefd[2];
	int		pipefd[2];

	filefd[0] = open_infile(argv[1], 0);
	filefd[1] = open_outfile(argv[argc - 1], 1);
	i = 2;
	while (i < argc - 1)
	{
		if (pipe(pipefd) == -1)
			error_handler("Failed to create a pipe.");
		tmpfd[1] = pipefd[1];
		if (i == 2)
			tmpfd[0] = filefd[0];
		else if (i == argc - 2)
			tmpfd[1] = filefd[1];
		piper(tmpfd[0], tmpfd[1], argv[i], envp);
		tmpfd[0] = pipefd[0];
		i++;
	}
	while (waitpid(-1, &status, 0) > 0)
		;
}
