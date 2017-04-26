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

void	check_dot(t_pf *pf, const char **str)
{
	(*str)++;
	ft_isdigit(**str) ? pf->dot = ft_atoi(*str) : (pf->dot = 0);
	pf->len_dot = len_value(pf->dot);
	*str += pf->len_dot;
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
		**fl == '.' ? check_dot(pf, fl) : 0;
		**fl == 'h' && *(*fl + 1) != 'h' ? pf->h = 1 : 0;
		**fl == 'h' && *(*fl + 1) == 'h' ? pf->hh = 1 : 0;
		**fl == 'l' && *(*fl + 1) != 'l' ? pf->l = 1 : 0;
		**fl == 'l' && *(*fl + 1) == 'l' ? pf->ll = 1 : 0;
		**fl == 'j' ? pf->j = 1 : 0;
		**fl == 'z' ? pf->z = 1 : 0;
		if (ft_isdigit(**fl))
		{
			pf->width = ft_atoi(*fl);
			pf->len_width = len_value(pf->width);
			*fl += pf->len_width;
			break ;
		}
		pf->hh == 1 || pf->ll == 1 ? (*fl) += 2 : (*fl)++;
	}
}

int 	ft_check_form(const char *form, va_list fm)
{
	t_pf 	pf;

	pf.s_p = "sSpdDioOuUxXcC";
	pf.f_l = "#0-+  .hljz123456789";
	pf.print_smb = 0;
	while (*form)
	{
		while (*form != '%' && *form)
		{
			ft_putchar(*form);
			pf.print_smb++;
			form++;
		}
		*form ? form++ : 0;
		while (ft_strchr(pf.f_l, *form) && *form)
			ft_check_fl(&form, &pf);
		(ft_strchr(pf.s_p, *form) && *form) ? 0 : form--;
		if (ft_strchr(pf.s_p, *form) && *form)
			ft_check_sp(*form, fm, &pf);
		*form ? form++ : 0;
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