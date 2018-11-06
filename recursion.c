/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:46:08 by nselaule          #+#    #+#             */
/*   Updated: 2018/11/06 10:05:50 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		recur(t_flags *flags, t_files *files)
{
	t_files	*cur;

	cur = files;
	while (cur)
	{
		if (cur->name && cur->path && S_ISDIR(cur->st_mode)
				&& ft_strcmp(".", cur->name) && ft_strcmp("..", cur->name)
				&& !(flags->a == 0 && cur->name[0] == '.'))
		{
			ft_putchar('\n');
			recur2(flags, cur->path);
		}
		cur = cur->next;
	}
}

void		recur2(t_flags *flags, char *path)
{
	int		i;
	char	*tab;
	DIR		*dir;
	t_files	*file;
	t_files *tmp;

	file = NULL;
	i = 1;
	ft_putstr(path);
	ft_putstr(":\n");
	if ((dir = opendir(path)) != NULL)
	{
		while (i != 0)
		{
			tab = ft_strjoin(path, "/");
			i = link_new(&file, readdir(dir), tab);
			free(tab);
		}
		closedir(dir);
		if (file)
		{
			/*tmp = file;
			while (tmp)
			{
				free(tmp->name);
				free(tmp->path);
				free(tmp->rights);
				free(tmp->uname);
				free(tmp->gname);
				free(tmp->lnpath);
				free(tmp);
				tmp = tmp->next;
			}*/
			output(flags, file, 1);
		}
		tmp = file;
		while (tmp)
		{
			free(tmp->name);
			free(tmp->path);
			free(tmp->rights);
			free(tmp->uname);
			free(tmp->gname);
			free(tmp->lnpath);
			free(tmp);
			tmp = tmp->next;
		}
	}
	else
		perm_dnied(path);
	//	free(file);
}

int			link_new(t_files **file, struct dirent *dir, char *path)
{
	t_files	*list;
	t_files *node;

	list = *file;
	if (!dir)
		return (0);
	if (list)
	{
		while (list->next)
			list = list->next;
		node = add_node(dir->d_name, path);
		list->next = node;
	}
	else
		*file = add_node(dir->d_name, path);
	return (1);
}
