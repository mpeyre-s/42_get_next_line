/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:26:51 by mathispeyre       #+#    #+#             */
/*   Updated: 2024/12/02 14:21:23 by mathispeyre      ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*clean_bank(char *bank)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	while (bank[i] != '\n' && bank[i] != '\0')
		i++;
	if (bank[i] == '\0')
	{
		free(bank);
		return (NULL);
	}
	j = ft_strlen(&bank[i + 1]);
	result = (char *)malloc(j + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (bank[++i])
		result[j++] = bank[i];
	result[j] = '\0';
	free(bank);
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
