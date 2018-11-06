/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:46:48 by nselaule          #+#    #+#             */
/*   Updated: 2018/11/06 10:03:04 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		output(t_flags *flags, t_files *file, int i)
{
	t_files	*cur;

	cur = file;
	cur = sort_files(cur, flags);
	if (flags->l == 1)
		lsprint(flags, cur, i);
	else
		basicls(flags, cur);
	if (flags->r == 1)
		recur(flags, cur);
}

t_files		*sort_files(t_files *list, t_flags *flags)
{
	t_files	*new;

	if (!list)
		return (NULL);
	new = list;
	sort(&new, cmp_alpha);
	if (flags->t == 1)
		sort(&new, cmp_time);
	if (flags->rv == 1)
		reversesort(&new);
	return (new);
}

void		sort(t_files **list, int (*cmp)(t_files *entry1, t_files *entry2))
{
	t_files	*a;
	t_files	*b;

	a = *list;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (cmp(a, b) > 0)
				swap_entry(&a, &b);
			b = b->next;
		}
		a = a->next;
	}
}

void		swap_entry(t_files **a, t_files **b)
{
	t_files	tmp;

	tmp = **a;
	entry_cpy(a, *b);
	entry_cpy(b, &tmp);
}

void		entry_cpy(t_files **src, t_files *cpy)
{
	(*src)->name = cpy->name;
	(*src)->path = cpy->path;
	(*src)->st_mode = cpy->st_mode;
	(*src)->st_nlink = cpy->st_nlink;
	(*src)->st_blocks = cpy->st_blocks;
	(*src)->ldatamod = cpy->ldatamod;
	(*src)->lstatch = cpy->lstatch;
	(*src)->created = cpy->created;
	(*src)->lnpath = cpy->lnpath;
	(*src)->type = cpy->type;
	(*src)->rights = cpy->rights;
	(*src)->uname = cpy->uname;
	(*src)->gname = cpy->gname;
	(*src)->size = cpy->size;
	(*src)->major = cpy->major;
	(*src)->minor = cpy->minor;
}
