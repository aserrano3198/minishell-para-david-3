#include "../includes/minishell.h"

int     builtin_cd(shell_t *shell)
{
    char    *updt_path;
    char    *home_path;
    char    *old_path;
    char    tmp[4097];
    char    tmp1[4097];

    old_path = getcwd(tmp1, 4096);
    if (shell->cmd_exec_parsed[1] != NULL && shell->cmd_exec_parsed[2] != NULL)
        ft_printf("cd: string not in pwd: %s\n", shell->cmd_exec_parsed[1]);
    else if (shell->cmd_exec_parsed[1] == NULL || !ft_strncmp(shell->cmd_exec_parsed[1], "~", 2))
    {
        home_path = get_env_var(shell, "HOME", "=");
        chdir(home_path);
        free(home_path);
    }
    else if (!ft_strncmp(shell->cmd_exec_parsed[1], "-", 2))
    {
        home_path = get_env_var(shell, "OLDPWD", "=");
        chdir(home_path);
        free(home_path);
    }
    else if (chdir(shell->cmd_exec_parsed[1]) != 0)
        perror("cd");
    updt_path = getcwd(tmp, 4096);
    set_env_var(shell, "PWD", updt_path);
    set_env_var(shell, "OLDPWD", old_path);
    return (1);
}