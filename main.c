/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 22:05:16 by tyou              #+#    #+#             */
/*   Updated: 2021/06/10 22:45:59 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char const *argv[])
{
	int		pipefd[2];
	pid_t	pid;
	t_cmd	cmd;
	int		status;

	if (argc != 5)
		exit(1);
	for (int i = 0; argv[i]; i++)
		printf("argv[%d] : %s\n",i, argv[i]);
	pipe(pipefd);
	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) == 0)
			exit(1);
		redirect_out(argv[4]);
		connect_pipe(pipefd, STDIN_FILENO);
		run_cmd(argv[3], &cmd);
		/*
			FILE2 생성, 표준출력 fd가 FILE2 fd룰 가르킴.
			pipefd 쪽에서 pipefd[0] (받는 fd) 가 표준입력으로 들어간다.
			CMD 실행. 표준입력과 함께.2
		*/
	}
	else if (pid == CHILD)
	{
		redirect_in(argv[1]);
		connect_pipe(pipefd, STDOUT_FILENO);
		run_cmd(argv[2], &cmd);
		/*
			FILE1 이 표준입력으로 들어가고
			connect_pipe 에서 표준출력이 pipefd[1] 으로 들어간다.
			커맨드를 실행할 때 표준입력으로 FIEL1 이 들어가는 것.
			그 이후에 표준출력은 pipefd[1] 로 들어감.
		*/
	}
	return (1);
}