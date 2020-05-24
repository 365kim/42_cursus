/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:46:35 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/24 20:52:58 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int		main(void)
{
	printf("* **************************************************** *\n");
	printf("*                                                      *\n");
	printf("*    printf's behavior with conversion specifier %%d    *\n");
	printf("*                                                      *\n");
	printf("* **************************************************** *\n\n");

	printf("printf(\"%%d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%d|\n\t\t", 12345) - 16);

	printf("printf(\"%%d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%d|\n\t\t", -12345) - 16);

	printf("printf(\"%%3d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%3d|\n\t\t", 12345) - 16);

	printf("printf(\"%%7d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%7d|\n\t\t", 12345) - 16);

	printf("printf(\"%%-7d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-7d|\n\t\t", 12345) - 16);

	printf("printf(\"%%-d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-d|\n\t\t", 12345) - 16);

	printf("printf(\"%%*d\", 7, 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%*d|\n\t\t", 7, 12345) - 16);

	printf("printf(\"%%*d\", -7, 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%*d|\n\t\t", -7, 12345) - 16);

	printf("printf(\"%%.d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.d|\n\t\t", 12345) - 16);

	printf("printf(\"%%.0d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.0d|\n\t\t", 12345) - 16);

	printf("printf(\"%%.3d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.3d|\n\t\t", 12345) - 16);

	printf("printf(\"%%.7d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.7d|\n\t\t", 12345) - 16);

	printf("printf(\"%%-.7d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-.7d|\n\t\t", 12345) - 16);

	printf("printf(\"%%-9.7d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-9.7d|\n\t\t", 12345) - 16);

	printf("printf(\"%%9.7d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%9.7d|\n\t\t", 12345) - 16);

	printf("printf(\"%%-7.9d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-7.9d|\n\t\t", 12345) - 16);

	printf("printf(\"%%-3.7d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-3.7d|\n\t\t", 12345) - 16);

	printf("printf(\"%%-7.3d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-7.3d|\n\t\t", 12345) - 16);

	printf("printf(\"%%.3d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.3d|\n\t\t", -12345) - 16);

	printf("printf(\"%%.7d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.7d|\n\t\t", -12345) - 16);

	printf("printf(\"%%-.7d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-.7d|\n\t\t", -12345) - 16);

	printf("printf(\"%%-9.7d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-9.7d|\n\t\t", -12345) - 16);

	printf("printf(\"%%-7.9d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-7.9d|\n\t\t", -12345) - 16);

	printf("printf(\"%%-3.7d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-3.7d|\n\t\t", -12345) - 16);

	printf("printf(\"%%-7.3d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-7.3d|\n\t\t", -12345) - 16);

	printf("printf(\"%%0d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%0d|\n\t\t", 12345) - 16);
	
	printf("printf(\"%%07d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%07d|\n\t\t", 12345) - 16);

	printf("printf(\"%%d\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%d|\n\t\t", 0) - 16);

	printf("printf(\"%%3d\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%3d|\n\t\t", 0) - 16);

	printf("printf(\"%%3.d\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%3.d|\n\t\t", 0) - 16);

	printf("printf(\"%%03d\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%03d|\n\t\t", 0) - 16);

	printf("printf(\"%%09.0d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%09.0d|\n\t\t", 12345) - 16);

	printf("printf(\"%%09.7d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%09.7d|\n\t\t", 12345) - 16);

	printf("printf(\"%%07.9d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%07.9d|\n\t\t", 12345) - 16);

	printf("printf(\"%%.d\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%.d|\n\t\t", 0) - 16);

	printf("printf(\"%%.3d\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%.3d|\n\t\t", 0) - 16);

	printf("printf(\"%% d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |% d|\n\t\t", 12345) - 16);

	printf("printf(\"%% d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |% d|\n\t\t", -12345) - 16);

	printf("printf(\"%% -d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |% -d|\n\t\t", 12345) - 16);

	printf("printf(\"%% 3d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |% 3d|\n\t\t", 12345) - 16);

	printf("printf(\"%% 7d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |% 7d|\n\t\t", 12345) - 16);


	printf("printf(\"%%+d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+d|\n\t\t", 12345) - 16);

	printf("printf(\"%%+d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+d|\n\t\t", -12345) - 16);

	printf("printf(\"%%+-d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+-d|\n\t\t", 12345) - 16);

	printf("printf(\"%%+-9d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+-9d|\n\t\t", 12345) - 16);

	printf("printf(\"%%+9d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+9d|\n\t\t", 12345) - 16);

	printf("printf(\"%%+09d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+09d|\n\t\t", 12345) - 16);

	printf("printf(\"%%+09d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+09d|\n\t\t", -12345) - 16);

	printf("printf(\"%%-+09d\", 12345)\n");
	printf("\t\twarning : flag '0' is ignored when flag '-' is present\n");

	printf("printf(\"%%+ 09d\", 12345)\n");
	printf("\t\twarning : flag ' ' is ignored when flag '+' is present\n");

	printf("printf(\"%%+9.7d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+9.7d|\n\t\t", 12345) - 16);

	printf("printf(\"%%+09.7d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+09.7d|\n\t\t", 12345) - 16);

	printf("printf(\"%%+7.9d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+7.9d|\n\t\t", 12345) - 16);

	printf("printf(\"%%+07.9d\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+07.9d|\n\t\t", 12345) - 16);

	printf("printf(\"%%+9.7d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+9.7d|\n\t\t", -12345) - 16);

	printf("printf(\"%%+09.7d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+09.7d|\n\t\t", -12345) - 16);

	printf("printf(\"%%+7.9d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+7.9d|\n\t\t", -12345) - 16);

	printf("printf(\"%%+07.9d\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%+07.9d|\n\t\t", -12345) - 16);


	printf("printf(\"%%#d\", 0)\n");
	printf("\t\tundefined behavior warning: flag '#' with 'd'\n");

	printf("\n\n");
}
