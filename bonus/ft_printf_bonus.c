/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:27:20 by tairan            #+#    #+#             */
/*   Updated: 2022/07/26 22:21:47 by tairribe         ###   ########.fr       */
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

void	init_flag(t_flag *f)
{
	f->left     = false;
	f->is_flag  = false;
	f->ch       = ' ';
	f->width    = 0;
	f->read     = 0;
	f->arg_size = 0;
	f->arg_str  = NULL;
}

int	flag_check(const char *s, t_flag *f)
{
	int i;

	i = 0;
	while(ft_strchr("0-", s[i]))
	{
		if (s[i] == '0')
			f->ch = '0';
		if (s[i] == '-')
			f->left = true;
		i++;
	}
	if (f->ch == '0' && f->left)
		f->ch = ' ';
	return i;
}

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
		nb = ft_substr(s, 0, i);
		printf("nb: %s\n", nb);
		f->precision = ft_atoi(nb);
		free(nb);
	}
	return (i);
}

t_flag flag_parse(const char *s, va_list args)
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

void	print_flag(t_flag f)
{
	printf("read:      %i\n", f.read);
	printf("width:     %i\n", f.width);
	printf("ch:        %c\n", f.ch);
	printf("is_flag:   %i\n", f.is_flag);
	printf("left:      %i\n", f.left);
	printf("arg_str:   %s\n", f.arg_str);
	printf("arg_size:  %i\n", f.arg_size);
	printf("precision: %i\n\n", f.precision);
}

void	append_str(t_list **list, const char *s, int size)
{
	t_line *line;

	// printf("size: %i\n", size);	
	// printf("s: %s\n", s);	
	line = ft_calloc(1, sizeof(t_line));
	line->len  = size;
	line->line = ft_calloc(size, sizeof(char));
	ft_memcpy(line->line, s, size);
	ft_lstadd_back(list, ft_lstnew(line));
}

void	add_pad(t_flag f, t_line *l)
{

	char *text;
	int pad_size;

	text = NULL;
	pad_size = f.width - f.arg_size;
	
	if (pad_size > 0){
		text = ft_calloc(f.width, sizeof(char));
		if (f.left)
		{
			ft_memset(&text[f.arg_size], f.ch, pad_size);
			ft_memcpy(text, f.arg_str, f.arg_size);
		}
		else
		{
			ft_memset(text, f.ch, pad_size);
			ft_memcpy(&text[pad_size], f.arg_str, f.arg_size);
		}
		l->line = text;
		l->len = f.width;
		free(f.arg_str);
	} 
	else {
		l->line = f.arg_str;
		l->len = f.arg_size;
	}
}

void	append_flag(t_list **list, t_flag f)
{
	t_line *line;
	line = ft_calloc(1, sizeof(t_line));

	add_pad(f, line);
	ft_lstadd_back(list, ft_lstnew(line));
}

void	print_line(t_line l)
{
	int i;
	char *s;

	s = l.line;
	i = 0;
	while(i < l.len)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}

size_t	print_list(t_list *lst)
{
	size_t size;
	t_line *l;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		l = lst->content;
		print_line(*l);
		size += l->len;
		lst = lst->next;
	}
	return(size);
}

int	ft_vprintf(const char *format, va_list args)
{
	int 	len;
	int 	i;
	int 	n;
	t_list 	*list;
	t_flag	f;

	i = 0;
	n = 0;

	list = NULL;
	len = ft_strlen(format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && i < len - 1)
		{
			f = flag_parse(&format[i], args);
			print_flag(f);
			if (f.is_flag)
			{
				append_str(&list, &format[n], i - n);
				append_flag(&list, f);
				i += f.read;
				n = i;
			} 
			else {
				i++;
			}
		} else {
			i++;
		}
	}
	append_str(&list, &format[n], i - n);
	len = print_list(list);
	ft_lstclear(&list, free_line);
	return (len);
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
