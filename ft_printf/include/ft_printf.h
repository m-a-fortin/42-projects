/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:18:48 by mafortin          #+#    #+#             */
/*   Updated: 2021/07/21 19:21:53 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_elem
{
	char	type;
	int		return_value;
	int		negative;
	int		char_len;
	int		digit_len;
	char	*str;
	int		nb;
	int		index;
}				t_elem;

int		ft_printf(const char *input, ...);
t_elem	ft_print_c_main(t_elem elem, va_list args);
t_elem	ft_print_loop(t_elem elem, const char *input, va_list args);
t_elem	ft_manage_args(t_elem elem, va_list args, char input);
t_elem	ft_print_d_i_main(t_elem elem, va_list args);
t_elem	ft_initialize_elem(t_elem elem);
t_elem	ft_reset_elem(t_elem elem);
t_elem	ft_print_s_main(t_elem elem, va_list args);
t_elem	ft_print_u_main(t_elem elem, va_list args);
t_elem	ft_print_x_main(t_elem elem, va_list args, char input);
t_elem	ft_print_p_main(t_elem elem, va_list args);

#endif
