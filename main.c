/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 14:02:46 by nselaule          #+#    #+#             */
/*   Updated: 2018/11/05 16:47:22 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			check_flag(char **tab, int x, int z, t_flags *flags)
{
	if (tab[x][z] != '\0')
	{
		if (tab[x][z] == 'l' || tab[x][z] == 'R' ||
			tab[x][z] == 'a' || tab[x][z] == 'r' || tab[x][z] == 't')
			copy_flag(tab, x, z, flags);
		else
			illegal_options(tab[x][z]);
	}
}

void			copy_flag(char **tab, int x, int z, t_flags *flags)
{
	if (tab[x][z] == 'l')
		flags->l = 1;
	if (tab[x][z] == 'R')
		flags->r = 1;
	if (tab[x][z] == 'a')
		flags->a = 1;
	if (tab[x][z] == 'r')
		flags->rv = 1;
	if (tab[x][z] == 't')
		flags->t = 1;
	z++;
	check_flag(tab, x, z, flags);
}

void			check_argv(int i, char **tab, t_flags *flags)
{
	while (flags->x != i)
	{
		if (tab[flags->x][flags->y] == '-')
		{
			if (flags->test == 1)
				no_directory(tab[flags->x]);
			else
			{
				flags->y++;
				check_flag(tab, flags->x, flags->y, flags);
			}
		}
		else
		{
			ft_strcpy(flags->arg[flags->u], tab[flags->x]);
			flags->rem++;
			flags->u++;
			flags->test = 1;
		}
		flags->y = 0;
		flags->x++;
	}
}

void			trie_alpha_argv(t_flags *flags)
{
	int			rem;
	int			i;

	rem = 0;
	i = 0;
	while (rem == 0)
	{
		rem = 1;
		while (i < (flags->rem - 1))
		{
			if (ft_strcmp(flags->arg[i], flags->arg[i + 1]) > 0)
			{
				swap_char(flags, i);
				rem = 0;
			}
			i++;
		}
		i = 0;
	}
}

static void	free_shit(t_flags *flags)
{
	int j;

	j = -1;
	while (++j < 100)
		ft_strdel(&flags->arg[j]);
	free(flags->arg);
	flags->arg = NULL;
	free(flags);
	flags = NULL;
}

int				main(int argc, char **argv)
{
	t_flags		*flags;
	t_helper	*f;
	int			i;

	i = 1;
	f = NULL;
	flags = init_flags();
	if (argc > 1)
	{
		check_argv(argc, argv, flags);
		trie_alpha_argv(flags);
	}
	if (flags->arg[0][0] == '\0')
	{
		flags->arg[0][0] = '.';
		flags->arg[0][1] = '\0';
		flags->rem = 1;
	}
	if (flags->arg[1][0] != '\0')
		i = 0;
	cparams(flags, i, f);
	free_shit(flags);
//	sleep(90);
	return (0);
}
