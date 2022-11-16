#ifndef _SHELL_H_
#define _SHELL_H_

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>


/* functions to manipulate strings */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
void print_string(char *string);
char *_memcpy(char *dest, char *src, unsigned int n);

/* Basic process of shell */
int main(int argc, char *argv[], char *env[]);
int shell_loop(char **env);
char *read_command(vhar **env);
char *split_command(char *string);
void forkExec(int status, char **argv, int *count, int *stad_exit);
void rm_new_line(char *string);
int _path(char *args, char **argv, char **env, int *stad_exit);
char *print_path(char *der, char *args);
char **_parser(char *string);
int printenv(char **env, int *stad_exit);
void built_in(char *string, char **argv, char **env, int *exi_t);
void sim_printShell(char *string);
void print_count(int *count);
int _putchar(char c);
int func_ctrl_d(char *string, ssize_t read, int *stad_exit);

/* finction signal */
void sign_handler(int signal);

#endif /* _SHELL_H_ */

