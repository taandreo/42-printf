/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairan <tairan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:40:51 by tairan            #+#    #+#             */
/*   Updated: 2022/07/11 07:19:01 by tairan           ###   ########.fr       */
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
	// printf("/////// %%X ///////\n");
	// printf("printf:    %X\n", -789);
	// ft_printf("ft_printf: %X\n", -789);

	// printf("/////// %%X ///////\n");
	// printf("printf:    %X\n", -789);
	// ft_printf("ft_printf: %X\n", -789);	
}