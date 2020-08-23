/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 13:46:35 by mihykim           #+#    #+#             */
/*   Updated: 2020/08/23 19:42:52 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int		main(void)
{
	printf("* **************************************************** *\n");
	printf("*                                                      *\n");
	printf("*    printf's behavior with conversion specifier %%p    *\n");
	printf("*                                                      *\n");
	printf("* **************************************************** *\n\n");

	char *ptr;
	void *void_ptr;

	printf("printf(\"%%p\", ptr)\n");
	printf("return : %d\n", printf("\t\tresult : |%p|\n\t\t", ptr) - 16);

	printf("printf(\"%%p\", void_ptr)\n");
	printf("return : %d\n", printf("\t\tresult : |%p|\n\t\t", void_ptr) - 16);

	printf("printf(\"%%p\", NULL)\n");
	printf("return : %d\n", printf("\t\tresult : |%p|\n\t\t", NULL) - 16);

	printf("printf(\"%%5p\", ptr)\n");
	printf("return : %d\n", printf("\t\tresult : |%5p|\n\t\t", ptr) - 16);

	printf("printf(\"%%10p\", ptr)\n");
	printf("return : %d\n", printf("\t\tresult : |%10p|\n\t\t", ptr) - 16);

	printf("printf(\"%%15p\", ptr)\n");
	printf("return : %d\n", printf("\t\tresult : |%15p|\n\t\t", ptr) - 16);

	printf("printf(\"%%-15p\", ptr)\n");
	printf("return : %d\n", printf("\t\tresult : |%-15p|\n\t\t", ptr) - 16);

	printf("printf(\"%%-p\", ptr)\n");
	printf("return : %d\n", printf("\t\tresult : |%-p|\n\t\t", ptr) - 16);

	printf("printf(\"%%*p\", 15, ptr)\n");
	printf("return : %d\n", printf("\t\tresult : |%*p|\n\t\t", 15, ptr) - 16);

	printf("printf(\"%%*p\", -15, ptr)\n");
	printf("return : %d\n", printf("\t\tresult : |%*p|\n\t\t", -15, ptr) - 16);

	printf("printf(\"%%.p\", ptr)\n");
	printf("return : %d\n", printf("\t\tresult : |%.p|\n\t\t", ptr) - 16);

	printf("printf(\"%%.p\", void_ptr)\n");
	printf("return : %d\n", printf("\t\tresult : |%.p|\n\t\t", void_ptr) - 16);

	printf("printf(\"%%.p\", NULL)\n");
	printf("return : %d\n", printf("\t\tresult : |%.p|\n\t\t", NULL) - 16);

	printf("printf(\"%%.0p\", ptr)\n");
	printf("\t\tundefined behavior warning: precision used with 'p'\n");

	printf("printf(\"%%.5p\", ptr)\n");
	printf("\t\tundefined behavior warning: precision used with 'p'\n");

	printf("printf(\"%%0p\", ptr)\n");
	printf("\t\tundefined behavior warning: flag '0' with 'p'\n");

	printf("printf(\"%% p\", ptr)\n");
	printf("\t\tundefined behavior warning: flag ' ' with 'p'\n");
	
	printf("printf(\"%%#p\", ptr)\n");
	printf("\t\tundefined behavior warning: flag '#' with 'p'\n");

	printf("printf(\"%%+p\", ptr)\n");
	printf("\t\tundefined behavior warning: flag '+' with 'p'\n");
	printf("\n\n");
}
