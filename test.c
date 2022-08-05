/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tairribe <tairribe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 04:40:51 by tairan            #+#    #+#             */
/*   Updated: 2022/08/05 15:25:09 by tairribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_printf.h>
#include "limits.h"


void dot(void)
{
	// char *message = 
	// "************************\n"
	// "********   %.   ********\n"
	// "************************\n";
	// int int_buffer[] = { -32, 42, -900, 0, 2147483647, -2147483648 };
	// int i;
	int len;
	// i = 0;
	
	// printf("%s", message);
	// while (i < 6)
	// {
	// 	len = printf("printf:    \n", int_buffer[i]);
	// 	printf("len: %i\n", len);
	// 	len = ft_printf("ft_printf: %.10i\n", int_buffer[i]);
	// 	printf("len: %i\n", len);
	// 	i++;
	// }
	// printf("printf: ");
	// printf("");
	printf("ft_printf: ");
	len = ft_printf(" %.s ", "-");
}

void	zero(void)
{
	char *message = 
	"************************\n"
	"********   %0   ********\n"
	"************************\n";

	printf("%s", message);
	printf("printf: ");
	printf(" %04d ", -14);
	printf("\nft_printf: ");
	ft_printf(" %04d ", -14);
	printf("\nprintf: ");
	printf(" %05d ", -15);
	printf("\nft_printf: ");
	ft_printf(" %05d ", -15);
	printf("\nprintf: ");
	printf(" %06d ", -16);
	printf("\nft_printf: ");
	ft_printf(" %06d ", -16);
	// printf("\nprintf: ");
	// printf(" %011d ", LONG_MAX);
	// printf("\nft_printf: ");
	// ft_printf(" %011d ", LONG_MAX);
	// printf("\nprintf: ");
	// printf(" %013d ", UINT_MAX);
	// printf("\nft_printf: ");
	// ft_printf(" %013d ", UINT_MAX);
	// printf("\nprintf: ");
	// printf(" %014d ", ULONG_MAX);
	// printf("\nft_printf: ");
	// ft_printf(" %014d ", ULONG_MAX);
	// printf("\nprintf: ");
	// printf(" %015d ", 9223372036854775807LL);
	// printf("\nft_printf: ");
	// ft_printf(" %015d ", 9223372036854775807LL);
	// printf("\nprintf: ");
	// printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\nft_printf: ");
	// ft_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
}

void	dot2(void)
{	
	int len;

	// len = 0;
	// len = printf(" %04d \n", -14);
	// printf("len: %i\n", len);
	// len = ft_printf(" %04d \n", -14);
	// printf("len: %i\n", len);
	len = printf("printf: %.2i \n", -1);
	len = ft_printf("ft_printf %.2i \n", -1);
}

// void	space(void)
// {
// 	printf("1: |% s|\n", ""); // 1
// 	printf("2: |% 1s|\n", ""); // 2
// 	printf("3: |% 1s|\n", ""); // 3
// 	printf("4: |% s|\n", ""); // 4
// 	printf("5: |% s|\n", "-"); // 5
// 	printf("6: |% s|% s|\n", "", "-"); // 6
// 	printf("7: |% s|% s|\n", " - ", "");  // 7
// 	printf("8: |% s|% s|% s|% s|\n", " - ", "", "4", ""); // 8
// 	printf("9: |% s|% s|% s|% s|% s|\n", " - ", "", "4", "", "2 ");  //9
// }


// void space2(void)
// {
// 	printf("1:L% sL\n", "");
// 	printf("1:L% 1sL\n", " teste");
// 	printf("5:L% sL\n", " -"); // 5
// }

void	pre00(void)
{
	ft_printf("ft_printf: %01.d\n", 0);
	printf("printf:   %01.d\n", 0);
}

int main(void)
{
	// dot2();
	// zero();
	pre00();
	// char *message = 
	// "************************\n"
	// "********   %x   ********\n"
	// "************************\n";
	// int int_buffer[] = { -32, 42, -900, 0, 2147483647, -2147483648 };
	// int i;
	// int len;
	
	// printf("%s", message);

	// i = 0;
	// while (i < 6)
	// {
	// 	printf("decimal: %d\n", int_buffer[i]);
	// 	printf("printf:    %x\n", int_buffer[i]);
	// 	ft_printf("ft_printf: %x\n\n", int_buffer[i]);
	// 	i++;
	// }

	// printf("ALL:\n");
	// printf("%s %x %x %x\n","printf", int_buffer[0], int_buffer[1], int_buffer[5]);
	// ft_printf("%s %x %x %x\n","ft_printf", int_buffer[0], int_buffer[1], int_buffer[5]);

	// printf("\n");
	// message = 
	// "************************\n"
	// "********   %p   ********\n"
	// "************************\n";

	// printf("%s", message);
	// void *p = NULL;
	// char *s = "abacate";
	// int  *o = malloc(1 * sizeof(int));
	// len = printf("printf: %p %p %p", p, s, o);
	// printf(" size: %i\n", len);
	// ft_printf("ft_printf: %p %p %p", p, s, o);
	// printf(" size: %i\n", len);
	// printf("/////// %%X ///////\n");
	// printf("printf:    %X\n", -789);
	// ft_printf("ft_printf: %X\n", -789);	
}