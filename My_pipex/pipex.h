/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phella <phella@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:21:37 by phella            #+#    #+#             */
/*   Updated: 2022/01/13 23:30:11 by phella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include   <unistd.h>
# include   <stdlib.h>
# include   <fcntl.h>
# include   <stdio.h>

char	**ft_split(const char *s, char c);
int		ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_path(char *cmd, char **env);
void	ft_get_cmd(char *argv, char **env);
void	ft_parent_process(char **argv, char **env, int *fd);
void	ft_child_process(char **argv, char **env, int *fd);
int		main(int argc, char **argv, char **env);

#endif
