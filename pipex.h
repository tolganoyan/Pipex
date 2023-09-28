/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoyan <tnoyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:49:00 by tnoyan            #+#    #+#             */
/*   Updated: 2023/07/31 22:51:29 by tnoyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

void	ft_error_control(int ac, char **av);
void	ft_putstr_fd(char *s, int fd);
void	ft_error(char *reason);
int		ft_strlen(char *str);
char	*ft_path_control(char *path_c, char **envp);
void	execute(char *argv, char **envp);
void	child_process(int *fd, char **argv, char **envp);
void	parent_process(int *fd, char **argv, char **envp);
char	*substr(const char *str, int start, int length);
char	*ft_strjoin(char *s1, char *s2);
int		count_words(char const *s, char c);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);

#endif
