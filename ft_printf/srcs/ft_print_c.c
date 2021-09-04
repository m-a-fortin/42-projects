/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:10:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/07/21 19:24:17 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_elem	ft_print_c_main(t_elem elem, va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	elem.return_value++;
	return (elem);
}
