/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairan <tairan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:17:38 by tairribe          #+#    #+#             */
/*   Updated: 2022/07/11 19:49:14 by tairan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned long n, int base)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n = n / base;
	}
	return (i);
}

char    *ft_utoa(unsigned long n, int base)
{

	int				re;
	int				size;
	char			*str_nb;

	if (base < 2 || base > 16)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	size = get_size(n, base);
	str_nb = ft_calloc(size + 1, sizeof(char));
	size--;
	while (n)
	{
		re = n % base;
		if (re > 9)
			str_nb[size--] = re - 10 + 'a';
		else
			str_nb[size--] = re + '0';
		n = n / base;
	}
	return (str_nb);
}

