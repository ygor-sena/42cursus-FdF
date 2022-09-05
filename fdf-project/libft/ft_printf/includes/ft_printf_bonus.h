/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 23:56:19 by yde-goes          #+#    #+#             */
/*   Updated: 2022/08/22 20:32:09 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define DECIMAL_BASE "0123456789"
# define UP_HEX_BASE "0123456789ABCDEF"
# define LOW_HEX_BASE "0123456789abcdef"
# define FLAGS "-0.# +" 
# define PLUS_SIGN "+"
# define SPACE_SIGN " "
# define PERCENT_SIGN "%"
# define SPECIFIERS "cspdiuxX%"
# define UP_HEX_PREFIX "0X"
# define LOW_HEX_PREFIX "0x"
# define NULL_PTR "(nil)"
# define NULL_STR "(null)"

# include "../../libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_format
{
	va_list		arg;
	const char	*format;
	size_t		size;
	size_t		index;
}	t_format;

typedef struct s_flag
{
	t_bool	padding;
	size_t	field;
	t_bool	precision;
	size_t	length;
	t_bool	left_just;
	t_bool	hashtag;
	t_bool	sign;
	t_bool	space;
	char	spec;
	t_bool	error;
}	t_flag;

int			ft_printf(const char *format, ...);

t_format	ft_instance_format(va_list arg, const char *format);
t_flag		ft_instance_flag(void);
void		ft_reset_flag(t_flag *flag);

void		ft_sort_format(t_format *input, t_flag flag);
void		ft_parse_hexa(t_format *input, t_flag flag, char *str_nbr);
void		ft_parse_integer(t_format *input, t_flag flag);
void		ft_type_cast(t_format *input, t_flag flag);

void		ft_cast_char(t_format *input);
void		ft_cast_percent(t_format *input);
void		ft_cast_string(t_format *input);
void		ft_cast_pointer(t_format *input);
void		ft_cast_unsigned(t_format *input);
void		ft_cast_integer(t_format *input, t_flag flag);
void		ft_cast_hexa(t_format *input, t_flag flag);
#endif
