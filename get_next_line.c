/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:26:13 by mathispeyre       #+#    #+#             */
/*   Updated: 2024/12/02 14:25:58 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*strdup_to_backslash(char *bank)
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

static char	*read_one_more_time(int fd, char *bank, ssize_t *bytes_read)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*new_bank;

	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read < 0)
	{
		free(bank);
		return (NULL);
	}
	if (*bytes_read == 0)
		return (bank);
	buffer[*bytes_read] = '\0';
	new_bank = ft_strjoin(bank, buffer);
	free(bank);
	return (new_bank);
}

static char	*process_existing_line(char **bank)
{
	char	*line;

	line = strdup_to_backslash(*bank);
	*bank = clean_bank(*bank);
	return (line);
}

static char	*handle_eof(char **bank)
{
	char	*line;

	if (!bank || !*bank)
		return (NULL);
	if (**bank == '\0')
	{
		free(*bank);
		*bank = NULL;
		return (NULL);
	}
	line = ft_strdup(*bank);
	free(*bank);
	*bank = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*bank;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!bank)
	{
		bank = (char *)malloc(1);
		if (!bank)
			return (NULL);
		bank[0] = '\0';
	}
	while (1)
	{
		if (ft_strchr(bank, '\n'))
			return (process_existing_line(&bank));
		bank = read_one_more_time(fd, bank, &bytes_read);
		if (!bank || (bytes_read == 0))
			return (handle_eof(&bank));
	}
}
