/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeann <rdeann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:00:15 by rdeann            #+#    #+#             */
/*   Updated: 2021/12/25 18:00:15 by rdeann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	heredoc_bool;
	int	save_argc;

	heredoc_bool = 0;
	save_argc = ac;
	if (ac > 1 && ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		save_argc--;
		heredoc_bool = 1;
	}
	if (save_argc < 5)
	{
		ft_putstr_fd(STDERR_FILENO, ERR_MSG_INVALID_AGRS);
		ft_putstr_fd(STDERR_FILENO, " Usage : ");
		ft_putendl_fd(STDERR_FILENO, ERR_MSG_USAGE_BONUS);
		exit(FAILURE);
	}
	if (heredoc_bool == 0)
		pipex_bonus(ac, av, envp);
	else
		pipex_heredoc(ac, av, envp);
	return (SUCCESS);
}
