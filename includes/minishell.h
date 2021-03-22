/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:30:53 by aserrano          #+#    #+#             */
/*   Updated: 2020/02/14 15:22:22 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include "../srcs/libft/libft.h"

int						g_forking;
int						g_read;

typedef struct		s_pipe
{
	char			**pipe_parse;
	int				pipe;
	int				read;
	int				fd[2];
	struct s_pipe	*next;
	struct s_pipe	*previous;
}					t_pipe;

typedef struct		s_shell
{
	char			**env;
	char			**commands;
	char			**cmd_exec_parsed;
	char			**path;
	int				status_last_command;
	t_pipe			*pipe_list;
	int				redirection_out;
	int				redirection_in;
	int				read;
}					t_shell;

int					ft_countwords2(char *s, char c);
int					ft_jump_quotes(char *s, int i);
char				**ft_comand_split(char *s, char c);
char				**ft_split_pc(char *s, char c);
int					ft_free(char **ret, char *trimmed,
					char **command, int selector);
int					ft_fail_message(char *str);
int					ft_redirection_pipe(t_shell *shell, char **command);
int					ft_redirection(t_shell *shell, char **command);
int					exec_command_redirection(t_shell *shell);
int					builtin_pwd(t_shell *shell);
int					builtin_echo(t_shell *shell);
int					builtin_cd(t_shell *shell);
int					ft_strlenchr(char *str, char delim);
int					builtin_exit(t_shell *shell);
int					builtin_export(t_shell *shell);
int					builtin_unset(t_shell *shell);
void				display_prompt();
char				**ft_arraydelone(char **array, char *to_delete);
void				add_env_var(t_shell *shell, char *new_env, char *new_value);
int					find_env_var(t_shell *shell, char *env_to_find);
char				*get_env_var(t_shell *shell, char *env, char *delim);
void				set_env_var(t_shell *shell, char *env, char *new_path);
int					del_env_var(t_shell *shell, char *env_to_del);
char				*ft_replacestr(char *str_to_replace,
					char *replace, char *value);
int					builtin_env(t_shell *shell);
int					ft_error(char *str);
void				parse_commands(t_shell *shell);
int					launch(t_shell *shell, char *path_exec);
int					exec_command(t_shell *shell);
t_pipe				*ft_lstlast_pipe(t_pipe *lst);
void				ft_lstadd_back_pipe(t_pipe **alst, t_pipe *newitem);
t_pipe				*new_pipe(char *command, int have_pipe,
					t_pipe *pipes, int read);
char				*ft_strbgchr(char *str, char delim);
void				free_command(char **command);
void				parse_env_vars(t_shell *shell);
int					ft_fail_message(char *str);
int					ft_redirection(t_shell *shell, char **command);
int					ft_is_redirection(t_shell *shell, char *command);
int					ft_pipe(t_shell *shell, t_pipe *list_cmnd);
t_shell				*init_save_env(int argc, char *argv[], char *env[]);
void				ft_lstclear_pipe(t_pipe **lst);
void				ft_cmdfail(char *str);

#endif
