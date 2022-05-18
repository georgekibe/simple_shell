#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>

/**
 * struct list_s - singly linked list of values
 * @name: string
 * @value: string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *name;
	char *value;
	struct list_s *next;
} list_t;

/**
 * struct built_s - Struct built_s
 * @name: built-in command
 * @f: function associated
 *
 * Description: struct representing shell built-in command
 */
typedef struct built_s
{
	char *name;
	int (*f)(list_t *input_list, char *shell_name, list_t **env_list_ptr);
} built_s;

/* main.c */
void sig_handler(int sig);

/* env_list.c */
list_t *create_env(char **env, list_t *env_list);
char *_getenv(list_t *env_list, char *name);
void print_env(list_t *env_list);
int _setenv(list_t *env_list, const char *name, const char *value, int ow);
int _unsetenv(list_t *env_list, const char *name);

