/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairan <tairan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:27:20 by tairan            #+#    #+#             */
/*   Updated: 2022/07/11 20:42:49 by tairan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

char	*char_to_str(char c)
{
	char *s;
	s = ft_calloc(2, 1);
	if (!s)
		return NULL;
	s[0] = c;
	return s;
}

char	*ft_str_toupper(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{	
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

char	*get_ptr(unsigned long p)
{
	char	*s;
	char	*tmp;
	
	s = ft_utoa(p, 16);
	tmp = ft_strjoin("0x", s);
	free(s);
	return (tmp);
}

char	*get_str(char c, va_list args)
{
	if (c == 'c')
		return (char_to_str(va_arg(args, int)));
	if (c == '%')
		return (ft_strdup("%"));
	if (c == 's')
		return ft_strdup(va_arg(args, char*));
	if (c == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (c == 'd')
		return(ft_itoa(va_arg(args, int)));
	if (c == 'u')
		return(ft_utoa(va_arg(args, unsigned int), 10));
	if (c == 'x')
		return(ft_utoa(va_arg(args, unsigned int), 16));
	if (c == 'X')
		return (ft_str_toupper(ft_utoa(va_arg(args, unsigned int), 16)));
	if (c == 'p')
		return(get_ptr((unsigned long) va_arg(args, void*)));
	return NULL;
}

int	print_fmt(char c, va_list args)
{
	char	*s;
	int		len;

	if (!ft_strchr("cspdiuxX%", c))
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
	s = get_str(c, args);
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	free(s);
	return (len - 1);
}

int	ft_vprintf(const char *format, va_list args)
{
	int len;
	int i;
	int n;

	i = 0;
	n = 0;

	len = ft_strlen(format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && i < len - 1)
		{
			i++;
			n += print_fmt(format[i], args);
		} 
		else {
			ft_putchar_fd(format[i], 1);
			n++;
		}
		i++;
	}		
	return(n);
}

int	ft_printf(const char *format, ...)
{
	int	len;
	va_list	args;
	va_start(args, format);
	len = ft_vprintf(format, args);
	va_end(args);
	return(len);
}
