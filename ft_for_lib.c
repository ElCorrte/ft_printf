/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 22:08:32 by yzakharc          #+#    #+#             */
/*   Updated: 2017/05/02 22:08:32 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspace(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') || (c == '\f') || (c == '\r')\
		|| (c == ' '))
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int b;
	int d;

	b = 0;
	while (ft_isspace(*str) == 1)
		str++;
	d = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		b = b * 10 + (*str - '0');
		str++;
	}
	return (b * d);
}

void	ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	free(*as);
	*as = NULL;
}

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		tot;
	int		count;

	count = (int)ft_strlen(str);
	tot = 0;
	if (!(dest = (char*)malloc(sizeof(*str) * (count + 1))))
		return (NULL);
	while (str[tot])
	{
		dest[tot] = str[tot];
		tot++;
	}
	dest[tot] = '\0';
	return (dest);
}

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	len;

	len = size;
	if (!(s = (char *)malloc((size + 1) * sizeof(*s))))
		return (NULL);
	while (size--)
		*s++ = '\0';
	*s = '\0';
	return (s - len);
}