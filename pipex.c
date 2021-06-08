/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:53:26 by tyou              #+#    #+#             */
/*   Updated: 2021/06/09 00:02:10 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char **environ;

static void	connect_pipe(int pipefd[2], int io)
{
	dup2(pipefd[io], io);
	close(pipefd[0]);
	close(pipefd[1]);
}

static void	cmd_init(const char *cmd, t_cmd *strt)
{
	char	**chunk;

	printf("starts\n");
	chunk = ft_split(cmd, ' ');
	printf("chunk[0] : %s\t%d\n",chunk[0], getpid());
	printf("chunk[1] : %s\t%d\n",chunk[1], getpid());
	printf("chunk[2] : %s\t%d\n",chunk[2], getpid());
	strt->cmd[0] = ft_strjoin("/bin/", chunk[0]);
	strt->cmd[1] = ft_strjoin("/usr/local/bin/", chunk[0]);
	strt->cmd[2] = ft_strjoin("/usr/bin/", chunk[0]);
	strt->cmd[3] = ft_strjoin("/usr/sbin/", chunk[0]);
	strt->cmd[4] = ft_strjoin("/sbin/", chunk[0]);
	strt->argv = (char *const *)chunk;
}

static void	run_cmd(const char *cmd, t_cmd *cmd_arg)
{
	int i;

	i = 0;
	cmd_init(cmd, cmd_arg);
	while(i < 5)
		execve(cmd_arg->cmd[i++], cmd_arg->argv, environ);
	perror(cmd_arg->argv[0]);
}

int	redirect_out(const char *file)
{
	int fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	redirect_in(const char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int main(int argc, char const *argv[])
{
	int		pipefd[2];
	pid_t	pid;
	t_cmd	cmd;
	int		status;

	for(int i = 0; i < 5; i++)
		printf("argv[%d] : %s\n",i, argv[i]);
	if (argc != 5)
		exit(1);
	pipe(pipefd);
	pid = fork();

	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) == 0)
			exit(1);
		redirect_out(FILE_2);
		connect_pipe(pipefd, STDIN_FILENO);
		run_cmd(CMD_2, &cmd);
	}
	else if (pid == CHILD)
	{
		redirect_in(FILE_1);
		connect_pipe(pipefd, STDOUT_FILENO);
		run_cmd(CMD_1, &cmd);
	}
	if (WIFEXITED(status) == 0)
		exit(1);
}