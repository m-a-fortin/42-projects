/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:42:56 by mafortin          #+#    #+#             */
/*   Updated: 2021/08/05 13:29:55 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_elem	ft_print_u_main(t_elem elem, va_list args)
{
	unsigned long long	digit;
	char				*str;
	int					index;

	index = 0;
	digit = va_arg(args, unsigned int);
	str = ft_utoa(digit);
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
		elem.return_value++;
	}
	free(str);
	elem = ft_reset_elem(elem);
	return (elem);
}
