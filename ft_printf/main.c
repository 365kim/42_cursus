#include "ft_printf.h"
#include "stdio.h"

int		main(void)
{
	char *s1 = "grape";
	char *s2 = "fruit";
	int n1 = 2147483647;
	int	n2 = -2147483647;
	int	n3 = 2147482647;

	printf("p로 주소출력\n");
	printf("(%d)", printf("  r : %p\n", s1) - 7);
	printf("(%d)", ft_printf("  f : %p\n", s1) - 7);
	printf("\n\n");

	printf("\"\"로 글자출력\n");
	printf("(%d)", printf("  r : grape\n") - 7);
	printf("(%d)", ft_printf("  f : grape\n") - 7);
	printf("\n\n");

 	printf("c,s로 글자출력\n");
	printf("(%d)", printf("  r : %s %s %c\n", s1, s2, '!') - 7);
	printf("(%d)", ft_printf("  f : %s %s %c\n", s1, s2, '!') - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%-6\n");
	printf("(%d)", printf("  r : ||%-6d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%-6d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%----6\n");
	printf("(%d)", printf("  r : ||%----6d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%----6d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 음수출력, 옵션%%-6\n");
	printf("(%d)", printf("  r : ||%-6d||\n", n2) - 7);
	printf("(%d)", ft_printf("  f : ||%-6d||\n", n2) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%06\n");
	printf("(%d)", printf("  r : ||%06d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%06d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%00006\n");
	printf("(%d)", printf("  r : ||%00006d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%00006d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 음수출력, 옵션%%06\n");
	printf("(%d)", printf("  r : ||%06d||\n", n2) - 7);
	printf("(%d)", ft_printf("  f : ||%06d||\n", n2) - 7);
	printf("\n\n");

	printf("d로 음수출력, 옵션%%00006\n");
	printf("(%d)", printf("  r : ||%00006d||\n", n2) - 7);
	printf("(%d)", ft_printf("  f : ||%00006d||\n", n2) - 7);
	printf("\n\n");

	printf("x로 unsigned 16진수출력\n");
	printf("(%d)", printf("  r : %x, %#x\n", n3, n3) - 7);
	printf("(%d)", ft_printf("  f : %x, %#x\n", n3, n3) - 7);
	printf("\n\n");

	printf("X로 unsigned 16진수출력\n");
	printf("(%d)", printf("  r : %X, %#X\n", n3, n3) - 7);
	printf("(%d)", ft_printf("  f : %X, %#X\n", n3, n3) - 7);
	printf("\n\n");

	printf("%%로 %%출력\n");
	printf("(%d)", printf("  r : %%\n") - 7);
	printf("(%d)", ft_printf("  f : %%\n") - 7);

	return (0);
}
