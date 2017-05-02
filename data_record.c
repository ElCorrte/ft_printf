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

int 	len_for_width(t_pf *pf)
{
	int	i;

	i = 0;
	if (pf->str)
		i = (int)ft_strlen(pf->str);
	else if (pf->c)
		i = 1;
	return (i);
}

void	ft_check_smb(const char *str, t_pf *pf)
{
	pf->str = ft_strnew(1);
	pf->str[0] = *str;
	pf->str[1] = '\0';
	use_flag(pf);
}

void	clean_all(t_pf *pf)
{
	pf->sharp = 0;
	pf->zero = 0;
	pf->dash = 0;
	pf->plus = 0;
	pf->space = 0;
	pf->width = 0;
	pf->len_width = 0;
	pf->dot = 0;
	pf->len_dot = 0;
	pf->print_smb = 0;
	pf->h = 0;
	pf->hh = 0;
	pf->l = 0;
	pf->ll = 0;
	pf->j = 0;
	pf->z = 0;
}

void	ft_mod_d_i(va_list *fm, t_pf *pf)
{
	pf->str = ft_strnew(0);
	pf->hh == 1 ? ft_itoa_dec((signed char)va_arg(*fm, int), pf) : 0;
	pf->h == 1 ? ft_itoa_dec((short)va_arg(*fm, int), pf) : 0;
	(pf->l == 1 || pf->spcr == 'D') ? ft_itoa_dec(va_arg(*fm, long), pf) : 0;
	pf->ll == 1 ? ft_itoa_dec(va_arg(*fm, long long), pf) : 0;
	pf->j == 1 ? ft_itoa_dec(va_arg(*fm, intmax_t), pf) : 0;
	pf->z == 1 ? ft_itoa_dec(va_arg(*fm, size_t), pf) : 0;
	!*pf->str ? ft_itoa_dec(va_arg(*fm, int), pf) : 0;
}

void 	ft_mod_other(va_list *fm, t_pf *pf, int key, int x)
{
	pf->str = ft_strnew(0);
	pf->hh == 1 ? itoa_hex_oct((unsigned char)va_arg(*fm, int), pf, key, x) : 0;
	pf->h == 1 ? itoa_hex_oct((unsigned short)va_arg(*fm, int), pf, key, x) : 0;
	if (pf->l == 1 || pf->spcr == 'p' || pf->spcr == 'U' || pf->spcr == 'O' )
		itoa_hex_oct(va_arg(*fm, unsigned long), pf, key, x);
	pf->ll == 1 ? itoa_hex_oct(va_arg(*fm, unsigned long long), pf, key, x) : 0;
	pf->j == 1 ? itoa_hex_oct(va_arg(*fm, uintmax_t), pf, key, x) : 0;
	pf->z == 1 ? itoa_hex_oct(va_arg(*fm, size_t), pf, key, x) : 0;
	!*pf->str ? itoa_hex_oct(va_arg(*fm, unsigned int), pf, key, x) : 0;
}