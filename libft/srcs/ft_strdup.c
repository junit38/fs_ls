/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:51:32 by jmery             #+#    #+#             */
/*   Updated: 2020/01/15 10:33:25 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft.h>

char	*ft_strdup(const char *str)
{
	char	*dup;

	dup = (char*)malloc(sizeof(dup) * (ft_strlen(str) + 1));
	if (dup)
		dup = ft_strcpy(dup, str);
	return (dup);
}
