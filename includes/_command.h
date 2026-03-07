#ifndef _COMMAND_H
# define _COMMAND_H

void			handle_heredoc(void);
void			handle_infile(void);
void			handle_append(void);
void			handle_outfile(void);
void			handle_ternary(void);
void			handle_pipe(void);
void			handle_and(void);
void			handle_background(void);

#endif // _COMMAND_H
