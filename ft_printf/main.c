#include "ft_printf.h"
#include "stdio.h"

int		main(void)
{
	char *s1 = "grape";
	char *s2 = "fruit";
	int n1 = 2147483647;
	int	n2 = -2147483647;
	int	n3 = 2147482647;

	printf("p로 주소출력, 옵션%%16p\n");
	printf("(%d)", printf("  r : %16p\n", s1) - 7);
	printf("(%d)", ft_printf("  f : %16p\n", s1) - 7);
	printf("\n\n");

	printf("\"\"로 글자출력\n");
	printf("(%d)", printf("  r : grape\n") - 7);
	printf("(%d)", ft_printf("  f : grape\n") - 7);
	printf("\n\n");

 	printf("c,s로 글자출력, 옵션 %%-5c\n");
	printf("(%d)", printf("  r : %s%s||%-5c||\n", s1, s2, '!') - 7);
	printf("(%d)", ft_printf("  f : %s%s||%-5c||\n", s1, s2, '!') - 7);
	printf("\n\n");

 	printf("s로 글자출력, 옵션%%10s\n");
	printf("(%d)", printf("  r : ||%10s||\n", s1) - 7);
	printf("(%d)", ft_printf("  f : ||%10s||\n", s1) - 7);
	printf("\n\n");

 	printf("s로 글자출력, 옵션%%-10s\n");
	printf("(%d)", printf("  r : ||%-10s||\n", s1) - 7);
	printf("(%d)", ft_printf("  f : ||%-10s||\n", s1) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%-16d\n");
	printf("(%d)", printf("  r : ||%-16d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%-16d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%----16d\n");
	printf("(%d)", printf("  r : ||%----16d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%----16d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%- 16d\n");
	printf("(%d)", printf("  r : ||%- 16d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%- 16d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%% 016d\n");
	printf("(%d)", printf("  r : ||%0 16d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%0 16d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%-+16d\n");
	printf("(%d)", printf("  r : ||%-+16d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%-+16d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%+16d\n");
	printf("(%d)", printf("  r : ||%+16d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%+16d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%+016d\n");
	printf("(%d)", printf("  r : ||%+016d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%+016d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%016d\n");
	printf("(%d)", printf("  r : ||%016d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%016d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 양수출력, 옵션%%000016d\n");
	printf("(%d)", printf("  r : ||%000016d||\n", n1) - 7);
	printf("(%d)", ft_printf("  f : ||%000016d||\n", n1) - 7);
	printf("\n\n");

	printf("d로 0 출력, 옵션%%+d\n");
	printf("(%d)", printf("  r : ||%+d||\n", -0) - 7);
	printf("(%d)", ft_printf("  f : ||%+d||\n", -0) - 7);
	printf("\n\n");

	printf("d로 0 출력, 옵션%%+06d\n");
	printf("(%d)", printf("  r : ||%+06d||\n", 0) - 7);
	printf("(%d)", ft_printf("  f : ||%+06d||\n", 0) - 7);
	printf("\n\n");

	printf("d로 +0 출력, 옵션%%+06d\n");
	printf("(%d)", printf("  r : ||%+06d||\n", +0) - 7);
	printf("(%d)", ft_printf("  f : ||%+06d||\n", +0) - 7);
	printf("\n\n");

	printf("d로 음수출력, 옵션%%-16d\n");
	printf("(%d)", printf("  r : ||%-16d||\n", n2) - 7);
	printf("(%d)", ft_printf("  f : ||%-16d||\n", n2) - 7);
	printf("\n\n");

	printf("d로 음수출력, 옵션%%+16d\n");
	printf("(%d)", printf("  r : ||%+16d||\n", n2) - 7);
	printf("(%d)", ft_printf("  f : ||%+16d||\n", n2) - 7);
	printf("\n\n");

	printf("d로 음수출력, 옵션%%000016d\n");
	printf("(%d)", printf("  r : ||%000016d||\n", n2) - 7);
	printf("(%d)", ft_printf("  f : ||%000016d||\n", n2) - 7);
	printf("\n\n");

	printf("x로 unsigned 16진수출력, 옵션%%x   %%#20x\n");
	printf("(%d)", printf("  r : %x, ||%#20x||\n", n3, n3) - 7);
	printf("(%d)", ft_printf("  f : %x, ||%#20x||\n", n3, n3) - 7);
	printf("\n\n");

	printf("X로 unsigned 16진수출력, 옵션%%0X   %%#-20X\n");
	printf("(%d)", printf("  r : %0X, ||%#-20X||\n", n3, n3) - 7);
	printf("(%d)", ft_printf("  f : %0X, ||%#-20X||\n", n3, n3) - 7);
	printf("\n\n");

	printf("%%로 %%출력\n");
	printf("(%d)", printf("  r : %%\n") - 7);
	printf("(%d)", ft_printf("  f : %%\n") - 7);
	printf("\n\n");

	printf("%%로 %%출력, 옵션%%10%%\n");
	printf("(%d)", printf("  r : ||%10%||\n") - 7);
	printf("(%d)", ft_printf("  f : ||%10%||\n") - 7);

	system("leaks a.out > leaks_result; cat leaks_result | grep leaked");
	return (0);
}
