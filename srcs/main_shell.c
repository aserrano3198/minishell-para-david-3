#include "../includes/minishell.h"

int         len_env(char *env[])
{
    int     len;

    len = 0;
    while (env[len])
        len++;
    return (len);
}

shell_t     *init_save_env(int argc, char *argv[], char *env[])
{
    shell_t *shell;
    int     size;
    int     i;

    (void)argc;
    (void)argv;
    if (!(shell = (shell_t*)malloc(sizeof(shell_t) * 1)))
        return (NULL);
    size = len_env(env);
    if (!(shell->env = (char**)malloc(sizeof(char*) * (size + 1))))
        return (NULL);
    shell->env[size] = NULL;
    i = -1;
    while (env[++i])
        if (!(shell->env[i] = ft_strdup(env[i])))
            return (NULL);
    return (shell);
}

void        banner(shell_t *shell)
{
    launch(shell, "/usr/bin/clear");
    ft_printf("\e[90m/********************************************************\\\e[0m\n");
    ft_printf("\e[90m/*                                                      *\\\n");
    ft_printf("\e[90m/*\e[0m  \e[35m   ,-.-. o       o       |           |     |     \e[0m   \e[90m*\\\e[0m\n");
    ft_printf("\e[90m/*\e[0m  \e[35m   | | | | ,---. |       |---.       |     |    \e[0m    \e[90m*\\\e[0m\n");
    ft_printf("\e[90m/*\e[0m  \e[35m   | | | | |   | | ,---. |   | ,---. |     |    \e[0m    \e[90m*\\\e[0m\n");
    ft_printf("\e[90m/*\e[0m  \e[35m   | | | | |   | | `---. |   | |---' |     |    \e[0m    \e[90m*\\\e[0m\n");
    ft_printf("\e[90m/*\e[0m  \e[35m   ` ' ' ` `   ` ` `---' `   ' `---' `---' `---'\e[0m    \e[90m*\\\e[0m\n");
    ft_printf("\e[90m/*                                                      *\\\e[0m\n");
    ft_printf("\e[90m/*                                                      *\\\e[0m\n");
    ft_printf("\e[90m/*\e[0m     \e[36mDeveloped by:      aserrano\e[0m                      \e[90m*\\\e[0m\n");
    ft_printf("\e[90m/*\e[0m                      \e[36m  pcuadrad     \e[0m                 \e[90m*\\\e[0m\n");
    ft_printf("\e[90m/*                                                      *\\\e[0m\n");
    ft_printf("\e[90m/********************************************************\\\e[0m\n");
}
//Funcion para probar signal.
//Control+C ahora no quita el programa.
//Habria que hacer que haga un salto de linea y vuelva a mostrar el prompt y continue.
void         test(int test)
{
    (void)test;
}

int         main(int argc, char *argv[], char *env[])
{
    char    *line;
    int     status;
    shell_t *shell;

    
    if (!(shell = init_save_env(argc, argv, env)))
        return (ft_error("Failed allocate memory"));
    banner(shell);
    status = 1;
    signal(SIGINT, test);
    while (status)
    {
        display_prompt(shell);
        if (get_next_line(STDIN_FILENO, &line) == 0 && line[0] == '\0')
            break;
        shell->commands = ft_split(line, ';');
        free(line);
        status = parse_commands(shell);
        free(shell->commands);
    }
    return (0);
}