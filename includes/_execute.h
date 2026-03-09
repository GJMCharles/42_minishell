#ifndef _EXECUTE_H
# define _EXECUTE_H

# include "_command.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_opt_pipe
{
	int		status;
	int		prev_pipe[2];
	int		next_pipe[2];
	int		input_fd;
	pid_t	bg_pids[MAX_COMMANDS];
	int		nb_bg;
}	t_opt_pipe;

char	*read_heredoc(const char *delimiter);
int		execute_command(t_cmd *cmd, int input_fd, int output_fd, int *bg_pid);

int		execute_pipeline(t_cmd_pipeline *pipeline);

#endif // _EXECUTE_H
