#include "../includes/minishell.h"

//Funcion que devuelve un numero en funcion de como nos hayan pasado la variable:
// export var=hola ---> status 2
// export var ---> status 0
// export var= ----> status 1
// export var = hola   ---> status -1

int     parse_var(char *var)
{
    int     i;

    i = -1;
    if (var[0] == '=' && var[1] == '\0')
        return (-1);
    else if (!ft_strchr(var, '='))
        return (0);
    else
    {
        while (var[++i])
        {
            if (var[i] == '=' && var[i + 1] == '\0')
                return (1);
            else if (var[i] == '=' && var[i + 1] != '\0')
                return (2);
        }
    }
    return (0);
}

int     ft_strlenchr(char *str, char delim)
{
    int     i;
    int     found;

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

char    *ft_strbgchr(char *str, char delim)
{
    int     i;
    int     len;
    char    *new_str;

    i = -1;
    len = ft_strlenchr(str, delim);
    if (!(new_str = ft_substr(str, 0, len)))
        return (NULL);
    return (new_str);
}

int     parse_status(shell_t *shell, char *var, int status, int ok)
{
    char    *new_var;
    char    *var_value;

    if (ok == 1)
    {
        if (status == -1)
            return (ft_error("minishell: bad assignment"));
        else if (status == 0)
        {
            new_var = ft_strdup(var);
            var_value = ft_strdup("''");
            if (find_env_var(shell, new_var) == 0)
                add_env_var(shell, new_var, var_value);
            free(new_var);
            free(var_value);
        }
        else if (status == 2 || status == 1)
        {
            new_var = ft_strbgchr(var, '=');
            if (status  == 2)
                var_value = ft_strtrim(ft_strrchr(var, '='), "=");
            else
                var_value = ft_strdup("''");
            if (find_env_var(shell, new_var) == 1)
                set_env_var(shell, new_var, var_value);
            else
                add_env_var(shell, new_var, var_value);
            free(new_var);
            free(var_value);
        }
    }
    else
        return (0);
    return (1);
}

int     builtin_export(shell_t *shell)
{
    int     i;
    int     status;
    int     ok;

    ok = 1;
    if (shell->cmd_exec_parsed[1] == NULL)
        builtin_env(shell);
    else
    {
        i = 0;
        while (shell->cmd_exec_parsed[++i])
        {
            status = parse_var(shell->cmd_exec_parsed[i]);
            ok = parse_status(shell, shell->cmd_exec_parsed[i], status, ok);
        }
    }
    return (1);
}