#include "ft_printf.h"
#include "stdio.h"

int		main(void)
{
	char *s1 = "grape";
	char *s2 = "fruit";
	int	n = -258;

	printf("%d\n", printf("Hello World\n"));
	printf("%d\n", ft_printf("Hello World\n"));
	printf("%d\n", printf("%s\n%s%c\n", s1, s2, '!'));
	printf("%d\n", ft_printf("%s\n%s%c\n", s1, s2, '!'));
	printf("\n");

	printf("%x, %#x\n", n, n);
	ft_printf("%x, %#x\n", n, n);
	printf("\n");

	printf("%d\n", printf("%X, %#X\n", n, n));
	printf("%d\n", ft_printf("%X, %#X\n", n, n));
	return (0);
}
