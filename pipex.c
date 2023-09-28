/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoyan <tnoyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:49:06 by tnoyan            #+#    #+#             */
/*   Updated: 2023/08/01 00:53:57 by tnoyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	ft_error_control(argc, argv);
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error("pipe error");
		pid1 = fork();
		if (pid1 == 0)
		{
			waitpid(pid1, NULL, 0);
			parent_process(fd, argv, envp);
		}
		pid1 = fork();
		if (pid1 == 0)
			child_process(fd, argv, envp);
	}
	else
	{
		ft_error("arguments error");
		exit(1);
	}
	return (0);
}
