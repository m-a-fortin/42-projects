/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:17:15 by mafortin          #+#    #+#             */
/*   Updated: 2021/07/29 19:08:35 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_elem	ft_initialize_elem(t_elem elem)
{
	elem.type = 0;
	elem.return_value = 0;
	elem.nb = 0;
	elem.index = 0;
	return (elem);
}

t_elem	ft_reset_elem(t_elem elem)
{
	elem.type = 0;
	elem.nb = 0;
	return (elem);
}

t_elem	ft_manage_args(t_elem elem, va_list args, char input)
{
	if (input == 'c')
		elem = ft_print_c_main(elem, args);
	if (input == 'd' || input == 'i')
		elem = ft_print_d_i_main(elem, args);
	if (input == 'p')
		elem = ft_print_p_main(elem, args);
	if (input == 'x' || input == 'X')
		elem = ft_print_x_main(elem, args, input);
	if (input == 's')
		elem = ft_print_s_main(elem, args);
	if (input == 'u')
		elem = ft_print_u_main(elem, args);
	return (elem);
}

t_elem	ft_print_loop(t_elem elem, const char *input, va_list args)
{
	elem.index = 0;
	while (input[elem.index])
	{	
		while (input[elem.index] == '%')
		{
			elem.index++;
			if (input[elem.index] == '%')
			{
				write(1, "%", 1);
				elem.return_value++;
			}
			else
				elem = ft_manage_args(elem, args, input[elem.index]);
			elem.index++;
		}
		if (!input[elem.index])
			break ;
		write(1, &input[elem.index], 1);
		elem.index++;
		elem.return_value++;
	}
	return (elem);
}

int	ft_printf(const char *input, ...)
{
	t_elem		elem;
	va_list		args;

	elem.return_value = 0;
	if (!input)
		return (-1);
	va_start(args, input);
	elem = ft_print_loop(elem, input, args);
	va_end(args);
	return (elem.return_value);
}
