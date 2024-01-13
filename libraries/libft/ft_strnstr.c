/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:07:34 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/01/26 16:57:00 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle || *needle == '\0')
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (*(haystack + i) != '\0' && i < len)
	{
		if (*(haystack + i) == *(needle + j))
		{
			while (*(haystack + i + j) == *(needle + j) && i + j < len)
			{
				if (*(needle + j + 1) == '\0')
				{
					return ((char *)(haystack + i));
				}
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
