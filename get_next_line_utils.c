/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:26:51 by mathispeyre       #+#    #+#             */
/*   Updated: 2024/11/29 15:37:16 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	size = 0;
	while (s1[size])
		size++;
	i = size;
	while (s2[size - i])
		size++;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = -1;
	while (s2[++j])
		result[i + j] = s2[j];
	result[i + j] = '\0';
	return (result);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*strdup_to_backslash(char *bank)
{
	size_t	len;
	size_t	i;
	char	*result;

	len = 0;
	while (bank[len] && bank[len] != '\n')
		len++;
	result = (char *)malloc((len + 2) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = bank[i];
		i++;
	}
	result[i] = '\n';
	result[i + 1] = '\0';
	return (result);
}

char	*clean_bank(char *bank)
{
	size_t	len;
	size_t	i;
	size_t	i2;
	char	*result;

	i = 0;
	while (bank[i] != '\n' && bank[i] != '\0')
		i++;
	if (bank[i] == '\0')
	{
		free(bank);
		return (NULL);
	}
	i++;
	len = 0;
	while (bank[i + len] != '\0')
		len++;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i2 = 0;
	while (i2 < len)
	{
		result[i2] = bank[i + i2];
		i2++;
	}
	result[i2] = '\0';
	free(bank);
	return (result);
}
