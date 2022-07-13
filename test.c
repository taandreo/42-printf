/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:40:51 by tairan            #+#    #+#             */
/*   Updated: 2022/07/13 01:41:41 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_printf.h>

int main(void)
{
	char *message = 
	"************************\n"
	"********   %x   ********\n"
	"************************\n";
	int int_buffer[] = { -32, 42, -900, 0, 2147483647, -2147483648 };
	int i;
	int len;
	
	printf("%s", message);

	i = 0;
	while (i < 6)
	{
		printf("decimal: %d\n", int_buffer[i]);
		printf("printf:    %x\n", int_buffer[i]);
		ft_printf("ft_printf: %x\n\n", int_buffer[i]);
		i++;
	}

	printf("ALL:\n");
	printf("%s %x %x %x\n","printf", int_buffer[0], int_buffer[1], int_buffer[5]);
	ft_printf("%s %x %x %x\n","ft_printf", int_buffer[0], int_buffer[1], int_buffer[5]);

	printf("\n");
	message = 
	"************************\n"
	"********   %p   ********\n"
	"************************\n";

	printf("%s", message);
	void *p = NULL;
	char *s = "abacate";
	int  *o = malloc(1 * sizeof(int));
	len = printf("printf: %p %p %p", p, s, o);
	printf(" size: %i\n", len);
	ft_printf("ft_printf: %p %p %p", p, s, o);
	printf(" size: %i\n", len);
	// printf("/////// %%X ///////\n");
	// printf("printf:    %X\n", -789);
	// ft_printf("ft_printf: %X\n", -789);	
}