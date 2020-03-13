#include "ft_printf.h"
#include "stdio.h"

int		main(void)
{
	char *s1 = "grape";
	char *s2 = "fruit";
	int	n = -258;

	printf("%d\n", printf("r : aa%5daa\n", -1234));
	printf("%d\n", ft_printf("f : aa%5daa\n", -1234));
	printf("\n");

	printf("r : %5s\n", s1);
	ft_printf("f : %5s\n", s1);
	printf("r : %-.2s\n", s1);
	printf("\n");

	printf("%d\n", printf("r : %s\n%s%c\n", s1, s2, '!'));
	printf("%d\n", ft_printf("f : %s\n%s%c\n", s1, s2, '!'));
	printf("\n");

	printf("r : %x, %#x\n", n, n);
	ft_printf("f : %x, %#x\n", n, n);
	printf("\n");

	printf("%d\n", printf("r : %X, %#X\n", n, n));
	printf("%d\n", ft_printf("f : %X, %#X\n", n, n));
	return (0);
}
