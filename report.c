/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:56:17 by nselaule          #+#    #+#             */
/*   Updated: 2018/10/23 13:56:19 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

void		no_directory(char *str)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void		illegal_options(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ft_ls [-Ralrt] [file ...]", 2);
	exit(EXIT_FAILURE);
}

void		perm_dnied(char *str)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}

void		poster_date(t_files *file)
{
	ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[4], 12));
	ft_putchar(' ');
}
