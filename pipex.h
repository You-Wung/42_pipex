/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 23:46:48 by tyou              #+#    #+#             */
/*   Updated: 2021/06/10 22:44:54 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define CHILD 0
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_cmd
{
	const char		*cmd[5];
	char * const	*argv;
	char * const	*envp;
}					t_cmd;
void				connect_pipe(int pipefd[2], int io);
void				cmd_init(const char *cmd, t_cmd *strt);
void				run_cmd(const char *cmd, t_cmd *cmd_arg);
int					redirect_out(const char *file);
int					redirect_in(const char *file);
#endif
