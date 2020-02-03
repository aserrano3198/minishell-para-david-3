#include "../includes/minishell.h"

int     ft_strlenchr(char *str, char limit)
{
    int     i;
    int     found;

    i = -1;
    found = 0;
    while (str[++i] && found != 1)
        if (str[i] == limit)
            found = 1;
    if (str[i] == '\0')
        return (-1);
    else
        return (i - 1);
}

char    *ft_strbeginchr(char *str, char delim)
{
    int     limit;
    char    *ret;

    limit = ft_strlenchr(str, delim);
    ret = ft_substr(str, 0, limit);
    return (ret);
}

int     builtin_export(shell_t *shell)
{
    int     i;
    int     update;
    int     len_path;
    char    *var;
    char    *new_var;

    i = -1;
    update = 0;
    if (shell->cmd_exec_parsed[1] == NULL)
        builtin_env(shell);
    else if (shell->cmd_exec_parsed[1] != NULL)
    {
        new_var = ft_strbeginchr(shell->cmd_exec_parsed[1], '=');
        len_path = ft_strlen(new_var);
        while (shell->env[++i] && update != 1)
        {
            var = ft_strbeginchr(shell->env[i], '=');
            if ((ft_strncmp(var, new_var, len_path)) == 0)
                update = 1;
        }
        if (update == 0)
            add_env_var(shell, shell->cmd_exec_parsed[1]);
        else
        {
            free(new_var);
            new_var = ft_strtrim(ft_strrchr(shell->cmd_exec_parsed[1], '='), "=");
            set_env_var(shell, var, new_var);
        }
        free(var);
        free(new_var);
    }
    return (1);
}