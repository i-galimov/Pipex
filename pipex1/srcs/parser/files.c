/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:38:48 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/18 16:01:17 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd(t_pipex *pipex, char *arg, int com, char *path)
{
	char	*tmp;

	tmp = NULL;
	if (arg && path)
	{
		arg = ft_strjoin("/", arg);
		tmp = ft_strjoin(path, arg);
		if (access(tmp, X_OK) == 0)
		{
			if (com == 1)
				pipex->command1 = tmp;
			else if (com == 2)
				pipex->command2 = tmp;
			return (0);
		}
		free(arg);
		free(tmp);
	}
	return (-1);
}

void	test_files(t_pipex *pipex, char **args)
{
	pipex->file1_name = args[1];
	pipex->file1 = open(args[1], O_RDONLY);
	pipex->file2 = open(args[4], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (pipex->file2 == -1)
	{
		perror("File2 ");
		error(pipex);
	}
}
