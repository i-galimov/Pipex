/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeann <rdeann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:00:53 by rdeann            #+#    #+#             */
/*   Updated: 2021/12/25 18:00:53 by rdeann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

int	open_infile(char *filename, int mode)
{
	int	flags;

	if (mode == 0)
		flags = O_RDONLY;
	if (access(filename, F_OK) == -1)
	{
		ft_putstr_fd(STDERR_FILENO, filename);
		ft_putendl_fd(STDERR_FILENO, ERR_MSG_NO_FILE_OR_DIR);
		exit(FAILURE);
	}
	else if (access(filename, R_OK) == -1)
	{
		ft_putstr_fd(STDERR_FILENO, filename);
		ft_putendl_fd(STDERR_FILENO, ERR_MSG_PERMISSION_DENIED);
		exit(FAILURE);
	}
	return (open(filename, flags));
}

int	open_outfile(char *filename, int mode)
{
	int	flags;

	if (mode == 1)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	else if (mode == 2)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	if (access(filename, F_OK) != -1 && access(filename, W_OK) == -1)
	{
		ft_putstr_fd(STDERR_FILENO, filename);
		ft_putendl_fd(STDERR_FILENO, ERR_MSG_PERMISSION_DENIED);
		exit(FAILURE);
	}
	return (open(filename, flags));
}
