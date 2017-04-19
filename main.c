#include <stdio.h>

int		ft_printf(const char *format, ...);

int 	main(void)
{
	int i = -125;
	int d = 3;
	int x = 255;
	int X = 255;
	int o = 173;
	char c = 72;
	char *s = "ello";

	printf("p_int i = %010i\np_int d = %010d\np_int x = %#10x\np_int X = %#10X\np_int o = %#10o\np_word = %10c%10s\n", i, d, x, X, o, c, s);
	printf("____________________\n\n");
	ft_printf("int i = %010i\nint d = %010d\nint x = %#10x\nint X = %#10X\nint o = %#10o\nword = %10c%10s\n", i, d, x, X, o, c, s);
	return (0);
}