/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:02:25 by tairan            #+#    #+#             */
/*   Updated: 2022/07/31 21:02:00 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
// # include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_line
{
	int		len;
	char	*line;
}			t_line;

typedef struct s_flag
{
	t_bool	left;
	t_bool	is_flag;	
	t_bool	hash;
	t_bool	plus;
	t_bool	space;
	char	ch;
	char	type;
	int		width;
	int		read;
	int		precision;
	int		arg_size;
	char	*arg_str;
}			t_flag;


int		ft_printf(const char *format, ...);
// UTILS_00
char	*ft_utoa(unsigned long n, int base);
char	*char_to_str(char c);
char	*get_string(char *s);
char	*join(char *line, char *text);
char 	*add_char(int size, char c);
char	*ft_str_toupper(char *s);
// UTILS_01
char	*get_ptr(unsigned long p);
void	print_str(char *s, int len);
// VERBOSE
void	print_line(char *s, int len);
int		print_fmt(char c, va_list args);
void	print_flag(t_flag f);
// LINKED_LIST
size_t	print_list(t_list *lst);
void	free_line(void *v);
// ARG_PARSE
t_flag	arg_parse(const char *s, va_list args);
// APPEND_FLAG
void	append_flag(t_list **list, t_flag f);
void	append_str(t_list **list, const char *s, int size);

#endif
