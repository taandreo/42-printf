/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:06:24 by tairribe          #+#    #+#             */
/*   Updated: 2022/07/31 18:37:06 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_line(char *s, int len)
{
	int i;

	i = 0;
	while(i < len)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	printf(": ");
	printf("len: %i", len);
	printf("\n");
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

// int	print_fmt(char c, va_list args)
// {
// 	char	*s;
// 	int		len;

// 	if (!ft_strchr("cspdiuxX%", c))
// 	{
// 		ft_putchar_fd(c, 1);
// 		return (1);
// 	}
// 	s = get_str(c, args);
// 	ft_putstr_fd(s, 1);
// 	len = ft_strlen(s);
// 	free(s);
// 	if (c == 'c' && len == 0)
// 	{
// 		ft_putchar_fd(0, 1);
// 		return (1);
// 	}
// 	return (len);
// }