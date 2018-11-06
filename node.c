/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:44:34 by nselaule          #+#    #+#             */
/*   Updated: 2018/11/06 09:50:40 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				major_minor(t_files *entry)
{
	struct stat		fstat;

	lstat(entry->path, &fstat);
	if (entry->type == 'c' || entry->type == 'b')
	{
		entry->major = (int)major(fstat.st_rdev);
		entry->minor = (int)minor(fstat.st_rdev);
	}
}

void				ft_node(t_files *entry)
{
	struct stat		fstat;
	char			buf[257];
	ssize_t			i;

	lstat(entry->path, &fstat);
	entry->lnpath = malloc(ft_strlen(entry->name) + 1);
	entry->type = gettype(fstat);
	entry->rights = getrights(fstat);
	if (getpwuid(fstat.st_uid) == NULL)
		entry->uname = ft_strdup("root");
	else
		entry->uname = ft_strdup((getpwuid(fstat.st_uid))->pw_name);
	if (getgrgid(fstat.st_gid) == NULL)
		entry->gname = ft_strdup("wheel");
	else
		entry->gname = ft_strdup((getgrgid(fstat.st_gid))->gr_name);
	if (entry->type != 'b' && entry->type != 'c')
		entry->size = fstat.st_size;
	if (entry->type == 'l')
	{
		if ((i = readlink(entry->path, buf, sizeof(buf) - 1)) != -1)
			buf[i] = '\0';
		free(entry->lnpath);
		entry->lnpath = ft_strdup(buf);
	}
	major_minor(entry);
//	pls_free_this_shit(&entry);
}

t_files				*add_node(char *name, char *path)
{
	t_files			*entry;
	struct stat		fstat;

	entry = malloc(sizeof(t_files));
	entry->name = ft_strdup(name);
	entry->path = ft_strjoin(path, name);
	if (lstat(entry->path, &fstat) == -1)
	{
		no_directory(entry->name);
		return (NULL);
	}
	entry->st_mode = fstat.st_mode;
	entry->st_nlink = fstat.st_nlink;
	entry->st_blocks = fstat.st_blocks;
	entry->ldatamod = fstat.st_mtimespec;
	entry->lstatch = fstat.st_ctimespec;
	entry->created = fstat.st_mtimespec;
	ft_node(entry);
	entry->next = NULL;
	return (entry);
}

void				add_file_dir(t_files **files, char *name, char *dir)
{
	t_files			*list;

	list = *files;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = add_node(name, dir);
	}
	else
		*files = add_node(name, dir);
}

void	clean_up(t_files **dlist)
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
		//	ptr->dname ?ft_memdel((void*)&ptr->dname) : 0;
			ptr->lnpath ? ft_memdel((void*)&ptr->lnpath) : 0;
//		ptr->l ? ft_memdel((void*)&ptr->l) : 0;
			ptr->rights ? ft_memdel((void*)&ptr->rights) : 0;
			ptr->path ? ft_memdel((void*)&ptr->path) : 0;
			ptr ? ft_memdel((void*)&ptr) : 0;
			ptr = (*dlist);
		}
		ptr ? ft_memdel((void*)&ptr) : 0;
	}
	return ;
}
