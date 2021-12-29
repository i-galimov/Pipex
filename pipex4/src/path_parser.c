/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeann <rdeann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:00:31 by rdeann            #+#    #+#             */
/*   Updated: 2021/12/25 18:00:31 by rdeann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

static char	*ft_parsepath(char *path, const char *cmd)
{
	char	**dir;
	char	*curr;
	char	*tmp;
	int		i;

	dir = ft_split(path, ':');
	if (dir == NULL)
		error_handler("ERROR: PATH is empty.");
	i = 0;
	curr = NULL;
	while (dir[i])
	{
		tmp = ft_strjoin(dir[i], "/");
		curr = ft_strjoin(tmp, (char *)cmd);
		ft_strdel(&tmp);
		if (access(curr, X_OK) != -1)
			break ;
		ft_strdel(&curr);
		i++;
	}
	free_tab(dir);
	return (curr);
}

char	*ft_getpath(char **env, char *cmd)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_parsepath(env[i] + 5, cmd);
			if (path == NULL)
			{
				ft_putstr_fd(STDERR_FILENO, "Error: ");
				ft_putstr_fd(STDERR_FILENO, cmd);
				ft_putstr_fd(STDERR_FILENO, ": command not found ");
				error_handler("");
			}	
		}
		i++;
	}
	return (path);
}
