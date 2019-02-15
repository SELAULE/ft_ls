/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pls_free_this-shit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:07:58 by nselaule          #+#    #+#             */
/*   Updated: 2019/02/15 10:06:18 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		pls_free_this_shit(t_files **dlist)
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
			ptr->gname ? ft_memdel((void*)&ptr->gname) : 0;
			ptr->uname ? ft_memdel((void*)&ptr->uname) : 0;
			ptr->lnpath ? ft_memdel((void*)&ptr->lnpath) : 0;
			ptr->rights ? ft_memdel((void*)&ptr->rights) : 0;
			ptr->path ? ft_memdel((void*)&ptr->path) : 0;
			ptr ? ft_memdel((void*)&ptr) : 0;
			ptr = (*dlist);
		}
	}
	return ;
}
