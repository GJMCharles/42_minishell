#include "_execute.h"

char *read_heredoc(const char *delimiter)
{
	char *heredoc_content = ft_calloc(sizeof(char), MAX_HEREDOC_LINES * MAX_LINE_LENGTH);
	char line[MAX_LINE_LENGTH];
	
	printf("heredoc> ");
	while (fgets(line, sizeof(line), stdin)) {
		line[strcspn(line, "\n")] = '\0';  // Remove newline
		if (strcmp(line, delimiter) == 0) {
			break;
		}
		ft_strlcat(heredoc_content, line, ft_strlen(line));
		ft_strlcat(heredoc_content, "\n", ft_strlen("\n"));
		printf("heredoc> ");
	}
	return heredoc_content;
}

int	execute_command(t_cmd *cmd, int input_fd, int output_fd, int *bg_pid)
{
	int	status;

	status = 0;
	pid_t pid = fork();

	if (pid == 0)
	{
		if (cmd->infile)
		{
			int fd = open(cmd->infile, O_RDONLY);
			if (fd < 0)
			{
				perror("failed to open input");
				exit(1);
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
		}
		else if (input_fd != STDIN_FILENO)
		{
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}

		if (cmd->heredoc_delimiter)
		{
			char *heredoc_content = read_heredoc(cmd->heredoc_delimiter);
			int pipefd[2];
			if (pipe(pipefd) < 0)
				exit(EXIT_FAILURE);
			if (write(pipefd[1], heredoc_content, ft_strlen(heredoc_content)) < 0)
				exit(EXIT_FAILURE);
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			free(heredoc_content);
		}

		if (cmd->outfile)
		{
			int flags = O_WRONLY | O_CREAT;
			flags |= cmd->append_mode ? O_APPEND : O_TRUNC;
			int fd = open(cmd->outfile, flags, 0644);
			if (fd < 0)
			{
				perror("open output");
				exit(1);
			}
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		else if (output_fd != STDOUT_FILENO)
		{
			dup2(output_fd, STDOUT_FILENO);
			close(output_fd);
		}

		if (execvp(cmd->args[0], cmd->args) < 0) {
            perror("execve failed");
            exit(EXIT_FAILURE);
        }
	}
	else if (pid < 0)
		return (perror("failed to load 'fork'"), -1);


	if (!cmd->background)
		return (waitpid(pid, &status, 0), -999);

	*bg_pid = pid;
	printf("[%d] %d\n", *bg_pid, pid);
	return (0);
}