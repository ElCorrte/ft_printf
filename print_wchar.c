/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_S.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:38:53 by yzakharc          #+#    #+#             */
/*   Updated: 2017/05/12 21:59:56 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_to_string(char *str, char symb)
{
	size_t	len;
	char	*res;
	int		i;

	len = ft_strlen(str) + 1;
	res = (char*)malloc(sizeof(char) * (len + 1));
	res[len] = 0;
	res[len - 1] = symb;
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	free(str);
	return (res);
}

void	print_four_bytes(int tmp, int *i, t_pf *pf)
{
	tmp = *i >> 6 * 3;
	tmp |= 240;
	pf->str = add_to_string(pf->str, tmp);
	tmp = *i >> 6 * 2;
	tmp &= 63;
	tmp |= 128;
	pf->str = add_to_string(pf->str, tmp);
	tmp = *i >> 6;
	tmp &= 63;
	tmp |= 128;
	pf->str = add_to_string(pf->str, tmp);
	tmp = *i;
	tmp &= 63;
	tmp |= 128;
	pf->str = add_to_string(pf->str, tmp);
}

void	print_three_bytes(int tmp, int *i, t_pf *pf)
{
	tmp = *i >> 6 * 2;
	tmp |= 224;
	pf->str = add_to_string(pf->str, tmp);
	tmp = *i >> 6;
	tmp &= 63;
	tmp |= 128;
	pf->str = add_to_string(pf->str, tmp);
	tmp = *i;
	tmp &= 63;
	tmp |= 128;
	pf->str = add_to_string(pf->str, tmp);
}

void	print_two_bytes(int tmp, int *i, t_pf *pf)
{
	tmp = *i >> 6;
	tmp |= 192;
	pf->str = add_to_string(pf->str, tmp);
	tmp = *i;
	tmp &= 63;
	tmp |= 128;
	pf->str = add_to_string(pf->str, tmp);
}

void	print_wchar(va_list *fm, t_pf *pf)
{
	int	*i;
	int	tmp;
	int printed_width;

	tmp = 0;
	printed_width = 0;
	pf->str = ft_strnew(1, pf);
	pf->str[0] = 0;
	i = va_arg(*fm, int *);
	pf->dot == 0 ? pf->dot = 2097152 : 0;
	while (*i)
	{
		if (*i < 128 && printed_width++ < pf->dot)
		{
			tmp = *i;
			pf->str = add_to_string(pf->str, tmp);
		}
		if ((*i >= 128 && *i < 2048) && (printed_width += 2) < pf->dot)
			print_two_bytes(tmp, i, pf);
		if ((*i >= 2048 && *i < 65536) && (printed_width += 3) < pf->dot)
			print_three_bytes(tmp, i, pf);
		if ((*i >= 65546 && *i < 2097152) && (printed_width += 4) < pf->dot)
			print_four_bytes(tmp, i, pf);
		i++;
	}
}
