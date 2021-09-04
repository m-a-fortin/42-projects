/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:12:30 by mafortin          #+#    #+#             */
/*   Updated: 2021/07/21 19:05:00 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_elem	ft_print_x_main(t_elem elem, va_list args, char input)
{
	unsigned int			digit;
	char					*str;
	int						index;

	index = 0;
	digit = va_arg(args, unsigned int);
	if (digit == 0)
	{
		write(1, "0", 1);
		elem.return_value++;
		return (elem);
	}
	str = ft_itoa_hex(digit);
	while (str[index])
	{
		if (input == 'x')
			str[index] = ft_tolower(str[index]);
		write(1, &str[index], 1);
		elem.return_value++;
		index++;
	}
	free(str);
	elem = ft_reset_elem(elem);
	return (elem);
}
