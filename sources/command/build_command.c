#include "_command.h"

void	build_commands_extended_others(t_cmd_pipeline **pipeline, t_cmd **cmd)
{
	if ((*cmd)->argc > 0 || (*cmd)->infile || (*cmd)->outfile || (*cmd)->heredoc_delimiter)
	{
		(*cmd)->args[(*cmd)->argc] = NULL;
		(*pipeline)->commands[(*pipeline)->nb_commands] = *cmd;
		(*pipeline)->operators[(*pipeline)->nb_commands] = TOKEN_SEMICOLON;
		(*pipeline)->nb_commands += 1;
	}
	else
		free(cmd);
}

void	build_commands_extended_special(t_cmd_pipeline **pipeline, t_cmd **cmd, t_token *token, size_t length)
{
	(*cmd)->args[(*cmd)->argc] = NULL;
	(*pipeline)->commands[(*pipeline)->nb_commands] = *cmd;
	(*pipeline)->operators[(*pipeline)->nb_commands] = token->type;
	(*pipeline)->nb_commands += 1;
	if (!create_command(cmd, length))
		return ;
	if (token->type == TOKEN_BACKGROUND)
		(*cmd)->background = 1;
}

void	build_commands_extended_redirection(t_opt_cmd *options, t_token_type token_type)
{
	options->expecting_filename = 1;
	options->last_token = token_type;
}

void	build_commands_extended_word(t_opt_cmd *options, t_cmd **cmd, char *value)
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

t_cmd_pipeline  *build_commands_pipeline(t_token *tokens)
{
	t_cmd_pipeline	*pipeline;
	t_cmd			*cmd;
	t_opt_cmd		options;
	t_token			*t;

	options = (t_opt_cmd) { 0, 0, TOKEN_SEMICOLON };
	if (!create_command_pipeline(&pipeline))
		return (NULL);
	if (!create_command(&cmd, token_count(tokens)))
		return (NULL);
	t = tokens;
	while (t)
	{
		if (t->type == TOKEN_WORD)
			build_commands_extended_word(&options, &cmd, t->value);
		else if (t->type == TOKEN_REDIR_IN || t->type == TOKEN_REDIR_OUT || t->type == TOKEN_REDIR_APPEND)
			build_commands_extended_redirection(&options, t->type);
		else if (t->type == TOKEN_HEREDOC)
			options.expecting_heredoc = 1;
		else if (t->type == TOKEN_PIPE || t->type == TOKEN_AND || t->type == TOKEN_OR || t->type == TOKEN_BACKGROUND || t->type == TOKEN_SEMICOLON)
			build_commands_extended_special(&pipeline, &cmd, t, token_count(tokens));
		t = t->next;
	}
	build_commands_extended_others(&pipeline, &cmd);
	return (pipeline);
}
