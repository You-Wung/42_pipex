/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 23:46:48 by tyou              #+#    #+#             */
/*   Updated: 2021/06/08 18:23:33 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# define CHILD 0
# define FILE_1	argv[1]
# define FILE_2	argv[4]
# define CMD_1	argv[2]
# define CMD_2	argv[3]

typedef struct		s_cmd
{
	const char		*cmd[5];
	char * const	*argv;
	char * const	*envp;
}					t_cmd;

#endif