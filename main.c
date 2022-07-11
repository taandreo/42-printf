#include <stdio.h>
#include <ft_printf.h>

int main(void)
{
	char *s;
	unsigned int n = +2147483648;
	s = ft_utoa(n, 16);
	printf("ft_utoa: %s\n", s);
	printf("printf:  %x\n", n);
}