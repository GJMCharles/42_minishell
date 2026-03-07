This project has been created as part of the 42 curriculum by <[gechavia](https://intra.42.fr/users/gechavia)>, <[grcharle](https://intra.42.fr/users/grcharle)>.

# 42_Minishell

## Description
The aim of this project is to recreate a miniturized working environment.
One that mimics the wideley known 'shell' of the UNIX environment, and its most used commands.
Those commands are coded, using C functions that operate in almost identital fashion.
While others are to be executed via their binary programs, after locating them using the ENV variable $PATH.

The build-in commands are as followed:
- history
- echo
- pwd
- export
- unset
- env
- exit

List of authorized functions from which the implemented ones are checkedboxed.

- [X] readline
- [ ] rl_clear_history
- [ ] rl_on_new_line
- [ ] rl_replace_line
- [ ] rl_redisplay
- [ ] add_history
- [X] printf
- [X] malloc
- [X] free
- [X] write
- [ ] access
- [ ] open
- [ ] read
- [ ] close
- [ ] fork
- [ ] wait
- [ ] waitpid
- [ ] wait3
- [ ] wait4
- [ ] signal
- [X] sigaction
- [X] sigemptyset
- [ ] sigaddset
- [ ] kill
- [ ] exit
- [ ] getcwd
- [ ] chdir
- [ ] stat
- [ ] lstat
- [ ] fstat
- [ ] unlink
- [ ] execve
- [ ] dup
- [ ] dup2
- [ ] pipe
- [ ] opendir
- [ ] readdir
- [ ] closedir
- [ ] strerror
- [X] perror
- [ ] isatty
- [ ] ttyname
- [ ] ttyslot
- [ ] ioctl
- [ ] getenv
- [X] tcsetattr
- [X] tcgetattr
- [ ] tgetent
- [ ] tgetflag
- [ ] tgetnum
- [ ] tgetstr
- [ ] tgoto
- [ ] tputs

## Instructions

After downloading the project from its remote repository
```bash
git clone <project-repository>
```
Fetch its submodule(s). In this case, the `libft` project.
```bash
git submodule init
```
Verify that all normes of coding conventions are respected.
```bash
norminette -R 2 .
```
Then compile the project in order to obtain its binary.
```bash
make
```
Repeat the process, in order to confirm that no re-link is initiated.
```bash
make
```
And now, finally execute the project using `valgrind`, in order to spy for any potential errors.
```bash
make debug
```
## Resources
