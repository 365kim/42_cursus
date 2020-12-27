/* *********************************************************************** */
/*                                                                         */
/*                                                     :::      ::::::::   */
/*   main.c                                          :+:      :+:    :+:   */
/*                                                 +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                             +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 18:30:17 by mihykim        #+#    #+#             */
/*   Updated: 2020/12/22 01:14:45 by mihykim          ###   ########.fr       */
/*                                                                         */
/* *********************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int		ft_strlen(char const *str);
char	*ft_strcpy(char *dst, char const *src);
int		ft_strcmp(char const *s1, char const *s2);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strdup(char const *s1);

int	main(void)
{

	int		i;
	long	r;
	char	buffer[33];
	char	buffer2[33];
	char	*var;
	char	*var2;

	var = "";
	var2 = "";
	r = 0;
	i = 0;
	while (i < 33)
	{
		buffer[i] = '\0';
		buffer2[i] = '\0';
		i++;
	}

	printf("--------- RESULT [1] ft_strlen.s ----------\n\n");
	var = "";
	printf("%8s => [ft: %2d]\n", var, ft_strlen(var));
	var = "365kim";
	printf("%8s => [ft: %2d]\n", var, ft_strlen(var));
	printf("\n\n\n");

	printf("--------- RESULT [2] ft_strcpy.s ----------\n\n");
	var = "";
	printf("%8s => [ft: %8s]\n", var, ft_strcpy(buffer, var));
	var = "42Seoul";
	printf("%8s => [ft: %8s]\n", var, ft_strcpy(buffer, var));
	printf("\n\n\n");

	printf("--------- RESULT [3] ft_strcmp.s ----------\n\n");
	var = "";
	var2 = "";
	printf("%8s vs %8s => [ft: %2d]\n", var, var2, ft_strcmp(var, var2));
	var = "365kim";
	printf("%8s vs %8s => [ft: %2d]\n", var, var2, ft_strcmp(var, var2));
	var2 = "365kim";
	printf("%8s vs %8s => [ft: %2d]\n", var, var2, ft_strcmp(var, var2));
	var2 = NULL;
	printf("%8s vs %8s => [ft: %2d]\n", var, var2, ft_strcmp(var, var2));
	var = NULL;
	printf("%8s vs %8s => [ft: %2d]\n", var, var2, ft_strcmp(var, var2));
	var2 = "365kim";
	printf("%8s vs %8s => [ft: %2d]\n", var, var2, ft_strcmp(var, var2));
	printf("\n\n\n");

	printf("--------- RESULT [4] ft_write.s ----------\n\n");
	var = "365kim";
	i = 0;
	printf("  [ft: %zd] <= %8s %d \n", ft_write(STDOUT_FILENO, var, i), var, i);
	i = 4;
	printf("  [ft: %zd] <= %8s %d \n", ft_write(STDOUT_FILENO, var, i), var, i);
	printf("\n\n\n");

	printf("--------- RESULT [5] ft_read.s ----------\n\n");ki
	i = 18;
	r = ft_read(STDIN_FILENO, buffer, i); 
	printf("[ft: %2ld] %s\n", r, buffer);
	i = 14;
	r = ft_read(STDIN_FILENO, buffer2, i); 
	printf("[ft: %2ld] %s\n", r, buffer2);
	printf("\n\n\n");

	printf("--------- RESULT [6] ft_strdup.s ----------\n\n");
	var = NULL;
	var2 = ft_strdup(var);
	printf("%15s => [ft: %15s]\n", var, var2);
	free(var2);
	var = "Merry_Christmas";
	var2 = ft_strdup(var);
	printf("%15s => [ft: %15s]\n", var, var2);
	free(var2);

	return (0);
}


