/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_parent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoyan <tnoyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:49:20 by tnoyan            #+#    #+#             */
/*   Updated: 2023/07/31 22:53:33 by tnoyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[1]);
	execute(argv[2], envp);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	execute(argv[3], envp);
}
