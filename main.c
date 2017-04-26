#include <stdio.h>

int		ft_printf(const char *format, ...);

int 	main(void)
{
	int i = -125;
	int d = -3;
	int u = -123;
	void *p = (void *)-123;
	int x = -255;
	int X = -255;
	int o = -73;
	char c = 72;
	char *s = "ello";
	int	cnt = 0;

	printf("__________%i__________\n", cnt++);
	printf("orig = %p\n", p);
	ft_printf("_my_ = %p\n", p);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %u\n", u);
	ft_printf("_my_ = %u\n", u);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %U\n", u);
	ft_printf("_my_ = %U\n", u);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %i\n", i);
	ft_printf("_my_ = %i\n", i);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %d\n", d);
	ft_printf("_my_ = %d\n", d);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %D\n", d);
	ft_printf("_my_ = %D\n", d);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %x\n", x);
	ft_printf("_my_ = %x\n", x);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %X\n", X);
	ft_printf("_my_ = %X\n", X);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %o\n", o);
	ft_printf("_my_ = %o\n", o);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %O\n", o);
	ft_printf("_my_ = %O\n", o);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %c\n", c);
	ft_printf("_my_ = %c\n", c);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %C\n", c);
	ft_printf("_my_ = %C\n", c);
	printf("\n__________%i__________\n", cnt++);
	printf("orig = %s\n", s);
	ft_printf("_my_ = %s\n", s);
	return (0);
}