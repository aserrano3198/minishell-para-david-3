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

int lsh_cd(char **args);
int lsh_exit();

char *builtin_str[] = {
    "cd",
    "exit"
};

int (*builtin_func[]) (char **) = {
    &lsh_cd,
    &lsh_exit
};


#endif