//
// Created by Dmytrii Spyrydonov on 4/14/17.
//
#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int	my;
	int	orig;

	my = ft_printf("my1 = %-+10da\n", 42);
	orig = printf("or1 = %-+10da\n", 42);
	printf("my1 = %d\nor1 = %d\n--------------------\n", my, orig);
	my = ft_printf("my2 = %-010da\n", 42);
	orig = printf("or2 = %-010da\n", 42);
	printf("my2 = %d\nor2 = %d\n--------------------\n", my, orig);
	my = ft_printf("my3 = %-10.15da\n", 42);
	orig = printf("or3 = %-10.15da\n", 42);
	printf("my3 = %d\nor3 = %d\n--------------------\n", my, orig);
	my = ft_printf("my4 = %-15.10da\n", 42);
	orig = printf("or4 = %-15.10da\n", 42);
	printf("my4 = %d\nor4 = %d\n--------------------\n", my, orig);
	my = ft_printf("my5 = %+-10da\n", 42);
	orig = printf("or5 = %+-10da\n", 42);
	printf("my5 = %d\nor5 = %d\n--------------------\n", my, orig);
	my = ft_printf("my6 = %15.10da\n", 42);
	orig = printf("or6 = %15.10da\n", 42);
	printf("my6 = %d\nor6 = %d\n--------------------\n", my, orig);
	my = ft_printf("my7 = % +d\n", 42);
	orig = printf("or7 = % +d\n", 42);
	printf("my7 = %d\nor7 = %d\n--------------------\n", my, orig);
	my = ft_printf("my8 = %+010d\n", 42);
	orig = printf("or8 = %+010d\n", 42);
	printf("my8 = %d\nor8 = %d\n--------------------\n", my, orig);
	my = ft_printf("my9 = %+10.5d\n", 42);
	orig = printf("or9 = %+10.5d\n", 42);
	printf("my9 = %d\nor9 = %d\n--------------------\n", my, orig);
	my = ft_printf("my10 = %+5.10d\n", 42);
	orig = printf("or10 = %+5.10d\n", 42);
	printf("my10 = %d\nor10 = %d\n--------------------\n", my, orig);
	my = ft_printf("my11 = % 10d\n", 42);
	orig = printf("or11 = % 10d\n", 42);
	printf("my11 = %d\nor11 = %d\n--------------------\n", my, orig);
	my = ft_printf("my12 = % 010d\n", 42);
	orig = printf("or12 = % 010d\n", 42);
	printf("my12 = %d\nor12 = %d\n--------------------\n", my, orig);
	my = ft_printf("my13 = % .10d\n", 42);
	orig = printf("or13 = % .10d\n", 42);
	printf("my13 = %d\nor13 = %d\n--------------------\n", my, orig);
	my = ft_printf("my14 = % 10d\n", 42);
	orig = printf("or14 = % 10d\n", 42);
	printf("my14 = %d\nor14 = %d\n--------------------\n", my, orig);
	my = ft_printf("my15 = %010.15d\n", 42);
	orig = printf("or15 = %010.15d\n", 42);
	printf("my15 = %d\nor15 = %d\n--------------------\n", my, orig);
	my = ft_printf("my16 = %015.10d\n", 42);
	orig = printf("or16 = %015.10d\n", 42);
	printf("my16 = %d\nor16 = %d\n--------------------\n", my, orig);
	my = ft_printf("my17 = %15.10d\n", 42);
	orig = printf("or17 = %15.10d\n", 42);
	printf("my17 = %d\nor17 = %d\n--------------------\n", my, orig);
	my = ft_printf("my18 = %10.15d\n", 42);
	orig = printf("or18 = %10.15d\n", 42);
	printf("my18 = %d\nor18 = %d\n--------------------\n", my, orig);
	my = ft_printf("my18 = %+ .15dtest\n", 42);
	orig = printf("or18 = %+ .15dtest\n", 42);
	printf("my18 = %d\nor18 = %d\n--------------------\n", my, orig);
	my = ft_printf("my19 = %+ 15dtest\n", 42);
	orig = printf("or19 = %+ 15dtest\n", 42);
	printf("my19 = %d\nor19 = %d\n--------------------\n", my, orig);
	my = ft_printf("my 20 = %05da\n", 42);
	orig = printf("my 20 = %05da\n", 42);
	printf("my19 = %d\nor19 = %d\n--------------------\n", my, orig);
	my = ft_printf("my 21 = %067da\n", 42);
	orig = printf("my 21 = %067da\n", 42);
	printf("my21 = %d\nor21 = %d\n--------------------\n", my, orig);
	my = ft_printf("%-0.0d\n", 42);
	orig = printf("%-0.0d\n", 42);
	printf("my22 = %d\nor22 = %d\n--------------------\n", my, orig);
	my = ft_printf("%i");
	printf("\n");
	orig = printf("%i");
	printf("\n");
	printf("my22 = %d\nor22 = %d\n--------------------\n", my, orig);
	return (0);
}