/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:26:13 by mathispeyre       #+#    #+#             */
/*   Updated: 2024/11/29 15:31:52 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_one_more_time(int fd, char *bank)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*new_bank;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(bank);
		return (NULL);
	}
	if (bytes_read == 0)
		return (bank);
	buffer[bytes_read] = '\0';
	new_bank = ft_strjoin(bank, buffer);
	free(bank);
	return (new_bank);
}

char	*get_next_line(int fd)
{
	static char	*bank;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!bank)
	{
		bank = (char *)malloc(1 * sizeof(char));
		if (!bank)
			return (NULL);
		bank[0] = '\0';
	}
	bank = read_one_more_time(fd, bank);
	while (bank && !ft_strchr(bank, '\n'))
	{
		bank = read_one_more_time(fd, bank);
		if (!bank)
			return (NULL);
	}
	if (!bank)
		return (NULL);
	line = strdup_to_backslash(bank);
	bank = clean_bank(bank);
	return (line);
}
