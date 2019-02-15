/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:46:00 by nselaule          #+#    #+#             */
/*   Updated: 2019/02/15 10:27:53 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		basicls(t_flags *flags, t_files *file)
{
	t_files	*cur;

	cur = file;
	while (cur)
	{
		if (!(flags->a == 0 && cur->name[0] == '.'))
			ft_putendl(cur->name);
		cur = cur->next;
	}
	clean_up(&file);
}

void		lsprint(t_flags *flags, t_files *file, int i)
{
	t_files	*tmp;
	int		y;

	y = 0;
	tmp = file;
	y = check_size(flags, file);
	if (i)
	{
		ft_putstr("total ");
		ft_putnbr(y);
		ft_putchar('\n');
	}
	while (tmp)
	{
		if (!(flags->a == 0 && tmp->name[0] == '.'))
		{
			lsprintlong(tmp);
			ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

int			check_size(t_flags *flags, t_files *file)
{
	t_files	*tmp;
	int		i;

	i = 0;
	tmp = file;
	while (tmp)
	{
		if (!(flags->a == 0 && tmp->name[0] == '.'))
		{
			i += tmp->st_blocks;
		}
		tmp = tmp->next;
	}
	return (i);
}

void		lsprintlong(t_files *file)
{
	ft_putchar(file->type);
	ft_putstr(file->rights);
	if (file->st_nlink > 9)
		ft_putstr(" ");
	else
		ft_putstr("  ");
	ft_putnbr(file->st_nlink);
	ft_putchar(' ');
	ft_putstr(file->uname);
	if ((ft_strlen(file->uname)) > 6)
		ft_putstr("  ");
	else
		ft_putstr("      ");
	print_fill(file->gname);
	lsprintlong2(file);
	ft_putstr("  ");
	poster_date(file);
	if (file->type == 108)
	{
		ft_putstr(file->name);
		ft_putstr(" -> ");
		ft_putstr(file->lnpath);
	}
	else
		ft_putstr(file->name);
}

void		lsprintlong2(t_files *file)
{
	if (file->type == 'c' || file->type == 'b')
	{
		if (file->major > 9)
			ft_putnbr(file->major);
		else
		{
			ft_putchar(' ');
			ft_putnbr(file->major);
		}
		ft_putstr(", ");
		if (file->minor > 99)
			ft_putnbr(file->minor);
		if (file->minor > 9 && file->minor < 100)
		{
			ft_putchar(' ');
			ft_putnbr(file->minor);
		}
		if (file->minor < 10)
		{
			ft_putstr("  ");
			ft_putnbr(file->minor);
		}
	}
	else
		lsprintlong3(file);
}
