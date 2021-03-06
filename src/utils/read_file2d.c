/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 10:53:04 by kehuang           #+#    #+#             */
/*   Updated: 2019/10/01 10:53:05 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "wutils.h"

static size_t	count_char(const char *s, const char c)
{
	size_t	res;
	size_t	idx;

	res = 0;
	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == c)
			++res;
		++idx;
	}
	return (res);
}

static int		split_line(char **res, char *buf)
{
	size_t	size_line;
	size_t	res_idx;
	char	*new_line_ptr;
	char	*buf_ptr;

	buf_ptr = buf;
	res_idx = 0;
	while ((new_line_ptr = ft_strchr(buf_ptr, '\n')) != NULL)
	{
		size_line = (size_t)(new_line_ptr - buf_ptr);
		if ((res[res_idx] = (char *)malloc(sizeof(char) * (size_line + 1)))
				== NULL)
		{
			while (--res_idx != (size_t)-1)
				free(res[res_idx]);
			return (-1);
		}
		ft_memcpy(res[res_idx], buf_ptr, size_line);
		res[res_idx][size_line] = '\0';
		buf_ptr = new_line_ptr + 1;
		++res_idx;
	}
	return (0);
}

char			**read_file2d(char *filename)
{
	size_t	size_line;
	char	*file;
	char	**res;

	if ((file = read_file(filename)) == NULL)
		return (NULL);
	size_line = count_char(file, '\n');
	res = (char **)malloc(sizeof(char *) * (size_line + 1));
	if (res != NULL)
	{
		res[size_line] = 0;
		if (split_line(res, file) != 0)
		{
			free(res);
			res = NULL;
		}
	}
	free(file);
	return (res);
}
