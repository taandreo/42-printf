/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:27:20 by tairan            #+#    #+#             */
/*   Updated: 2022/07/13 02:27:57 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_str(char c, va_list args)
{
	if (c == 'c')
		return (char_to_str(va_arg(args, int)));
	if (c == '%')
		return (ft_strdup("%"));
	if (c == 's')
		return get_string(va_arg(args, char*));
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
	if (c == 'c' && len == 0)
	{
		ft_putchar_fd(0, 1);
		return (1);
	}
	return (len);
}

void	init_flag(flag *f)
{
	f->left  = false;
	f->width = 0;
	f->zero  = false;
}

int format_parse(const char *s, va_list args)
{
	flag f;
	int i;

	i = -1;
	init_flag(&f);
	while(s[++i] && s[i] == '0')
		f.zero = true;
	while(ft_isdigit(s[i]))


}

int	ft_vprintf(const char *format, va_list args)
{
	int len;
	int i;
	int n;
	line l;

	i = 0;
	n = 0;

	len = ft_strlen(format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && i < len - 1)
		{
			i++;
			// n += print_fmt(format[i], args);
			format_parse(&format[i], args);
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
