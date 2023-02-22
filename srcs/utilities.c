/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:05:52 by aserrano          #+#    #+#             */
/*   Updated: 2020/02/11 16:06:58 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ft_strlenchr(char *str, char delim)
{
	int		i;
	int		found;

	found = 0;
	i = -1;
	while (str[++i] && found != 1)
		if (str[i] == delim)
			found = 1;
	if (found == 0)
		return (0);
	else
		return (i - 1);
}

char			*ft_strbgchr(char *str, char delim)
{
	int		len;
	char	*new_str;

	
	len = ft_strlenchr(str, delim);
	if (!(new_str = ft_substr(str, 0, len)))
		return (NULL);
	return (new_str);
}

size_t			ft_arraylen(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char			**ft_arraydelone(char **array, char *to_delete)
{
	size_t		len_array;
	size_t		len_delete;
	char		**new_array;
	int			i;
	int			j;

	len_delete = ft_strlen(to_delete);
	len_array = ft_arraylen(array);
	if (!(new_array = (char**)malloc(sizeof(char*) * (len_array))))
		return (NULL);
	i = -1;
	j = 0;
	while (array[++i])
		if (ft_strncmp(array[i], to_delete, len_delete) != 0)
			new_array[j++] = array[i];
		else
			free(array[i]);
	new_array[j] = NULL;
	free(array);
	free(to_delete);
	return (new_array);
}
