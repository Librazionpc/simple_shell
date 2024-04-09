#ifndef MAIN
#define MAIN
int _putchar(char c);
char *create_array(unsigned int size, char c);
char *_strdup(char *s);
char *str_concat(char *s1, char *s2);
int **alloc_grid(int width, int hieght);
void free_grid(int **grid, int height);
char *argstostr(int ac, char **av);
#endif
