/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suport_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 22:50:38 by yzakharc          #+#    #+#             */
/*   Updated: 2017/05/02 22:50:39 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar_pf(char c, t_pf *pf)
{
	write(1, &c, 1);
	pf->print_smb++;
}

void	putstr_pf(char const *s, t_pf *pf)
{
	if (s == NULL)
		return ;
	while (*s++)
		putchar_pf(*(s - 1), pf);
}

void	ft_sharp(t_pf *pf)
{
	if (*pf->str != '0' && *pf->str)
	{
		(pf->spcr == 'o' || pf->spcr == 'O') ? putchar_pf('0', pf) : 0;
		pf->spcr == 'x' || pf->spcr == 'p' ? putstr_pf("0x", pf) : 0;
		pf->spcr == 'X' ? putstr_pf("0X", pf) : 0;
		pf->sharp_true = 1;
	}
	else
		return ;
}