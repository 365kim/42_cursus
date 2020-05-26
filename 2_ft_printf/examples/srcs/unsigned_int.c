/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:46:35 by mihykim           #+#    #+#             */
/*   Updated: 2020/05/26 14:54:27 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int		main(void)
{
	printf("* **************************************************** *\n");
	printf("*                                                      *\n");
	printf("*    printf's behavior with conversion specifier %%u    *\n");
	printf("*                                                      *\n");
	printf("* **************************************************** *\n\n");

	printf("printf(\"%%u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%u|\n\t\t", 12345) - 16);

	printf("printf(\"%%u\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%u|\n\t\t", -12345) - 16);

	printf("printf(\"%%3u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%3u|\n\t\t", 12345) - 16);

	printf("printf(\"%%7u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%7u|\n\t\t", 12345) - 16);

	printf("printf(\"%%-7u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-7u|\n\t\t", 12345) - 16);

	printf("printf(\"%%-u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-u|\n\t\t", 12345) - 16);

	printf("printf(\"%%*u\", 7, 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%*u|\n\t\t", 7, 12345) - 16);

	printf("printf(\"%%*u\", -7, 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%*u|\n\t\t", -7, 12345) - 16);

	printf("printf(\"%%.u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.u|\n\t\t", 12345) - 16);

	printf("printf(\"%%.0u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.0u|\n\t\t", 12345) - 16);

	printf("printf(\"%%.3u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.3u|\n\t\t", 12345) - 16);

	printf("printf(\"%%.7u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.7u|\n\t\t", 12345) - 16);

	printf("printf(\"%%-.7u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-.7u|\n\t\t", 12345) - 16);

	printf("printf(\"%%-9.7u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-9.7u|\n\t\t", 12345) - 16);

	printf("printf(\"%%9.7u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%9.7u|\n\t\t", 12345) - 16);

	printf("printf(\"%%-7.9u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-7.9u|\n\t\t", 12345) - 16);

	printf("printf(\"%%-3.7u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-3.7u|\n\t\t", 12345) - 16);

	printf("printf(\"%%-7.3u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-7.3u|\n\t\t", 12345) - 16);

	printf("printf(\"%%.3u\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.3u|\n\t\t", -12345) - 16);

	printf("printf(\"%%.7u\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%.7u|\n\t\t", -12345) - 16);

	printf("printf(\"%%-.7u\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-.7u|\n\t\t", -12345) - 16);

	printf("printf(\"%%-9.7u\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-9.7u|\n\t\t", -12345) - 16);

	printf("printf(\"%%-7.9u\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-7.9u|\n\t\t", -12345) - 16);

	printf("printf(\"%%-3.7u\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-3.7u|\n\t\t", -12345) - 16);

	printf("printf(\"%%-7.3u\", -12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%-7.3u|\n\t\t", -12345) - 16);

	printf("printf(\"%%0u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%0u|\n\t\t", 12345) - 16);
	
	printf("printf(\"%%07u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%07u|\n\t\t", 12345) - 16);

	printf("printf(\"%%u\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%u|\n\t\t", 0) - 16);

	printf("printf(\"%%3u\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%3u|\n\t\t", 0) - 16);

	printf("printf(\"%%3.u\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%3.u|\n\t\t", 0) - 16);

	printf("printf(\"%%03u\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%03u|\n\t\t", 0) - 16);

	printf("printf(\"%%09.0u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%09.0u|\n\t\t", 12345) - 16);

	printf("printf(\"%%09.7u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%09.7u|\n\t\t", 12345) - 16);

	printf("printf(\"%%07.9u\", 12345)\n");
	printf("return : %d\n", printf("\t\tresult : |%07.9u|\n\t\t", 12345) - 16);

	printf("printf(\"%%.u\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%.u|\n\t\t", 0) - 16);

	printf("printf(\"%%.3u\", 0)\n");
	printf("return : %d\n", printf("\t\tresult : |%.3u|\n\t\t", 0) - 16);

	printf("printf(\"%% u\", 12345)\n");
	printf("\t\tundefined behaviour warning : flag ' ' with 'u'\n");

	printf("printf(\"%%+u\", 12345)\n");
	printf("\t\tundefined behaviour warning : flag '+' with 'u'\n");

	printf("printf(\"%%#u\", 0)\n");
	printf("\t\tundefined behavior warning: flag '#' with 'u'\n");

	printf("\n\n");
}
