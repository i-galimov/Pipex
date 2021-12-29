/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeann <rdeann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:00:57 by rdeann            #+#    #+#             */
/*   Updated: 2021/12/25 18:00:57 by rdeann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"	
/*
	???
*/
void	executer(char *cmd, char **envp)
{
	const char	*path;
	char		**args;

	args = cmd_parser(cmd);
	if (args[0][0] == '/')
	{
		if (access(args[0], X_OK) == -1)
		{
			ft_putstr_fd(STDERR_FILENO, "Error: ");
			ft_putstr_fd(STDERR_FILENO, args[0]);
			error_handler(ERR_MSG_NO_FILE_OR_DIR);
		}	
		path = ft_strdup(args[0]);
	}	
	else
		path = ft_getpath(envp, args[0]);
	if (ft_strchr(path, '/') != NULL)
		execve(path, args, envp);
	ft_putstr_fd(STDERR_FILENO, "Error: ");
	ft_putstr_fd(STDERR_FILENO, (char *)path);
	ft_putstr_fd(STDERR_FILENO, ": Failed to execve the process");
	ft_memdel((char *)path);
	free_tab(args);
	error_handler(".");
}
