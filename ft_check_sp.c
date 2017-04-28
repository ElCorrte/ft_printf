/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:43:06 by yzakharc          #+#    #+#             */
/*   Updated: 2017/04/26 15:43:06 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sharp(t_pf *pf)
{
	(pf->spcr == 'o' || pf->spcr == 'O') ? ft_putchar('0') : 0;
	pf->spcr == 'x' || pf->spcr == 'p' ? ft_putstr("0x") : 0;
	pf->spcr == 'X' ? ft_putstr("0X") : 0;
	pf->sharp = 0;
}

void	ft_plus_space(t_pf *pf)
{
	if (pf->spcr == 'i' || pf->spcr == 'd')
	{
		if (pf->space == 1 && pf->plus == 1)
		{
			ft_putchar('+');
			pf->space = 0;
			pf->plus = 0;
		}
		pf->plus == 1 ? ft_putchar('+') : 0;
		pf->space == 1 ? ft_putchar(' ') : 0;
	}
	pf->plus == 1 ? pf->plus = 0 : 0;
	pf->space == 1 ? pf->space = 0 : 0;
	pf->width ? pf->width-- : 0;
}

void	print_width(size_t minus, t_pf *pf)
{
	int	width;

	if (!pf->space || pf->zero == 1)
		(pf->zero == 1 && pf->plus == 1) || pf->space == 1 ? ft_plus_space(pf) : 0;
	width = pf->width;
	pf->space == 1 || pf->plus == 1 ? width-- : 0;
	pf->width = 0;
	width -= minus;
	if (pf->sharp)
	{
		(pf->spcr == 'o' || pf->spcr == 'O') ? width -= 1 : 0;
		(pf->spcr == 'x' || pf->spcr == 'X') ? width -= 2 : 0;
	}
	if (*pf->str == '-' && !pf->dash && pf->zero != 0)
	{
		ft_putchar('-');
		pf->str++;
	}
	while (width != 0)
	{
		if (!pf->dash)
			pf->zero && !pf->dot ? ft_putchar('0') : ft_putchar(' ');
		else
			ft_putchar(' ');
		width--;
	}
	pf->zero = 0;
}

void	print_dash(t_pf *pf)
{
	pf->space == 1 || pf->plus == 1 ? ft_plus_space(pf) : 0;
	ft_putstr(pf->str);
	(pf->width > pf->dot) ? print_width(ft_strlen(pf->str), pf) : 0;
}

void	create_dot(char *str, int dot, t_pf *pf)
{
	char	*dot_str;
	int		len;
	size_t	i;
	int		end;

	i = ft_strlen(str);
	*str == '-' ? dot++ : 0;
	end = *str == '-' ? 1 : 0;
	len = dot;
	if (dot > i)
	{
		dot_str = ft_strnew((size_t)dot);
		while(dot-- > 0)
			dot_str[dot] = '0';
		while (--len > end && i)
		{
			dot_str[len] = str[--i];
			str[i - 1] == '-' ? i = 0 : 0;
		}
		*str == '-' ? dot_str[0] = '-' : 0;
		ft_strdel(&pf->str);
		pf->str = ft_strdup(dot_str);
	}
}

void	use_flag(t_pf *pf)
{
	pf->dot ? create_dot(pf->str, pf->dot, pf) : 0;
	pf->dash == 1 ? print_dash(pf) : 0;
	pf->width && pf->width > pf->dot ? print_width(ft_strlen(pf->str), pf) : 0;
	(pf->sharp == 1 || pf->spcr == 'p') ? ft_sharp(pf) : 0;
	(pf->plus == 1 || pf->space == 1) ? ft_plus_space(pf) : 0;
	pf->dash == 1 ? pf->dash = 0 : ft_putstr(pf->str);
	ft_strdel(&pf->str);
	pf->width = 0;
	pf->dot = 0;
}

void	print_char(va_list fm, t_pf *pf)
{
	if (pf->spcr == 'c' || pf->spcr == 'C')
	{
		pf->c = va_arg(fm, int);
		pf->width ? print_width(1, pf) : 0;
		ft_putchar(pf->c);
	}
	if (pf->spcr == 's')
	{
		pf->s = va_arg(fm, char *);
		pf->width ? print_width(ft_strlen(pf->s), pf) : 0;
		ft_putstr(pf->s);
	}
}


void	ft_check_sp(char sp, va_list fm, t_pf *pf)
{
	pf->spcr = sp;
	(sp == 'i' || sp == 'd' || sp == 'D') ? ft_mod_d_i(fm, pf) : 0;
	(sp == 'c' || sp =='s' || sp == 'C') ? print_char(fm, pf) : 0;
	sp == 'p' ? ft_mod_other(fm, pf, 16, 39) : 0;
	(sp == 'u' || sp == 'U') ? ft_mod_other(fm, pf, 10, 0) : 0;
	(sp == 'o' || sp == 'O') ? ft_mod_other(fm, pf, 8, 0) : 0;
	sp == 'x' ? ft_mod_other(fm, pf, 16, 39) : 0;
	sp == 'X' ? ft_mod_other(fm, pf, 16, 7) : 0;
	use_flag(pf);
}