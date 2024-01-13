/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:56:31 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/02/10 16:26:10 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;
	size_t		s_size;

	last = NULL;
	if (!s)
		return (NULL);
	s_size = ft_strlen(s) + 1;
	while (s_size--)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	return ((char *)last);
}
