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
# include <stdint.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_pf
{
	char		*str;
	char		*s_p;
	char 		*f_l;
	char 		c;
	char		spcr;
	char 		*s;
	int 		sharp;
	int 		zero;
	int 		dash;
	int			plus;
	int 		space;
	int 		width;
	int 		len_width;
	int 		dot;
	int 		len_dot;
	int 		print_smb;
	int 		h;
	int 		hh;
	int 		l;
	int 		ll;
	int 		j;
	int 		z;
}				t_pf;

int				ft_printf(const char *format, ...);
void			ft_itoa_dec(intmax_t value, t_pf *pf);
void			itoa_hex_oct(uintmax_t value, t_pf *pf, int base, int x);
int				len_value(intmax_t value);
void			ft_check_sp(char sp, va_list fm, t_pf *pf);
void			ft_mod_d_i(va_list fm, t_pf *pf);
void			ft_mod_other(va_list fm, t_pf *pf, int key, int x);

#endif