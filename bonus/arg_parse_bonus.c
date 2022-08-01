/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:24:15 by tairribe          #+#    #+#             */
/*   Updated: 2022/07/31 21:10:10 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_width(const char *s, t_flag *f)
{
	int i;
	char *nb;

	i = 0;
	while(ft_isdigit(s[i]))
		i++;
	nb = ft_substr(s, 0, i);
	f->width = ft_atoi(nb);
	free(nb);
	return (i);
}

int	get_precision(const char *s, t_flag *f)
{
	int i;
	char *nb;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		while(ft_isdigit(s[i]))
			i++;
		nb = ft_substr(s, 1, i);
		f->precision = ft_atoi(nb);
		free(nb);
	}
	return (i);
}

void	init_flag(t_flag *f)
{
	f->left      = false;
	f->is_flag   = false;
	f->hash		 = false;
	f->plus		 = false;
	f->space	 = false;
	f->ch        = ' ';
	f->type      = ' ';
	f->width     = 0;
	f->read      = 0;
	f->arg_size  = 0;
	f->arg_str   = NULL;
	f->precision = -1;
}

int	flag_check(const char *s, t_flag *f)
{
	int i;

	i = 0;
	while(ft_strchr("0-#+ ", s[i]))
	{
		if (s[i] == '0')
			f->ch = '0';
		if (s[i] == '#')
			f->hash = true;
		if (s[i] == '-')
		{
			f->left = true;
			f->ch = ' ';
		}
		if (s[i] == ' ')
			f->space = true;
		if (s[i] == '+')
		{
			f->plus = true;
			f->space = false;
		}
		i++;
	}		
	return i;
}

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

t_flag	arg_parse(const char *s, va_list args)
{
	t_flag f;
	int i;

	i = 1;
	init_flag(&f);
	i += flag_check(&s[i], &f);
	i += get_width(&s[i], &f);
	i += get_precision(&s[i], &f);
	if (ft_strchr("cspdiuxX%", s[i]))
	{
		f.arg_str = get_str(s[i], args);
		f.type = s[i];
		if (s[i] == 'c')
			f.arg_size = 1;
		else
			f.arg_size = ft_strlen(f.arg_str);
		f.is_flag = true;
		i++;
	}
	f.read = i;
	return (f); 
}