/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:46:35 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/23 19:06:05 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int		main(void)
{
	printf("* **************************************************** *\n");
	printf("*                                                      *\n");
	printf("*    printf's behavior with conversion specifier %%%%    *\n");
	printf("*                                                      *\n");
	printf("* **************************************************** *\n\n");

	printf("printf(\"%%%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |%%|\n\t\t") - 16);

	printf("printf(\"%%5%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |%5%|\n\t\t") - 16);

	printf("printf(\"%%-5%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |%-5%|\n\t\t") - 16);

	printf("printf(\"%%-%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |%-%|\n\t\t") - 16);

	printf("printf(\"%%*%%\", 5)\n");
	printf("return : %d\n", printf("\t\tresult : |%*%|\n\t\t", 5) - 16);

	printf("printf(\"%%*%%\", -5)\n");
	printf("return : %d\n", printf("\t\tresult : |%*%|\n\t\t", -5) - 16);

	printf("printf(\"%%.5%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |%.5%|\n\t\t") - 16);

	printf("printf(\"%%.-5%%\")\n");
	printf("\t\twarning : invalid conversion specifier '-'\n");

	printf("printf(\"%%.*%%\", -5)\n");
	printf("return : %d\n", printf("\t\tresult : |%.*%|\n\t\t", -5) - 16);

	printf("printf(\"%%.%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |%.%|\n\t\t") - 16);

	printf("printf(\"%%.0%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |%.0%|\n\t\t") - 16);

	printf("printf(\"%%05%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |%05%|\n\t\t") - 16);

	printf("printf(\"%% %%\")\n");
	printf("return : %d\n", printf("\t\tresult : |% %|\n\t\t") - 16);
	
	printf("printf(\"%% 05%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |% 05%|\n\t\t") - 16);

	printf("printf(\"%%-05%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |%-05%|\n\t\t") - 16);

	printf("printf(\"%%#5%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |%#5%|\n\t\t") - 16);

	printf("printf(\"%%+5%%\")\n");
	printf("return : %d\n", printf("\t\tresult : |%+5%|\n\t\t") - 16);
	printf("\n\n");
}
