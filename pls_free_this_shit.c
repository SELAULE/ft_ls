/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pls_free_this-shit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:07:58 by nselaule          #+#    #+#             */
/*   Updated: 2018/09/24 16:50:10 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    pls_free_this_shit(t_files **dlist)
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
//			ptr->name ? ft_memdel((void*)&ptr->name) : 0;
			ptr->gname ? ft_memdel((void*)&ptr->gname) : 0;
			ptr->uname ? ft_memdel((void*)&ptr->uname) : 0;
//			ptr->dname ?ft_memdel((void*)&ptr->dname) : 0;
			ptr->lnpath ? ft_memdel((void*)&ptr->lnpath) : 0;
//			ptr->l ? ft_memdel((void*)&ptr->l) : 0;
			ptr->rights ? ft_memdel((void*)&ptr->rights) : 0;
			ptr->path ? ft_memdel((void*)&ptr->path) : 0;
			ptr ? ft_memdel((void*)&ptr) : 0;
			ptr = (*dlist);
		}
	}
	return ;
}
