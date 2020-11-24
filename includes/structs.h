/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/11/24 17:20:37 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_data
{
	int				l;
	int				rr;
	int				a;
	int				r;
	int				t;
	char			*path;
	int				size_len;
	int				nlink_len;
	int				owner_len;
	int				group_len;
}					t_data;

#endif
