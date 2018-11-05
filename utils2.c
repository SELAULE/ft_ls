/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:53:52 by nselaule          #+#    #+#             */
/*   Updated: 2018/11/05 16:47:02 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		permisions(int size, int i, int y)
{
	char	*num;
	char	*tmp;

	num = (char *)malloc(sizeof(char) * 9);
	num[0] = ' ';
	num[1] = ' ';
	num[2] = ' ';
	num[3] = ' ';
	num[4] = ' ';
	num[5] = ' ';
	num[6] = ' ';
	num[7] = ' ';
	num[8] = '\0';
	tmp = ft_itoa(size);
	y = ft_strlen(tmp);
	while (y != -1)
	{
		num[i] = tmp[y];
		y--;
		i--;
	}
	ft_putstr(num);
}

void		print_fill(char *name)
{
	int i;

	i = 0;
	ft_putstr(name);
	i = ft_strlen(name);
	if (i == 3)
		ft_putstr("         ");
	if (i == 5)
		ft_putstr("       ");
	if (i == 8)
		ft_putstr("    ");
	if (i == 10)
		ft_putstr("  ");
}

void		lsprintlong3(t_files *file)
{
	if (file->size == 0)
	{
		ft_putstr("     ");
		ft_putnbr(file->size);
	}
	else
		permisions(file->size, 8, 0);
	ft_putchar(' ');
}

int			cmp_time(t_files *entry1, t_files *entry2)
{
	if (entry1->ldatamod.tv_sec < entry2->ldatamod.tv_sec)
		return (entry1->ldatamod.tv_sec < entry2->ldatamod.tv_sec);
	else if (entry1->ldatamod.tv_sec == entry2->ldatamod.tv_sec)
	{
		if (entry1->ldatamod.tv_nsec < entry2->ldatamod.tv_nsec)
			return (entry1->ldatamod.tv_nsec < entry2->ldatamod.tv_nsec);
		else if (entry1->ldatamod.tv_nsec == entry2->ldatamod.tv_nsec)
			return (ft_strcmp(entry1->name, entry2->name));
	}
	return (0);
}

int			cmp_alpha(t_files *entry1, t_files *entry2)
{
	return (ft_strcmp(entry1->name, entry2->name));
}
