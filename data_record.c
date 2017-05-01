/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:50:13 by yzakharc          #+#    #+#             */
/*   Updated: 2017/04/26 15:50:14 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mod_d_i(va_list fm, t_pf *pf)
{
	pf->str = ft_strnew(0);
	pf->hh == 1 ? ft_itoa_dec((signed char)va_arg(fm, int), pf) : 0;
	pf->h == 1 ? ft_itoa_dec((short)va_arg(fm, int), pf) : 0;
	(pf->l == 1 || pf->spcr == 'D') ? ft_itoa_dec(va_arg(fm, long), pf) : 0;
	pf->ll == 1 ? ft_itoa_dec(va_arg(fm, long long), pf) : 0;
	pf->j == 1 ? ft_itoa_dec(va_arg(fm, intmax_t), pf) : 0;
	!*pf->str ? ft_itoa_dec(va_arg(fm, int), pf) : 0;
}

void 	ft_mod_other(va_list fm, t_pf *pf, int key, int x)
{
	pf->str = ft_strnew(0);
	pf->hh == 1 ? itoa_hex_oct((unsigned char)va_arg(fm, int), pf, key, x) : 0;
	pf->h == 1 ? itoa_hex_oct((unsigned short)va_arg(fm, int), pf, key, x) : 0;
	if (pf->l == 1 || pf->spcr == 'p' || pf->spcr == 'U' || pf->spcr == 'O' )
		itoa_hex_oct(va_arg(fm, unsigned long), pf, key, x);
	pf->ll == 1 ? itoa_hex_oct(va_arg(fm, unsigned long long), pf, key, x) : 0;
	pf->j == 1 ? itoa_hex_oct(va_arg(fm, uintmax_t), pf, key, x) : 0;
	!*pf->str ? itoa_hex_oct(va_arg(fm, unsigned int), pf, key, x) : 0;
}