#include <stdio.h>
#include <ft_printf_bonus.h>
#include <ft_printf.h>


void	init_line(line *l)
{
	l->len = 4;
	l->line = NULL;
}

void	func1(void)
{
	line	test;
	test.len = 3;
	test.line = NULL;
	init_line(&test);

	printf("line: %s len: %i\n", test.line, test.len);
}

void	test_operators()
{
	int i = 0;
	char *str = "abacate";
	while(str[i])
	{
		ft_putchar_fd(str[i++], 1);
	}
}

int main(void)
{
	func1();
	test_operators();
	// char *s;
	// int len;
	// unsigned int n = +2147483648;
	// s = ft_utoa(n, 16);
	// printf("ft_utoa: %s\n", s);
	// printf("printf:  %x\n", n);

	// len = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf(" size: %i\n", len);
	// ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf(" size: %i\n", len);
	// ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf(" size: %i\n", len);
	// ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf(" size: %i\n", len);
	// s = NULL;
	// printf("%s", s);
	// printf(" size: %i\n", len);
}

