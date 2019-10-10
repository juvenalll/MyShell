#ifndef HELP_H
#define HELP_H
//Any function created to merely simplify the operation of the program goes here
void getCLargs();

int special_characters(char input[]);
int predefined(char input[]);
void run_builtin(char *input);
void tokenize(char * line, char **words);
int pipe_check(char input[]);
#endif