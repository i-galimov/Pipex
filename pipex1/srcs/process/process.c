/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:20:37 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/18 16:14:05 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_pipex *pipex)
{
	if (pipex->file1 != -1)
		dup2(pipex->file1, STDIN_FILENO);
	else
	{
		ft_putstr(pipex->file1_name);
		ft_putstr(" : No such file or directory\n");
		close(pipex->end[0]);
		exit(-1);
	}
	dup2(pipex->end[1], STDOUT_FILENO);
	close(pipex->end[0]);
	execve(pipex->command1, pipex->args1, pipex->envp);
	ft_putstr_fd(pipex->command1, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	pipex->ret = 127;
	error(pipex);
}

void	second_command(t_pipex *pipex)
{
	dup2(pipex->file2, STDOUT_FILENO);
	dup2(pipex->end[0], STDIN_FILENO);
	close(pipex->end[1]);
	execve(pipex->command2, pipex->args2, pipex->envp);
	ft_putstr_fd(pipex->command2, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	pipex->ret = 127;
	error(pipex);
}
