/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_strtrim_q.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <tmnatsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:08:28 by tmnatsak          #+#    #+#             */
/*   Updated: 2024/01/13 14:46:42 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	trimmed_len(const char *str)
{
	int	count;
	int	squote;
	int	dquote;
	int	i;

	squote = 0;
	dquote = 0;
	count = 0;
	i = -1;
	while (str && str[++i])
	{
		squote = (squote + (!dquote && str[i] == '\'')) % 2;
		dquote = (dquote + (!squote && str[i] == '\"')) % 2;
		if ((str[i] == '\"' && !squote) || (str[i] == '\'' && !dquote))
			count++;
	}
	if (squote || dquote)
		return (-1);
	return (count);
}

char	*strtrim_quotes(const char *str, int squote, int dquote)
{
	char	*trimmed;
	int		count;
	int		i[2];

	i[0] = 0;
	i[1] = -1;
	count = trimmed_len(str);
	if (!str || count == -1)
		return (NULL);
	trimmed = malloc(sizeof(char) * (ft_strlen(str) - count + 1));
	if (!trimmed)
		return (NULL);
	while (str[i[0]])
	{
		squote = (squote + (!dquote && str[i[0]] == '\'')) % 2;
		dquote = (dquote + (!squote && str[i[0]] == '\"')) % 2;
		if ((str[i[0]] != '\"' || squote) && (str[i[0]] != '\'' || dquote) \
			&& ++i[1] >= 0)
			trimmed[i[1]] = str[i[0]];
		i[0]++;
	}
	trimmed[++i[1]] = '\0';
	return (trimmed);
}
