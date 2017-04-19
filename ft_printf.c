/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:31:20 by yzakharc          #+#    #+#             */
/*   Updated: 2017/04/06 13:31:22 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(size_t minus, t_pf *pf)
{
	int	width;

	width = pf->width;
	pf->width = 0;
	width -= minus;
	if (pf->sharp)
	{
		pf->sharp == 2 ? width -= 1 : 0;
		(pf->sharp == 3 || pf->sharp == 4) ? width -= 2 : 0;
	}
	if (*pf->str == '-')
	{
		ft_putchar('-');
		pf->str++;
	}
	while (width != 0)
	{
		pf->zero ? ft_putchar('0') : ft_putchar(' ');
		width--;
	}
	pf->zero = 0;
}

void	print_int(va_list fm, t_pf *pf, int key, int x)
{
	pf->i = va_arg(fm, int);
	pf->str = ft_itoa_base(pf->i, key, x);
	if (pf->plus && *pf->str != '-')
	{
		ft_putchar('+');
		pf->plus = 0;
	}
	if (pf->space && !pf->plus && *pf->str != '-')
	{
		ft_putchar(' ');
		pf->space = 0;
	}
	pf->width ? print_width(ft_strlen(pf->str), pf) : 0;
	pf->sharp == 2 ? ft_putchar('0') : 0;
	pf->sharp == 3 ? ft_putstr("0x") : 0;
	pf->sharp == 4 ? ft_putstr("0X") : 0;
	pf->sharp = 0;
	ft_putstr(pf->str);
}

void	print_c(va_list fm, t_pf pf)
{
	pf.c = va_arg(fm, int);
	pf.width ? print_width(1, &pf) : 0;
	ft_putchar(pf.c);
}

void	print_s(va_list fm, t_pf pf)
{
	pf.s = va_arg(fm, char *);
	pf.width ? print_width(ft_strlen(pf.s), &pf) : 0;
	ft_putstr(pf.s);
}

void	ft_check_sp(char sp, va_list fm, t_pf *pf)
{
	(sp == 'i' || sp == 'd') ? print_int(fm, pf, 10, 0) : 0;
	sp == 'c' ? print_c(fm, *pf) : 0;
	sp == 's' ? print_s(fm, *pf) : 0;
	if (sp == 'o')
	{
		pf->sharp ? pf->sharp += 1 : 0;
		print_int(fm, pf, 8, 0);
	}
	if (sp == 'x')
	{
		pf->sharp ? pf->sharp += 2 : 0;
		print_int(fm, pf, 16, 39);
	}
	if (sp == 'X')
	{
		pf->sharp ? pf->sharp += 3 : 0;
		print_int(fm, pf, 16, 7);
	}
}

void	ft_check_fl(char fl, va_list fm, t_pf *pf)
{
	fl == '#' ? pf->sharp = 1 : 0;
	fl == '0' ? pf->zero = 1 : 0;
	fl == '-' ? pf->dash = 1 : 0;
	fl == '+' ? pf->plus = 1 : 0;
	fl == ' ' ? pf->space = 1 : 0;
}

void	len_width(int width, t_pf *pf)
{
	pf->len_width = 0;
	(width < 0) ? pf->len_width++ : 0;
	while (width != 0)
	{
		width /= 10;
		pf->len_width++;
	}
}

void 	ft_check_form(const char *form, va_list fm)
{
	t_pf 	pf;

	pf.s_p = "naAeEfFgGsSpdDioOuUxXcC%";
	pf.f_l = "#0-+ ";
	while (*form)
	{
		while (*form != '%' && *form)
		{
			ft_putchar(*form);
			form++;
		}
		if (ft_strchr(pf.f_l, *(form + 1)) && *form)
		{
			ft_check_fl(*(form + 1), fm, &pf);
			form++;
		}
		if (ft_isdigit(*(form + 1)) && *form)
		{
			form++;
			pf.width = ft_atoi(form);
			len_width(pf.width, &pf);
			form += --pf.len_width;
		}
		if (ft_strchr(pf.s_p, *(form + 1)) && *form)
		{
			ft_check_sp(*(form + 1), fm, &pf);
			form++;
		}
		form++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	fm;

	va_start(fm, format);
	ft_check_form(format, fm);
	va_end(fm);
	return (0);
}