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

int		check_dot(t_pf *pf, const char **str, va_list *fm)
{
	(*str)++;
	pf->dot = ft_isdigit(**str) ? ft_atoi(*str) : 0;
	**str == '*' ? pf->dot = va_arg(*fm, int) : 0;
	pf->len_dot = len_value(pf->dot);
	pf->len_dot == 0 ? pf->len_dot++ : 0;
	*str += pf->len_dot;
	return (0);
}

int		check_width(t_pf *pf, const char **str)
{
	pf->width = ft_atoi(*str);
	pf->len_width = len_value(pf->width);
	*str += pf->len_width;
	return (0);
}

void	skip_zero(const char **fl, t_pf *pf)
{
	**fl == '0' ? pf->zero = 1 : 0;
	while (**fl == '0' && **fl)
		(*fl)++;
}

int 	skip_hh_ll(const char **fl, t_pf *pf)
{
	if (**fl == 'h' && *(*fl + 1) == 'h')
	{
		pf->hh = 1;
		(*fl) += 2;
	}
	if (**fl == 'l' && *(*fl + 1) == 'l')
	{
		pf->ll = 1;
		(*fl) += 2;
	}
	return (0);
}

int		ft_check_fl(const char **fl, t_pf *pf, va_list *fm)
{
	while (ft_strchr(pf->f_l, **fl) && **fl)
	{
		**fl == '0' ? skip_zero(fl, pf) : 0;
		**fl == '#' ? pf->sharp = 1 : 0;
		**fl == '-' ? pf->dash = 1 : 0;
		**fl == '+' ? pf->plus = 1 : 0;
		**fl == ' ' ? pf->space = 1 : 0;
		if (**fl == '.')
			return (check_dot(pf, fl, fm));
		**fl == 'h' && *(*fl + 1) != 'h' ? pf->h = 1 : 0;
		if (**fl == 'h' && *(*fl + 1) == 'h')
			return (skip_hh_ll(fl, pf));
		**fl == 'l' && *(*fl + 1) != 'l' ? pf->l = 1 : 0;
		if (**fl == 'l' && *(*fl + 1) == 'l')
			return (skip_hh_ll(fl, pf));
		**fl == 'j' ? pf->j = 1 : 0;
		**fl == 'z' ? pf->z = 1 : 0;
		if (ft_isdigit(**fl))
			return (check_width(pf, fl));
		(*fl)++;
	}
	return (0);
}

int		ft_check_form(const char *form, va_list *fm, t_pf *pf)
{
	while (*form)
	{
		while (*form != '%' && *form)
		{
			putchar_pf(*form, pf);
			form++;
		}
		*form ? form++ : 0;
		while (ft_strchr(pf->f_l, *form) && *form)
			ft_check_fl(&form, pf, fm);
		ft_trunk(pf);
		if (ft_strchr(pf->s_p, *form) && *form)
			ft_check_sp(*form, fm, pf);
		else
			*form ? ft_check_smb(form, pf) : 0;
		*form ? form++ : 0;
	}
	return (pf->print_smb);
}

int		ft_printf(const char *format, ...)
{
	va_list	fm;
	int		how_mach;
	t_pf	pf;

	pf.s_p = "sSpdDioOuUxXcC";
	pf.f_l = "#0-+  .hljz123456789";
	pf.print_smb = 0;
	clean_all(&pf);
	va_start(fm, format);
	how_mach = ft_check_form(format, &fm, &pf);
	clean_all(&pf);
	va_end(fm);
	return (how_mach);
}
