/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suport_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 22:50:38 by yzakharc          #+#    #+#             */
/*   Updated: 2017/05/10 18:11:47 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_flag(t_pf *pf)
{
	char *c;

	c = "XxOop";
	if (!ft_strchr(c, pf->spcr))
		pf->sharp = 0;
}

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
	pf->spcr == 'o' && pf->value > 0 ? pf->dot = 0 : 0;
	if ((*pf->str != '0' && pf->dot != -1) || pf->spcr == 'p')
	{
		(pf->spcr == 'o' || pf->spcr == 'O') ? putchar_pf('0', pf) : 0;
		pf->spcr == 'x' || pf->spcr == 'p' ? putstr_pf("0x", pf) : 0;
		pf->spcr == 'X' ? putstr_pf("0X", pf) : 0;
		pf->sharp_true = 1;
	}
	else
		return ;
}
