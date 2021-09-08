/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:19:13 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/07 19:20:48 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//search for the char to_find in the string. Return 1 if found 0 if not
int	ft_char_search(char *string, char to_find)
{
	int	index;

	index = 0;
	while (string[index])
	{
		if (string[index] == to_find)
			return (1);
		else
			index++;
	}
	return (0);
}