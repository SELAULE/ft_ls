/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:46:27 by nselaule          #+#    #+#             */
/*   Updated: 2018/09/22 13:46:36 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		gettype(struct stat filestats)
{
	if (S_ISFIFO(filestats.st_mode))
		return ('p');
	else if (S_ISCHR(filestats.st_mode))
		return ('c');
	else if (S_ISDIR(filestats.st_mode))
		return ('d');
	else if (S_ISBLK(filestats.st_mode))
		return ('b');
	else if (S_ISREG(filestats.st_mode))
		return ('-');
	else if (S_ISLNK(filestats.st_mode))
		return ('l');
	else if (filestats.st_mode & S_IFSOCK)
		return ('s');
	else
		return ('-');
}

char		*getrights(struct stat filestats)
{
	char	*rights;

	rights = (char*)malloc(10);
	rights[0] = (filestats.st_mode & S_IRUSR) ? 'r' : '-';
	rights[1] = (filestats.st_mode & S_IWUSR) ? 'w' : '-';
	rights[2] = rights_3(filestats);
	rights[3] = (filestats.st_mode & S_IRGRP) ? 'r' : '-';
	rights[4] = (filestats.st_mode & S_IWGRP) ? 'w' : '-';
	rights[5] = rights_6(filestats);
	rights[6] = (filestats.st_mode & S_IROTH) ? 'r' : '-';
	rights[7] = (filestats.st_mode & S_IWOTH) ? 'w' : '-';
	rights[8] = rights_9(filestats);
	rights[9] = '\0';
	return (rights);
}

char		rights_9(struct stat filestats)
{
	if (filestats.st_mode & S_ISVTX && !(filestats.st_mode & S_IXOTH))
		return ('T');
	else if (filestats.st_mode & S_ISVTX && (filestats.st_mode & S_IXOTH))
		return ('t');
	else if (!(filestats.st_mode & S_ISVTX) && (filestats.st_mode & S_IXOTH))
		return ('x');
	else
		return ('-');
}

char		rights_6(struct stat filestats)
{
	if (filestats.st_mode & S_ISGID && !(filestats.st_mode & S_IXGRP))
		return ('S');
	else if (filestats.st_mode & S_ISGID && (filestats.st_mode & S_IXGRP))
		return ('s');
	else if (!(filestats.st_mode & S_ISGID) && (filestats.st_mode & S_IXGRP))
		return ('x');
	else
		return ('-');
}

char		rights_3(struct stat filestats)
{
	if (filestats.st_mode & S_ISUID && !(filestats.st_mode & S_IXUSR))
		return ('S');
	else if (filestats.st_mode & S_ISUID && (filestats.st_mode & S_IXUSR))
		return ('s');
	else if (!(filestats.st_mode & S_ISUID) && (filestats.st_mode & S_IXUSR))
		return ('x');
	else
		return ('-');
}
