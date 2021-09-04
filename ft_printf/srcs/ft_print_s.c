/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:01:10 by mafortin          #+#    #+#             */
/*   Updated: 2021/07/21 19:25:53 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_elem	ft_print_s_main(t_elem elem, va_list args)
{
	int		index;
	char	*str;

	index = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
		elem.return_value++;
	}
	elem = ft_reset_elem(elem);
	return (elem);
}
