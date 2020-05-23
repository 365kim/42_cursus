/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:46:35 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/24 00:43:17 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int		main(void)
{
	printf("* **************************************************** *\n");
	printf("*                                                      *\n");
	printf("*    printf's behavior with conversion specifier %%c    *\n");
	printf("*                                                      *\n");
	printf("* **************************************************** *\n\n");

	printf("printf(\"%%c\", 'a')\n");
	printf("return : %d\n", printf("\t\tresult : |%c|\n\t\t", 'a') - 16);

	printf("printf(\"%%-c\", 'a')\n");
	printf("return : %d\n", printf("\t\tresult : |%-c|\n\t\t", 'a') - 16);

	printf("printf(\"%%c\", '\\0')\n");
	printf("return : %d\n", printf("\t\tresult : |%c|\n\t\t", '\0') - 16);

	printf("printf(\"%%5c\", '\\0')\n");
	printf("return : %d\n", printf("\t\tresult : |%5c|\n\t\t", '\0') - 16);

	printf("printf(\"%%-5c\", '\\0')\n");
	printf("return : %d\n", printf("\t\tresult : |%-5c|\n\t\t", '\0') - 16);

	printf("printf(\"%%5c\", 'a')\n");
	printf("return : %d\n", printf("\t\tresult : |%5c|\n\t\t", 'a') - 16);

	printf("printf(\"%%-5c\", 'a')\n");
	printf("return : %d\n", printf("\t\tresult : |%-5c|\n\t\t", 'a') - 16);

	printf("printf(\"%%*c\", 5, 'a')\n");
	printf("return : %d\n", printf("\t\tresult : |%*c|\n\t\t", 5, 'a') - 16);

	printf("printf(\"%%*c\", -5, 'a')\n");
	printf("return : %d\n", printf("\t\tresult : |%*c|\n\t\t", -5, 'a') - 16);

	printf("printf(\"%%.c\", 'a')\n");
	printf("return : %d\n", printf("\t\tresult : |%.c|\n\t\t", 'a') - 16);

	printf("printf(\"%%.5c\", 'a')\n");
	printf("\t\tundefined behavior warning: precision used with 'c'\n");

	printf("printf(\"%%7.3c\", 'a')\n");
	printf("\t\tundefined behavior warning: precision used with 'c'\n");

	printf("printf(\"%%0c\", 'a')\n");
	printf("\t\tundefined behavior warning: flag '0' with 'c'\n");

	printf("printf(\"%%#c\", 'a')\n");
	printf("\t\tundefined behavior warning: flag '#' with 'c'\n");

	printf("printf(\"%% c\", 'a')\n");
	printf("\t\tundefined behavior warning: flag ' ' with 'c'\n");

	printf("printf(\"%%+c\", 'a')\n");
	printf("\t\tundefined behavior warning: flag '+' with 'c'\n");
	printf("\n\n");
}
