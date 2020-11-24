/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:52:17 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:21:29 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int		ft_getsizex(int x)
{
	int		size;

	size = 0;
	while (x > 9)
	{
		x = x / 10;
		size++;
	}
	return (size);
}

char	*ft_itoaneg(int n)
{
	char	*p;
	int		x;
	int		size;

	x = -n;
	n = -n;
	size = ft_getsizex(x);
	p = (char *)malloc(sizeof(p) * (size + 2));
	if (p)
	{
		p[size + 1] = '\0';
		while (size > 0)
		{
			x = n % 10;
			p[size] = 48 + x;
			n = n / 10;
			size--;
		}
		p[0] = '-';
	}
	return (p);
}

char	*ft_itoapos(int n)
{
	char	*p;
	int		x;
	int		size;

	x = n;
	size = 0;
	while (x > 9)
	{
		x = x / 10;
		size++;
	}
	p = (char *)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 10;
			p[size] = 48 + x;
			n = n / 10;
			size--;
		}
	}
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;

	p = NULL;
	if (n == -2147483648)
	{
		p = (char*)malloc(sizeof(p) * 12);
		if (p)
			p = "-2147483648";
		return (p);
	}
	if (n < 0)
		return (p = ft_itoaneg(n));
	else
		return (p = ft_itoapos(n));
	return (p);
}
