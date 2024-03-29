/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:53:49 by tairribe          #+#    #+#             */
/*   Updated: 2022/08/05 21:33:02 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	free_line(void *v)
{
	t_line	*l;

	l = (t_line *)v;
	free(l->line);
	free(l);
}

static void	print_str(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}

size_t	print_list(t_list *lst)
{
	size_t	size;
	t_line	*l;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		l = lst->content;
		print_str(l->line, l->len);
		size += l->len;
		lst = lst->next;
	}
	return (size);
}

void	append_str(t_list **list, const char *s, int size)
{
	t_line	*line;

	if (size <= 0)
		return ;
	line = ft_calloc(1, sizeof(t_line));
	line->len = size;
	line->line = ft_calloc(size, sizeof(char));
	ft_memcpy(line->line, s, size);
	ft_lstadd_back(list, ft_lstnew(line));
}
