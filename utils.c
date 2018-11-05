/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:54:08 by nselaule          #+#    #+#             */
/*   Updated: 2018/11/05 10:29:20 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flags			*init_flags(void)
{
	t_flags		*lst;
	int			i;

	i = 0;
	lst = (t_flags *)malloc(sizeof(t_flags) * 1);
	lst->arg = (char **)malloc(sizeof(char*) * 100);
	while (i != 100)
	{
		lst->arg[i] = (char *)malloc(sizeof(char) * 500);
		lst->arg[i][0] = '\0';
		i++;
	}
	lst->l = 0;
	lst->r = 0;
	lst->a = 0;
	lst->rv = 0;
	lst->t = 0;
	lst->test = 0;
	lst->y = 0;
	lst->u = 0;
	lst->rem = 0;
	lst->x = 1;
	return (lst);
}

void			swap_char(t_flags *flags, int i)
{
	char		*tmp;

	tmp = flags->arg[i];
	flags->arg[i] = flags->arg[i + 1];
	flags->arg[i + 1] = tmp;
}

t_helper		*init_helper(void)
{
	t_helper	*lst;

	lst = (t_helper *)malloc(sizeof(t_helper) * 1);
	lst->i = 0;
	lst->dir = 0;
	lst->fil = 0;
	lst->dirs = create_char();
	lst->file = create_char();
	return (lst);
}

char			**create_char(void)
{
	char		**new;
	int			i;

	i = 0;
	new = (char **)malloc(sizeof(char*) * 100);
	while (i != 100)
	{
		new[i] = (char *)malloc(sizeof(char) * 100);
		new[i][0] = '\0';
		i++;
	}
	return (new);
}

void			reversesort(t_files **list)
{
	t_files		*p;
	t_files		*q;
	t_files		*r;

	p = *list;
	q = NULL;
	while (p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	*list = q;
}
