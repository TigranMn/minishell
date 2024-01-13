/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <tmnatsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:43:40 by tmnatsak          #+#    #+#             */
/*   Updated: 2024/01/13 14:46:42 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charcount(char *str, char c)
{
	int	count;

	count = 0;
	while (str && *str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
