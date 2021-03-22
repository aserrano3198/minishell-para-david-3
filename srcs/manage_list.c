/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:13:00 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/14 12:27:51 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_pipe			*ft_lstlast_pipe(t_pipe *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void			ft_lstadd_back_pipe(t_pipe **alst, t_pipe *newitem)
{
	t_pipe *item;

	if (!*alst && newitem)
		*alst = newitem;
	else if (*alst && newitem)
	{
		item = *alst;
		while (item->next)
			item = item->next;
		item->next = newitem;
	}
}

void			ft_lstclear_pipe(t_pipe **lst)
{
	t_pipe	*tmp;
	int		i;

	i = 0;
	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		i = 0;
		while (tmp->pipe_parse[i])
			free(tmp->pipe_parse[i++]);
		free(tmp->pipe_parse);
		free(*lst);
		*lst = tmp->next;
	}
	*lst = NULL;
}

t_pipe			*new_pipe(char *command, int have_pipe, t_pipe *pipes, int read)
{
	t_pipe *new;

	if (!(new = malloc(sizeof(t_pipe))))
		return (NULL);
	new->pipe_parse = ft_comand_split(command, ' ');
	new->pipe = have_pipe;
	new->read = read;
	new->previous = ft_lstlast_pipe(pipes);
	new->next = 0;
	return (new);
}
