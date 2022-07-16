/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairan <tairan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:02:25 by tairan            #+#    #+#             */
/*   Updated: 2022/07/11 19:51:50 by tairan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
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
	t_bool	zero;
	int		width;
	t_bool	left;
}			t_flag;

int		ft_printf(const char *format, ...);
char	*ft_utoa(unsigned long n, int base);
char	*char_to_str(char c);
char	*ft_str_toupper(char *s);
char	*get_ptr(unsigned long p);
char	*get_string(char *s);

#endif
