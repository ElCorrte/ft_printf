/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:43:06 by yzakharc          #+#    #+#             */
/*   Updated: 2017/05/04 15:46:16 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	pf->sharp == 1 ? ft_sharp(pf) : 0;
	pf->space == 1 || pf->plus == 1 ? ft_pl_sp(pf) : 0;
	pf->str ? putstr_pf(pf->str, pf) : 0;
	pf->c ? putchar_pf(pf->c, pf) : 0;
	(pf->width > pf->dot) ? print_width(len_for_width(pf), pf) : 0;
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
	!pf->dash_true ? putstr_pf(pf->str, pf) : 0;
	if (pf->spcr == 'c' || pf->spcr == 'C')
		!pf->dash_true ? putchar_pf(pf->c, pf) : 0;
}

int		ft_check_sp(char sp, va_list *fm, t_pf *pf)
{
	pf->spcr = sp;
	(sp == 'i' || sp == 'd' || sp == 'D') ? ft_mod_d_i(fm, pf) : 0;
	sp == 's' ? pf->str = va_arg(*fm, char *) : 0;
	sp == 'c' || sp == 'C' ? pf->c = va_arg(*fm, int) : 0;
	sp == 'p' ? ft_mod_other(fm, pf, 16, 39) : 0;
	(sp == 'u' || sp == 'U') ? ft_mod_other(fm, pf, 10, 0) : 0;
	(sp == 'o' || sp == 'O') ? ft_mod_other(fm, pf, 8, 0) : 0;
	sp == 'x' ? ft_mod_other(fm, pf, 16, 39) : 0;
	sp == 'X' ? ft_mod_other(fm, pf, 16, 7) : 0;
	use_flag(pf);
	return (0);
}
