#include "_execute.h"

int	execute_pipeline(t_cmd_pipeline *pipeline)
{
	t_opt_pipe	option;
	int			i;

	option.status = 0;
	ft_memcpy(option.prev_pipe,
		(int[]){STDIN_FILENO, STDOUT_FILENO}, sizeof(option.prev_pipe));
	ft_memcpy(option.next_pipe, (int[]){0, 0}, sizeof(option.next_pipe));
	option.input_fd = STDIN_FILENO;
	option.nb_bg = 0;
	i = 0;
	while (i < pipeline->nb_commands)
	{
		t_cmd	*cmd = pipeline->commands[i];
		t_token_type op = pipeline->operators[i];

		if (i > 0)
		{
			int prev_op = pipeline->operators[i - 1];
			if ((prev_op == TOKEN_AND && option.status != 0)
				|| (prev_op == TOKEN_OR && option.status == 0))
				continue;
		}
		if (op == TOKEN_PIPE)
		{
			if (pipe(option.next_pipe) < 0)
				exit(EXIT_FAILURE);
		}

		int output_fd = (op == TOKEN_PIPE) ? option.next_pipe[1] : STDOUT_FILENO;
		int bg_pid = 0;

		if (cmd->background) {
			option.status = execute_command(cmd, option.input_fd, output_fd, &bg_pid);
			if (bg_pid > 0)
				option.bg_pids[option.nb_bg++] = bg_pid;
		}
		else
		{
			option.status = execute_command(cmd, option.input_fd, output_fd, &bg_pid);
		}

		if (op == TOKEN_PIPE)
		{
			close(option.next_pipe[1]);
			if (option.input_fd != STDIN_FILENO)
				close(option.input_fd);
			option.input_fd = option.next_pipe[0];
		} else
		{
			if (option.input_fd != STDIN_FILENO)
				close(option.input_fd);
			option.input_fd = STDIN_FILENO;
		}

		if (cmd->background)
		{
            // Don't wait, just continue
        }
		i += 1;
	}
	return (option.status);
}
