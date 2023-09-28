/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoyan <tnoyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:49:12 by tnoyan            #+#    #+#             */
/*   Updated: 2023/09/12 20:22:29 by tnoyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path_control(char *path_c, char **envp)
{
	char	**full_paths;
	char	*path_directory;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	full_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (full_paths[i])
	{
		part_path = ft_strjoin(full_paths[i], "/");
		path_directory = ft_strjoin(part_path, path_c);
		free(part_path);
		if (access(path_directory, F_OK) == 0)
			return (path_directory);
		i++;
	}
	i = -1;
	while (full_paths[++i])
		free(full_paths[i]);
	free(full_paths);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**cmd_space;
	char	*path_ctrl;
	int		i;

	i = -1;
	cmd_space = ft_split(argv, ' ');
	path_ctrl = ft_path_control(cmd_space[0], envp);
	if (!cmd_space)
	{
		while (cmd_space[++i])
			free(cmd_space[i]);
		free(cmd_space);
		exit(1);
	}
	if (execve(path_ctrl, cmd_space, envp) == -1)
		ft_error("execute error");
}
