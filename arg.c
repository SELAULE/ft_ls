/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:44:09 by nselaule          #+#    #+#             */
/*   Updated: 2019/02/15 17:29:21 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	free_this_shit(t_helper *helper)
{
	int j;
	int	x;

	j = 0;
	while (j < 100)
	{
		ft_strdel(&helper->dirs[j]);
		j++;
	}
	free(helper->dirs);
	helper->dirs = NULL;
	x = 0;
	while (x < 100)
	{
		ft_strdel(&helper->file[x]);
		x++;
	}
	free(helper->file);
	helper->file = NULL;
	free(helper);
	helper = NULL;
}

void		cparams(t_flags *flags, int i, t_helper *helper)
{
	DIR		*dir;

	helper = init_helper();
	while (helper->i++ != flags->rem)
	{
		if ((dir = opendir(flags->arg[helper->i])) == NULL)
		{
			if (errno != ENOTDIR)
				no_directory(flags->arg[helper->i]);
			else
			{
				ft_strcpy(helper->file[helper->fil], flags->arg[helper->i]);
				helper->fil++;
			}
		}
		else
		{
			ft_strcpy(helper->dirs[helper->dir], flags->arg[helper->i]);
			helper->dir++;
			if (closedir(dir) == -1)
				no_directory(flags->arg[helper->i]);
		}
//		helper->i++;
	}
	ft_param(flags, helper, i);
	free_this_shit(helper);
}

void		ft_param(t_flags *flags, t_helper *helper, int i)
{
	i = 0;
	if (helper->fil != 0)
		check_file(flags, helper);
	if (helper->fil != 0 && helper->dir != 0)
		ft_putchar('\n');
	if (helper->dir != 0)
		check_dirs(flags, helper, i);
}
