/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 17:11:17 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <time.h>
# include <sys/xattr.h>

# include "structs.h"

/**
 * DATA.C
 */
t_data		*init_data(void);

/**
 * DIR.C
 */
int 		is_dir(char *path);
int 		is_file(char *path);
int         get_time(char *path);

/**
 * FT_LS.C
 */
void		ft_ls_dir(char *path, t_data *data, int is_alone);
void		ft_ls_file(char *path, t_data *data);

/**
 * FT_LS_2.C
 */
int			get_files_len(char **table);
int			get_dirs_len(char **table);
void		ft_ls_exist(char **table);
void		ft_ls_files(char **table, t_data *data);
void		ft_ls_dirs(char **table, t_data *data, int is_alone);

/**
 * FT_LS_3.C
 */
int			get_dir_len(char *path, t_data *data);

/**
 * INFO.C
 */
int			get_size_len(char *path);
void		get_data_info(char **table, t_data *data);
void		get_data_info_file(char **table, t_data *data);

/**
 * INFO_2.C
 */
int			get_nb_len(int size);
int			get_size_len(char *path);
int			get_nlink_len(char *path);
int			get_owner_len(char *path);
int			get_group_len(char *path);

/**
 * OPTIONS.C
 */
int			init_options(t_data *data, int argc, char **argv);
void		print_options(t_data *data);

/**
 * PATH.C
 */
char		*get_new_path(char *table, t_data *data);

/**
 * PRINT_INFO.C
 */
void		print_info(char *path, t_data *data);

/**
 * TABLE.C
 */
void		print_table(char **table, t_data *data);
void		reverse_table(char **table);
void		free_table(char **table);
char		**init_table(int len);

/**
 * TABLE_2.C
 */
void		sort_table(char **table);
void		sort_table_reverse(char **table);
void		sort_table_time(char **table, t_data *data);
void		swap_folders(char **table);

#endif
