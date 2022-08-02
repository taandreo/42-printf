/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:24:15 by tairribe          #+#    #+#             */
/*   Updated: 2022/08/01 21:37:35 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	append_zero(int size, t_line *l, t_bool ig_sign)
{
	char *s;
	char *tmp;
	
	if (ft_strchr("+-", l->line[0]))
	{
		s = ft_strdup(&l->line[1]);
		tmp = l->line;
		l->line = s;
		if (ig_sign)
			l->len--;
		s = add_char(size - l->len, '0');
		if (tmp[0] == '-')
			s = join(ft_strdup("-"), s);
		else 	
			s = join(ft_strdup("+"), s);
		free(tmp);
		l->line = join(s, l->line);
		l->len = ft_strlen(l->line);
	}
	else {
		s = add_char(size - l->len, '0');
		l->line = join(s, l->line);
		l->len = size;
	}
}	

void	add_precision(t_flag f, t_line *l)
{
	if (ft_strchr("iudxX", f.type))
	{
		if (l->line[0] == '0')
		{
			free(l->line);
			l->line = ft_strdup("");
		}
		if (f.precision > l->len)
			append_zero(f.precision, l, true);
		if (ft_strchr("+-", l->line[0]) && f.precision > l->len - 1)
			append_zero(f.precision, l, true);
	} 
	if (f.type == 's' && f.precision < l->len)
	{
		if (ft_strncmp("(null)", l->line, 6) == 0 && f.precision < 6)
		{
			l->len = 0;
			return ;
		}
		l->len = f.precision;
	}
}

void	add_pad(t_flag f, t_line *l)
{
	char *text;
	int pad_size;

	text = NULL;
	pad_size = f.width - l->len;
	text = ft_calloc(f.width, sizeof(char));
	if (f.left)
	{
		ft_memset(&text[l->len], f.ch, pad_size);
		ft_memcpy(text, l->line, l->len);
	}
	else
	{
		ft_memset(text, f.ch, pad_size);
		ft_memcpy(&text[pad_size], l->line, l->len);
	}
	free(l->line);
	l->line = text;
	l->len = f.width;
}

void	add_plus(t_line *l)
{
	if (l->line[0] != '-')
	{
		l->line = join(ft_strdup("+"), l->line);
		l->len++;
	}
}

void	add_space(t_flag f, t_line *l)
{
	if (l->line[0] != '-' && ft_strchr("uid", f.type))
	{
		l->line = join(ft_strdup(" "), l->line);
		l->len++;
	}
}

void	add_alt_form(t_flag f, t_line *l)
{
	if (f.type == 'x' && l->line[0] != '0')
	{
		l->line = join(ft_strdup("0x"), l->line);
		l->len += 2;
	}
	if (f.type == 'X' && l->line[0] != '0')
	{
		l->line = join(ft_strdup("0X"), l->line);
		l->len += 2;
	}
}

void	append_flag(t_list **list, t_flag f)
{
	t_line *l;
	l = ft_calloc(1, sizeof(t_line));

	l->line = f.arg_str;
	l->len  = f.arg_size;
	if (f.plus && ft_strchr("iud", f.type))
		add_plus(l);
	if (f.space && ft_strchr("iuds", f.type))
		add_space(f, l);
	if (f.precision >= 0)
		add_precision(f, l);
	if (f.hash && ft_strchr("xX", f.type))
		add_alt_form(f, l);
	if (f.ch == '0' && f.width - l->len > 0)
		append_zero(f.width, l, false);
	if (f.ch != '0' && f.width - l->len > 0)
		add_pad(f, l);
	ft_lstadd_back(list, ft_lstnew(l));
}