#include "_command.h"

void	build_command_extended_others(t_cmd_pipeline **pipe, t_cmd **cmd)
{
	if ((*cmd)->argc > 0 || (*cmd)->infile || (*cmd)->outfile || (*cmd)->heredoc_delimiter)
	{
		(*cmd)->args[(*cmd)->argc] = NULL;
		(*pipe)->commands[(*pipe)->nb_commands] = *cmd;
		(*pipe)->operators[(*pipe)->nb_commands] = TOKEN_SEMICOLON;
		(*pipe)->nb_commands += 1;
	}
	else
	{
		free(cmd);
	}
}

void	build_command_extended_special(t_cmd_pipeline **pipe, t_cmd **cmd, t_token *token, size_t length)
{
	(*cmd)->args[(*cmd)->argc] = NULL;
	(*pipe)->commands[(*pipe)->nb_commands] = *cmd;
	(*pipe)->operators[(*pipe)->nb_commands] = token->type;
	(*pipe)->nb_commands += 1;
	if (!create_command(cmd, length))
		return ;
	if (token->type == TOKEN_BACKGROUND)
		(*cmd)->background = 1;
}

void	build_command_extended_redirection(t_cmd_build *options, t_token_type token_type)
{
	options->expecting_filename = 1;
	options->last_token = token_type;
}

void	build_command_extended_word(t_cmd_build *options, t_cmd **cmd, char *value)
{
	if (options->expecting_filename)
	{
		if (options->last_token == TOKEN_REDIR_IN)
			(*cmd)->infile = ft_strdup(value);
		else if (options->last_token == TOKEN_REDIR_OUT)
		{
			(*cmd)->outfile = ft_strdup(value);
			(*cmd)->append_mode = 0;
		}
		else if (options->last_token == TOKEN_REDIR_APPEND)
		{
			(*cmd)->outfile = ft_strdup(value);
			(*cmd)->append_mode = 1;
		}
		options->expecting_filename = 0;
	}
	else if (options->expecting_heredoc)
	{
		(*cmd)->heredoc_delimiter = ft_strdup(value);
		options->expecting_heredoc = 0;
	}
	else
		(*cmd)->args[(*cmd)->argc++] = ft_strdup(value);
}

t_cmd_pipeline  *build_command_pipeline(t_token *tokens)
{
	t_cmd_pipeline	*pipe;
	t_cmd			*cmd;
	t_cmd_build		options;
	t_token			*t;

	options = (t_cmd_build) { 0, 0, TOKEN_SEMICOLON };
	if (!create_command_pipeline(&pipe))
		return (NULL);
	if (!create_command(&cmd, token_count(tokens)))
		return (NULL);
	t = tokens;
	while (t)
	{
		if (t->type == TOKEN_WORD)
			build_command_extended_word(&options, &cmd, t->value);
		else if (t->type == TOKEN_REDIR_IN || t->type == TOKEN_REDIR_OUT || t->type == TOKEN_REDIR_APPEND)
			build_command_extended_redirection(&options, t->type);
		else if (t->type == TOKEN_HEREDOC)
			options.expecting_heredoc = 1;
		else if (t->type == TOKEN_PIPE || t->type == TOKEN_AND || t->type == TOKEN_OR || t->type == TOKEN_BACKGROUND || t->type == TOKEN_SEMICOLON)
			build_command_extended_special(&pipe, &cmd, t, token_count(tokens));
		t = t->next;
	}
	build_command_extended_others(&pipe, &cmd);
	return (pipe);
}
