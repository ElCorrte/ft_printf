/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:31:35 by yzakharc          #+#    #+#             */
/*   Updated: 2017/04/06 13:31:36 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H_
# define FT_PRINTF_H_

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_pf
{
	char		*str;
	char		*s_p;
	char 		*f_l;
	char 		c;
	char 		*s;
	int			i;
	int 		sharp;
	int 		zero;
	int 		dash;
	int			plus;
	int 		space;
	int 		width;
	int 		len_width;
}				t_pf;
int				ft_printf(const char *format, ...);

#endif