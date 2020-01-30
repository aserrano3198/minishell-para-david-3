/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:53:13 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 16:53:05 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr_chr(char **str, char c, int fd)
{
	char	*line;
	char	*dup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[fd][i] != c)
		i++;
	line = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		line[j] = str[fd][j];
		j++;
	}
	line[j] = '\0';
	dup = ft_strdup(str[fd] + j + 1);
	free(str[fd]);
	str[fd] = dup;
	return (line);
}

int			ft_ret(char **str, int i, char **line, int fd)
{
	if (i < 0)
		return (-1);
	else if (i == 0 && str[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_strchr_gnl(str[fd], '\n') == 1)
	{
		*line = ft_substr_chr(str, '\n', fd);
		return (1);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	int			i;
	static char	*str[4096];
	char		*dup;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buf);
		else
		{
			dup = ft_strjoin_and_free(str[fd], buf);
			str[fd] = dup;
		}
		if (ft_strchr_gnl(str[fd], '\n'))
			break ;
	}
	return (ft_ret(str, i, line, fd));
}
