#include "../includes/minishell.h"

//Funcion que devuelve la ruta de la variable env pasada con un delimitador para coger
// lo que hay despues del '=' PWD=/user..... o si queremos coger la carpeta en que se encuentra el usuario 'ver display_prompt'
char        *get_env_var(shell_t *shell, char *env, char *delim)
{
    int     i;
    char    *path;
    char    *tmp;
    size_t  len_path;

    len_path = ft_strlen(env);
    i = -1;
    while (shell->env[++i])
        if ((ft_strncmp(shell->env[i], env, len_path)) == 0)
        {
            tmp = ft_strrchr(shell->env[i], delim[0]);
            break ;
        }
    path = ft_strtrim(tmp, delim);
    return (path);
}

//Funcion que actualiza la ruta de la variable env pasada
void        set_env_var(shell_t *shell, char *env, char *new_path)
{
    int     i;
    char    *tmp;
    size_t  len_path;

    tmp = ft_strjoin(env, "=");
    len_path = ft_strlen(tmp);
    i = -1;
    while (shell->env[++i])
        if ((ft_strncmp(shell->env[i], tmp, len_path)) == 0)
        {
            free(shell->env[i]);
            shell->env[i] = ft_strjoin(tmp, new_path);
            free(tmp);
            return ;
        }
}

// Funcion que añade una nueva variable de entorno
void        add_env_var(shell_t *shell, char *new_env, char *new_value)
{
    int     i;
    char    **env;
    int     cpy;
    char    *tmp;

    i = 0;
    cpy = -1;
    while (shell->env[i])
        i++;
    if (!(env = (char **)malloc(sizeof(char*) * (i + 2))))
        return ;
    i = -1;
    while (shell->env[++i])
        env[i] = shell->env[i];
    tmp = ft_strjoin(new_env, "=");
    env[i] = ft_strjoin(tmp, new_value);
    free(tmp);
    env[i + 1] = NULL;
    free(shell->env);
    shell->env = env;
}

int         find_env_var(shell_t *shell, char *env_to_find)
{
    int     i;
    size_t  len_path;
    char    *tmp;

    tmp = ft_strjoin(env_to_find, "=");
    len_path = ft_strlen(tmp);
    i = -1;
    while (shell->env[++i])
        if ((ft_strncmp(shell->env[i], tmp, len_path)) == 0)
        {
            free(tmp);
            return (1);
        }
    return (0);
}

void        display_prompt(shell_t *shell)
{
    char    *path_dir;
    char    *user;

    user = get_env_var(shell, "USER", "=");
    path_dir = get_env_var(shell, "PWD", "/");
    ft_printf("\033[32m%s\033[0m@\033[33mminishell\033[0m \033[34m%s\033[0m > ", user, path_dir);
    free(path_dir);
    free(user);
}