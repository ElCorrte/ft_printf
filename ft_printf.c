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
	if (*pf->str == '-' && !pf->dash && pf->zero != 0)
	{
		ft_putchar('-');
		pf->str++;
	}
	while (width != 0)
	{
		if (!pf->dash)
			pf->zero ? ft_putchar('0') : ft_putchar(' ');
		else
			ft_putchar(' ');
		width--;
	}
	pf->zero = 0;
}

void	print_dash(t_pf *pf)
{
	ft_putstr(pf->str);
	print_width(ft_strlen(pf->str), pf);
	pf->dash = 0;
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
	if (!pf->dash)
		pf->width ? print_width(ft_strlen(pf->str), pf) : 0;
	pf->sharp == 2 ? ft_putchar('0') : 0;
	pf->sharp == 3 ? ft_putstr("0x") : 0;
	pf->sharp == 4 ? ft_putstr("0X") : 0;
	pf->sharp = 0;
	(pf->dash && pf->width) ? print_dash(pf) : ft_putstr(pf->str);
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

void	skip_zero(const char **fl, t_pf *pf)
{
	**fl == '0' ? pf->zero = 1 : 0;
	while (**fl == '0' && **fl)
		(*fl)++;
}

void	ft_check_fl(const char **fl, t_pf *pf)
{
	while (ft_strchr(pf->f_l, **fl) && **fl)
	{
		**fl == '0' ? skip_zero(fl, pf) : 0;
		**fl == '#' ? pf->sharp = 1 : 0;
		**fl == '-' ? pf->dash = 1 : 0;
		**fl == '+' ? pf->plus = 1 : 0;
		**fl == ' ' ? pf->space = 1 : 0;
		**fl == '.' ? pf->dot = 1 : 0;
		**fl == 'h' && *(*fl + 1) != 'h' ? pf->h = 1 : 0;
		**fl == 'h' && *(*fl + 1) == 'h' ? pf->hh = 1 : 0;
		**fl == 'l' && *(*fl + 1) != 'l' ? pf->l = 1 : 0;
		**fl == 'l' && *(*fl + 1) == 'l' ? pf->ll = 1 : 0;
		**fl == 'j' ? pf->j = 1 : 0;
		**fl == 'z' ? pf->z = 1 : 0;
		if (ft_isdigit(**fl))
		{
			pf->width = ft_atoi(*fl);
			len_width(pf->width, pf);
			*fl += pf->len_width;
		}
		(*fl)++;
	}
	(*fl)--;
}

int 	ft_check_form(const char *form, va_list fm)
{
	t_pf 	pf;

	pf.s_p = "sSpdDioOuUxXcC";
	pf.f_l = "#0-+  .hljz123456789";
	while (*form)
	{
		while (*form != '%' && *form)
		{
			ft_putchar(*form);
			form++;
		}
		form++;
		ft_strchr(pf.f_l, *form) && *form ? ft_check_fl(&form,&pf) : 0;
		if (ft_strchr(pf.s_p, *form) && *form)
			ft_check_sp(*form, fm, &pf);
		form++;
	}
	return (pf.print_smb);
}

int		ft_printf(const char *format, ...)
{
	va_list	fm;
	int		print_smb;

	va_start(fm, format);
	print_smb = ft_check_form(format, fm);
	va_end(fm);
	return (print_smb);
}