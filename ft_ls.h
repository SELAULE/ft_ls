/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nselaule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:56:02 by nselaule          #+#    #+#             */
/*   Updated: 2018/11/06 09:30:53 by nselaule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LS_H
# define FT_LS_H
//# include <sys/sysmacros.h>
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct				s_helper
{
	int						fil;
	int						dir;
	int						i;
	char					**file;
	char					**dirs;
}							t_helper;

typedef struct				s_flags
{
	int						y;
	int						u;
	int						rem;
	int						x;
	int						l;
	int						r;
	int						a;
	int						rv;
	int						t;
	int						test;
	char					**arg;
}							t_flags;

typedef struct				s_files
{
	char					*name;
	char					*path;
	mode_t					st_mode;
	nlink_t					st_nlink;
	long					st_blocks;
	char					type;
	char					*rights;
	char					xattributes;
	int						links;
	char					*uname;
	char					*gname;
	long					size;
	struct timespec			laccess;
	struct timespec			ldatamod;
	struct timespec			lstatch;
	struct timespec			created;
	char					*lnpath;
	int						minor;
	int						major;
	int						blocks;
	struct s_files			*next;
}							t_files;

void						copy_flag(char **tab, int x,
							int z, t_flags *flags);
void						cparams(t_flags *flags,
							int i, t_helper *helper);
void						ft_param(t_flags *flags,
							t_helper *helper, int i);
void						check_file(t_flags *flags, t_helper *helper);
int							check_dirs(t_flags *flags, t_helper *helper, int x);
void						check_dirs2(t_flags *flags, t_files *dirs,
							int x, int first);
void						add_file_dir(t_files **files, char *name,
							char *dir);
t_files						*add_node(char *name, char *path);
char						gettype(struct stat filestats);
char						*getrights(struct stat filestats);
char						rights_9(struct stat filestats);
char						rights_6(struct stat filestats);
char						rights_3(struct stat filestats);
void						output(t_flags *flags, t_files *file, int i);
t_files						*sort_files(t_files *list, t_flags *flags);
void						sort(t_files **list, int (*cmp)
							(t_files *entry1, t_files *entry2));
void						swap_entry(t_files **a, t_files **b);
void						entry_cpy(t_files **src, t_files *cpy);
void						basicls(t_flags *flags, t_files *files);
void						lsprint(t_flags *flags, t_files *file, int i);
int							check_size(t_flags *flags, t_files *file);
void						lsprintlong(t_files *file);
void						lsprintlong2(t_files *file);
void						recur(t_flags *flags, t_files *files);
void						recur2(t_flags *flags, char *path);
int							link_new(t_files **file,
							struct dirent *dir, char *path);
t_flags						*init_flags(void);
void						swap_char(t_flags *flags, int i);
t_helper					*init_helper(void);
char						**create_char(void);
void						reversesort(t_files **list);
void						permisions(int size, int i, int y);
void						print_fill(char *name);
void						lsprintlong3(t_files *file);
int							cmp_time(t_files *entry1, t_files *entry2);
int							cmp_alpha(t_files *entry1, t_files *entry2);
void						no_directory(char *str);
void						illegal_options(char c);
void						perm_dnied(char *str);
void						poster_date(t_files *file);
void						clean_up(t_files **files);
//void						pls_free_this_shit(t_files **dlist);
#endif
