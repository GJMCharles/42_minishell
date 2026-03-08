#include "minishell.h"

/**
 * Command CD
 */

int change_directory(t_minishell *shell, char **args)
{
	char    *path;

    if (!args[1])
    {
        path = getenv("HOME");
        if (!path)
            return (ft_putstr_fd("cd: HOME not set\n", 2), 1);
    }
    else
        path = args[1];
    if (chdir(path) == -1)
        return (perror("cd"), 1);
    return (0);
}
