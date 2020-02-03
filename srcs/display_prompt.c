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
            tmp = ft_strrchr(shell->env[i], delim[0]);
    path = ft_strtrim(tmp, delim);
    return (path);
}

//Funcion que actualiza la ruta de la variable env pasada
void        set_env_var(shell_t *shell, char *env, char *new_path)
{
    int     i;
    char    *tmp;
    size_t  len_path;

    len_path = ft_strlen(env);
    i = -1;
    while (shell->env[++i])
        if ((ft_strncmp(shell->env[i], env, len_path)) == 0)
        {
            free(shell->env[i]);
            tmp = ft_strjoin(env, "=");
            shell->env[i] = ft_strjoin(tmp, new_path);
            free(tmp);
        }
}

void        display_prompt(shell_t *shell)
{
    char    *path_dir;
    char    *user;

    user = get_env_var(shell, "USER", "=");
    path_dir = get_env_var(shell, "PWD", "/");
    ft_printf("%s@minishell %s > ", user, path_dir);
    free(path_dir);
    free(user);
}