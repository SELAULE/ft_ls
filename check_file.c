/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:44:24 by nselaule          #+#    #+#             */
/*   Updated: 2018/09/27 18:13:07 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		check_file(t_flags *flags, t_helper *helper)
{
	t_files	*file;
	int		i;

	i = 0;
	file = NULL;
	flags->a = 1;
	while (i != helper->fil)
	{
		add_file_dir(&file, helper->file[i], "");
		i++;
	}
	if (file)
		output(flags, file, 0);
}

static	void	clean_up_shit(t_files **dlist)
{
	t_files *ptr;

	ptr = NULL;
	if ((dlist && *dlist))
	{
		ptr = (*dlist);
		while (ptr)
		{
			(*dlist) = (*dlist)->next;
			ptr->next = NULL;
			(ptr->name) ? ft_memdel((void*)&ptr->name) : 0;
			(ptr->gname) ? ft_memdel((void*)&ptr->gname) : 0;
			(ptr->uname) ? ft_memdel((void*)&ptr->uname) : 0;
			ptr->lnpath ? ft_memdel((void*)&ptr->lnpath) : 0;
			ptr->rights ? ft_memdel((void*)&ptr->rights) : 0;
			ptr->path ? ft_memdel((void*)&ptr->path) : 0;
			ptr ? ft_memdel((void*)&ptr) : 0;
			ptr = (*dlist);
		}
		ptr ? ft_memdel((void*)&ptr) : 0;
	}
	return ;
}

int			check_dirs(t_flags *flags, t_helper *helper, int x)
{
	t_files	*dirs;
	int		i;
	int		first;

	first = 0;
	dirs = NULL;
	i = 0;
	x = helper->dir;
	while (i != helper->dir)
	{
		add_file_dir(&dirs, helper->dirs[i], "");
		if (dirs->type == 108 && flags->l == 1)
		{
			lsprintlong(dirs);
			return (0);
		}
		i++;
	}
	dirs = sort_files(dirs, flags);
	check_dirs2(flags, dirs, x, first);
	dirs ? clean_up_shit(&dirs) : 0;
	return (0);
}

int			dir_newline(int first, t_files *dirs, int x)
{
	if (first == 1)
		ft_putchar('\n');
	if (x > 1)
		ft_putendl(ft_strjoin(dirs->name, ":"));
	return (1);
}

void			check_dirs2(t_flags *flags, t_files *dirs, int x, int first)
{
	char		*tab;
	DIR			*dir;
	int			i;
	t_files		*files;

	files = NULL;
	i = 1;
	while (dirs)
	{
		dir = opendir(dirs->name);
		while (i != 0)
		{
			tab = ft_strjoin(dirs->path, "/");
			i = link_new(&files, readdir(dir), tab);
			ft_strdel(&tab);
		}
		closedir(dir);
		if (files)
		{
			first = dir_newline(first, dirs, x);
			output(flags, files, 1);
		}
		i = 1;
		files = NULL;
		dirs = dirs->next;
	}
}
