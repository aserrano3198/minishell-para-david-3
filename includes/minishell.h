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

typedef struct  shell_s
{
    char    **env;
    char    **commands;
    char    **cmd_exec_parsed;
}               shell_t;

int     builtin_cd(shell_t *shell);
int     builtin_exit(shell_t *shellm);
void    display_prompt(shell_t *shell);
char    *get_env_var(shell_t *shell, char *env, char *delim);
void    set_env_var(shell_t *shell, char *env, char *new_path);
int     builtin_env(shell_t *shell);
int     ft_error(char *str);
int     parse_commands(shell_t *shell);
int     launch(shell_t *shell);
int     exec_command(shell_t *shell);

#endif