/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:16:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/07/21 19:24:23 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_elem	ft_print_d_i_main(t_elem elem, va_list args)
{
	long long int	digit;
	char			*str;
	int				index;

	index = 0;
	digit = va_arg(args, long long int);
	str = ft_itoa(digit);
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
