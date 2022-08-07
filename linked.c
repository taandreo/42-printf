/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:40:51 by tairan            #+#    #+#             */
/*   Updated: 2022/08/07 12:32:23 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_printf.h>

void	print_list(t_list *list)
{
	int i;
	while(list)
	{
		i = *(int*)(list->content);
		printf("%i\n", i);
		list = list->next;
	}
}

int main(void)
{
	t_list *list;
	int		*n;
	int		*m;

	n = ft_calloc(1, sizeof(int));
	*n = 3;
	m = ft_calloc(1, sizeof(int));
	*m = 7;

	ft_lstadd_front(&list, ft_lstnew(n));
	ft_lstadd_front(&list, ft_lstnew(m));
	print_list(list);
}
