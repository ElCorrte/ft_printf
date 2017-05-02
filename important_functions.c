/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   important_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:39:04 by yzakharc          #+#    #+#             */
/*   Updated: 2017/05/02 18:39:05 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_trunk_1(t_pf *pf)
{
	if (pf->ll == 1)
	{
		pf->l = 0;
		pf->h = 0;
		pf->hh = 0;
	}
	if (pf->l == 1)
	{
		pf->h = 0;
		pf->hh = 0;
	}
	if (pf->h == 1)
		pf->hh = 0;
}

void	ft_trunk(t_pf *pf)
{
	if (pf->z == 1)
	{
		pf->j = 0;
		pf->ll = 0;
		pf->l = 0;
		pf->h = 0;
		pf->hh = 0;
	}
	if (pf->j == 1)
	{
		pf->ll = 0;
		pf->l = 0;
		pf->h = 0;
		pf->hh = 0;
	}
	ft_trunk_1(pf);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
		if ((*s == (char)c) || (*(++s) == (char)c))
			return ((char *)s);
	return (NULL);
}