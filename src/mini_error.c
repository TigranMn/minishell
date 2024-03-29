/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <tmnatsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:35:22 by tmnatsak          #+#    #+#             */
/*   Updated: 2024/01/13 14:46:42 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// extern int	g_status;

void	error_msg(char *msg)
{
	printf("%s %s %s\n", "\033[1;33m⚠ minishell: \033[0;33m", msg, DEFAULT);
	exit (1);
}

void	print_error_msg_fd(char *msg, int nl)
{
	ft_putstr_fd("\033[1;33m⚠ minishell: \033[0;33m", 2);
	ft_putstr_fd(msg, 2);
	if (nl)
		ft_putendl_fd(DEFAULT, 2);
}

static void	set_status(int errcode)
{
	g_status = errcode;
	ft_putstr_fd("\033[1;33m⚠ minishell: ", 2);
}

void	*mini_error(int errmsg, char *param, int errcode)
{
	set_status(errcode);
	if (errmsg == EPERM)
		ft_putstr_fd("\033[0;33mpermission denied: \033[0m", 2);
	else if (errmsg == EMEM)
		ft_putstr_fd("\033[0;33mno memory left on device\033[0m\n", 2);
	else if (errmsg == NOTDIR)
		ft_putstr_fd("\033[0;33mNot a directory: \033[0m", 2);
	else if (errmsg == ISDIR)
		ft_putstr_fd("\033[0;33mIs a directory: \033[0m", 2);
	else if (errmsg == NDIR)
		ft_putstr_fd("\033[0;33mNo such file or directory: \033[0m", 2);
	else if (errmsg == ECMD)
		ft_putstr_fd("\033[0;33mcommand not found: \033[0m", 2);
	else if (errmsg == EFORK)
		ft_putstr_fd("\033[0;33mfork failed\n", 2);
	else if (errmsg == EPIPE)
		ft_putstr_fd("\033[0;33merror creating pipe\n", 2);
	else if (errmsg == EPIPEND)
		ft_putstr_fd("\033[0;33msyntax error near unexpected token `|'\n", 2);
	else if (errmsg == DUPERR)
		ft_putstr_fd("\033[0;33mdup2 failed\n", 2);
	else if (errmsg == EQUOTE)
		ft_putstr_fd("\033[0;33merror while looking for matching quote\n", 2);
	ft_putendl_fd(param, 2);
	return (NULL);
}

/****************************************************************************/
/* The  opendir()  function  opens a directory stream corresponding to the  */
/*        directory name, and returns a pointer to  the  directory  stream. */
/*        The stream is positioned at the first entry in the directory.     */
/*                                                                          */
/* DIR structure represents this directory stream. When you open a directory*/
/* with opendir(), it returns a pointer to a DIR structure, which you can   */
/* use to read the directory's contents.                                    */
/****************************************************************************/

// char **str -> HOME and cwd
void	mini_cd_error(char **full_cmd, char **str)
{
	DIR	*dir;

	dir = NULL;
	if (full_cmd[1])
		dir = opendir(full_cmd[1]);
	if (!full_cmd[1] && *str && !str[0][0])
	{
		g_status = 1;
		print_error_msg_fd("HOME not set", 1);
	}
	if (!full_cmd[1] && str[0])
		g_status = chdir(str[0]) < 0;
	if (full_cmd[1] && dir && access(full_cmd[1], F_OK) != -1)
		chdir(full_cmd[1]);
	else if (full_cmd[1] && access(full_cmd[1], F_OK) == -1)
		mini_error(NDIR, full_cmd[1], 1);
	else if (full_cmd[1] && access(full_cmd[1], X_OK) == -1)
		mini_error(EPERM, full_cmd[1], 126);
	else if (full_cmd[1])
		mini_error(NOTDIR, full_cmd[1], 1);
	if (full_cmd[1] && dir)
		closedir(dir);
}
