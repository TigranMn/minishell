/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <tmnatsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 23:05:52 by tmnatsak          #+#    #+#             */
/*   Updated: 2024/01/13 14:46:42 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printmatrix_fd(char **matrix, int fd)
{
	int	i;

	i = -1;
	while (matrix && matrix[++i])
		ft_putendl_fd(matrix[i], fd);
}

void	ft_matrixline_swap(char **m, int i, int j)
{
	char	*temp;

	temp = ft_strdup(m[i]);
	free(m[i]);
	m[i] = ft_strdup(m[j]);
	free(m[j]);
	m[j] = ft_strdup(temp);
	free(temp);
}

char	**ft_alphabetical_matrix(char **m)
{
	char	**matrix;
	int		i[2];
	int		len;

	i[0] = -1;
	i[1] = 0;
	matrix = ft_dup_matrix(m);
	while (matrix && matrix[++i[0]])
	{
		while (matrix[++i[1]])
		{
			if (ft_strlen(matrix[i[0]]) > ft_strlen(matrix[i[1]]))
				len = ft_strlen(matrix[i[1]]);
			else
				len = ft_strlen(matrix[i[0]]);
			if (ft_strncmp(matrix[i[0]], matrix[i[1]], len) < 0)
				ft_matrixline_swap(matrix, i[0], i[1]);
		}
		i[1] = -1;
	}
	return (matrix);
}
