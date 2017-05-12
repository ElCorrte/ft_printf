/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:31:35 by yzakharc          #+#    #+#             */
/*   Updated: 2017/05/11 14:36:41 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct		s_pf
{
	char			*str;
	int				str_clean;
	char			*s_p;
	char			*f_l;
	char			*is_int;
	int				c;
	char			spcr;
	int				value;
	int				sharp_true;
	int				sharp;
	int				zero;
	int				dash;
	int				dash_true;
	int				pl_sp_true;
	int				plus;
	int				space;
	int				width;
	int				new_width;
	int				len_width;
	int				printed_width;
	int				dot;
	int				len_dot;
	int				print_smb;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
	int				no_mod;
	int				plus_one;
}					t_pf;

int					ft_printf(const char *format, ...);
void				ft_itoa_dec(intmax_t value, t_pf *pf);
void				itoa_hex_oct(uintmax_t value, t_pf *pf, int base, int x);
int					len_value(intmax_t value);
int					ft_check_sp(char sp, va_list *fm, t_pf *pf);
void				ft_mod_d_i(va_list *fm, t_pf *pf);
void				ft_mod_other(va_list *fm, t_pf *pf, int key, int x);
void				clean_all(t_pf *pf);
void				ft_check_smb(const char *str, t_pf *pf);
void				print_width(int minus, t_pf *pf);
void				use_flag(t_pf *pf);
int					len_for_width(t_pf *pf);
void				putchar_pf(char c, t_pf *pf);
void				putstr_pf(char const *s, t_pf *pf);
void				ft_trunk(t_pf *pf);
int					ft_isdigit(int c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
char				*ft_strnew(size_t size, t_pf *pf);
void				ft_sharp(t_pf *pf);
void				putstr_pf(char const *s, t_pf *pf);
void				putchar_pf(char c, t_pf *pf);
int					check_dot(t_pf *pf, const char **str, va_list *fm);
void				create_dot(char *str, int dot, t_pf *pf);
int					check_width(t_pf *pf, const char **str, va_list *fm);
void				print_width(int minus, t_pf *pf);
void				ft_pl_sp(t_pf *pf);
void				clear_flag(t_pf *pf);
void				print_wchar(va_list *fm, t_pf *pf);

#endif
