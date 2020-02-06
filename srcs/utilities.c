#include "../includes/minishell.h"

int     is_replace(char *str, int pos, char *replace)
{
    int     i;

    i = 0;
    while (str[pos])
    {
        if (str[pos] == replace[i])
        {
            i++;
            pos++;
        }
        else
            break ;
        if (replace[i] == '\0')
            return (1);
    }
    return (0);
}

char    *ft_replacestr(char *str_to_replace, char *replace, char *value)
{
    char    *str_replaced;
    int     len;
    int     i;
    int     j;
    int     t;

    len = ft_strlen(str_to_replace) - ft_strlen(replace) + ft_strlen(value);
    if (!(str_replaced = (char*)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    j = 0;
    while (str_to_replace[i])
    {
        if (is_replace(str_to_replace, i, replace))
        {
            t = 0;
            while (value[t])
                str_replaced[j++] = value[t++];
            i += ft_strlen(replace);
        }
        if (str_to_replace[i])
            str_replaced[j++] = str_to_replace[i++];
    }
    free(str_to_replace);
    str_replaced[j] = '\0';
    return (str_replaced);
}