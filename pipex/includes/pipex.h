/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeann <rdeann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:01:52 by rdeann            #+#    #+#             */
/*   Updated: 2021/12/25 18:01:52 by rdeann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include "./includes/libft.h"
# include "./includes/get_next_line.h"

# define SUCCESS 0
# define FAILURE 1

# define ERR_MSG_INVALID_AGRS "Invalid number of arguments."
# define ERR_MSG_USAGE_BONUS "./pipex [here_doc] infile cmd1 cmd2 ... outfile"
# define ERR_MSG_NO_FILE_OR_DIR ": No such file or directory"
# define ERR_MSG_PERMISSION_DENIED ": Permission denied"
# define ERR_MSG_CANNOT_READ "Cannot read file."
# define ERR_MSG_CANNOT_DELETE "Cannot delete file."
# define TMP_FILE "/tmp/.heredoc"

void		error_handler(char *str);

void		free_tab(char **tab);
char		*ft_getpath(char **env, char *cmd);
char		**cmd_parser(const char *cmd);

int			open_infile(char *filename, int flags);
int			open_outfile(char *filename, int flags);

void		piper(int fdin, int fdout, char *cmd, char **envp);
void		executer(char *cmd, char **envp);

void		pipex_bonus(int argc, char **argv, char **envp);
void		pipex_heredoc(int argc, char **argv, char **envp);
int			ft_heredoc(int fd, char *limiter, int pip);
int			piper_heredoc(int in, int out, char *limiter, int pip);
#endif
