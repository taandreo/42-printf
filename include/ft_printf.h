/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:02:25 by tairan            #+#    #+#             */
/*   Updated: 2022/08/05 20:05:49 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
char	*ft_utoa(unsigned long n, int base);
char	*char_to_str(char c);
char	*ft_str_toupper(char *s);
char	*get_ptr(unsigned long p);
char	*get_string(char *s);

#endif
