/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:06:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/07/21 19:41:07 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	ft_deal_letter_p(char *str, int modulo, int index)
{
	if (modulo == 10)
		str[index] = 'A';
	if (modulo == 11)
		str[index] = 'B';
	if (modulo == 12)
		str[index] = 'C';
	if (modulo == 13)
		str[index] = 'D';
	if (modulo == 14)
		str[index] = 'E';
	if (modulo == 15)
		str[index] = 'F';
	return (str[index]);
}

char	ft_deal_modulo_p(char *str, int modulo, int index)
{
	if (modulo >= 10 && modulo <= 15)
		str[index] = ft_deal_letter_p(str, modulo, index);
	else
		str[index] = modulo + '0';
	return (str[index]);
}

char	*ft_ptoa_hex(unsigned long int nb)
{
	int		len;
	char	*str;
	int		index;
	int		modulo;
	int		len_start;

	index = 0;
	len = ft_digit_len(nb) + 1;
	len_start = len;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (nb > 0)
	{
		modulo = nb % 16;
		nb /= 16;
		str[index] = ft_deal_modulo_p(str, modulo, index);
		index++;
		len--;
	}
	str[index] = '\0';
	return (ft_inv_string(str, index));
}

t_elem	ft_print_p_main(t_elem elem, va_list args)
{
	unsigned long int		digit;
	char					*str;
	int						index;

	index = 0;
	digit = (unsigned long int)va_arg(args, void *);
	write(1, "0x", 2);
	elem.return_value += 2;
	if (digit == 0)
	{
		write(1, "0", 1);
		elem.return_value++;
		return (elem);
	}
	str = ft_ptoa_hex(digit);
	while (str[index])
	{	
		str[index] = ft_tolower(str[index]);
		write(1, &str[index], 1);
		elem.return_value++;
		index++;
	}
	free(str);
	elem = ft_reset_elem(elem);
	return (elem);
}
