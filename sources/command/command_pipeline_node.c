#include "_command.h"

void	destroy_command_pipeline(t_cmd_pipeline **pipe)
{
	t_cmd_pipeline	*tmp_pipe;
	int				i;

	tmp_pipe = *pipe;
	if (tmp_pipe)
	{
		if (tmp_pipe->operators)
			free(tmp_pipe->operators);
		if (tmp_pipe->commands)
		{
			i = 0;
			while (i++ < tmp_pipe->nb_commands)
				destroy_command(&tmp_pipe->commands[i - 1]);
			free(tmp_pipe->commands);
		}
		free(tmp_pipe);
	}
	*pipe = NULL;
}

int	create_command_pipeline(t_cmd_pipeline **pipe)
{
	t_cmd_pipeline	*tmp_pipe;

	*pipe = NULL;
	tmp_pipe = (t_cmd_pipeline *) ft_calloc(sizeof(t_cmd_pipeline), 1);
	if (!tmp_pipe)
		return (perror("failed to allocate 'struct s_cmd_pipeline'"), 0);
	tmp_pipe->commands = (t_cmd **) ft_calloc(sizeof(t_cmd *), MAX_COMMANDS);
	if (!tmp_pipe->commands)
	{
		destroy_command_pipeline(&tmp_pipe);
		return (perror("failed to allocate 'struct s_cmd *'"), 0);
	}
	tmp_pipe->operators = (t_token_type *) ft_calloc(sizeof(t_token_type), MAX_COMMANDS);
	if (!tmp_pipe->operators)
	{
		destroy_command_pipeline(&tmp_pipe);
		return (perror("failed to allocate 'int'"), 0);
	}
	tmp_pipe->nb_commands = 0;
	*pipe = tmp_pipe;
	return (1);
}
