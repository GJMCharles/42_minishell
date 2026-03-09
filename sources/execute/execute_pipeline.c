#include "_execute.h"

// int	execute_pipeline(t_cmd_pipeline *pipeline)
// {
// 	int		status;
// 	int		prev_pipe[2];
// 	int		next_pipe[2];
// 	int		input_fd;
// 	pid_t	bg_pids[MAX_COMMANDS];
// 	int		num_bg;
// 	int		i;

// 	status = 0;
// 	prev_pipe[0] = STDIN_FILENO;
// 	prev_pipe[1] = STDOUT_FILENO;
// 	input_fd = STDIN_FILENO;
// 	num_bg = 0;
// 	i = 0;
// 	while (i < pipeline->nb_commands)
// 	{
// 		t_cmd	*cmd;
// 		int		operator;

// 		cmd = pipeline->commands[i];
// 		operator = pipeline->operators[i];

// 		if (i > 0)
// 		{
// 			int prev_op = pipeline->operators[i - 1];
// 			if ((prev_op == TOKEN_AND && status != 0)
// 				|| (prev_op == TOKEN_OR && status == 0))
// 				continue ;
// 		}
// 		if (operator == TOKEN_PIPE)
// 			pipe(next_pipe);
// 		int output_fd = (operator == TOKEN_PIPE) ? next_pipe[1] : STDOUT_FILENO;
// 		int bg_pid = 0;

// 		status = execute_command(cmd, input_fd, output_fd, &bg_pid);
// 		if (cmd->background && bg_pid > 0)
// 			bg_pids[num_bg++] = bg_pid;

// 		if (input_fd != STDIN_FILENO)
// 			close(input_fd);
// 		if (operator == TOKEN_PIPE)
// 		{
// 			close(next_pipe[1]);
// 			input_fd = next_pipe[0];
// 		}
// 		else
// 			input_fd = STDIN_FILENO;
// 		if (cmd->background)
// 		{
// 			//
// 		}
// 		i += 1;
// 	}
// 	return (status);
// }
