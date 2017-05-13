/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:43:06 by yzakharc          #+#    #+#             */
/*   Updated: 2017/05/11 12:17:27 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_n(va_list *fm, t_pf *pf)
{
	int *n;

	n = va_arg(*fm, void *);
	*n = pf->print_smb;
	return (0);
}

void	ft_pl_sp(t_pf *pf)
{
	if (pf->spcr == 'i' || pf->spcr == 'd')
	{
		if (pf->space == 1 && pf->plus == 1 && *pf->str != '-')
		{
			putchar_pf('+', pf);
			pf->space = 0;
			pf->plus = 0;
			pf->pl_sp_true = 1;
		}
		if (pf->plus == 1 && *pf->str != '-')
		{
			putchar_pf('+', pf);
			pf->pl_sp_true = 1;
		}
		if (pf->space == 1 && !pf->plus && *pf->str != '-')
		{
			putchar_pf(' ', pf);
			pf->pl_sp_true = 1;
		}
	}
	pf->plus == 1 ? pf->plus = 0 : 0;
	pf->space == 1 ? pf->space = 0 : 0;
	pf->pl_sp_true && pf->width ? pf->width-- : 0;
}

void	print_dash(t_pf *pf)
{
	pf->sharp == 1 || pf->spcr == 'p' ? ft_sharp(pf) : 0;
	pf->space == 1 || pf->plus == 1 ? ft_pl_sp(pf) : 0;
	pf->str ? putstr_pf(pf->str, pf) : 0;
	if (pf->spcr == 'c')
		putchar_pf(pf->c, pf);
	else
		pf->c ? putchar_pf(pf->c, pf) : 0;
	(pf->width > pf->dot) ? print_width(len_for_width(pf), pf) : 0;
	pf->str_clean == 1 ? ft_strdel(&pf->str) : 0;
	pf->dash_true = 1;
}

void	use_flag(t_pf *pf)
{
	if (pf->spcr != 'c')
		pf->dot != -1 && pf->dot ? create_dot(pf->str, pf->dot, pf) : 0;
	pf->dash == 1 ? print_dash(pf) : 0;
	if (pf->width && pf->width > pf->dot && pf->width > (int)ft_strlen(pf->str))
		print_width(len_for_width(pf), pf);
	(!pf->sharp_true && (pf->sharp == 1 || pf->spcr == 'p')) ? ft_sharp(pf) : 0;
	(pf->plus == 1 || pf->space == 1) ? ft_pl_sp(pf) : 0;
	if (!pf->dash_true && pf->spcr != 'c')
	{
		pf->plus_one ? putstr_pf((pf->str + 1), pf) : putstr_pf(pf->str, pf);
		pf->str_clean == 1 ? ft_strdel(&pf->str) : 0;
	}
	if (pf->spcr == 'c' || pf->spcr == 'C')
		!pf->dash_true ? putchar_pf(pf->c, pf) : 0;
}

int		ft_check_sp(char sp, va_list *fm, t_pf *pf)
{
	pf->spcr = sp;
	clear_flag(pf);
	if (pf->spcr == 'n')
		return (print_n(fm, pf));
	(sp == 'i' || sp == 'd' || sp == 'D') ? ft_mod_d_i(fm, pf) : 0;
	pf->spcr == 'S' ? print_wchar(fm, pf) : 0;
	if (sp == 's' && pf->dot != -1)
		if (!(pf->str = va_arg(*fm, char *)))
			pf->str = "(null)";
	sp == 's' && pf->dot == -1 ? pf->str = ft_strnew(0, pf) : 0;
	sp == 'c' || sp == 'C' ? pf->c = va_arg(*fm, int) : 0;
	sp == 'b' ? ft_mod_other(fm, pf, 2, 0) : 0;
	sp == 'p' ? ft_mod_other(fm, pf, 16, 39) : 0;
	(sp == 'u' || sp == 'U') ? ft_mod_other(fm, pf, 10, 0) : 0;
	(sp == 'o' || sp == 'O') ? ft_mod_other(fm, pf, 8, 0) : 0;
	sp == 'x' ? ft_mod_other(fm, pf, 16, 39) : 0;
	sp == 'X' ? ft_mod_other(fm, pf, 16, 7) : 0;
	if ((pf->dot == -1 && pf->value == 0 && !pf->sharp) || \
		(pf->sharp && pf->spcr == 'x' && pf->dot == -1 && pf->value == 0))
		*pf->str = '\0';
	pf->dot == -1 && pf->width > 0 && pf->spcr != 'd' ? pf->dot = 0 : 0;
	use_flag(pf);
	return (0);
}
