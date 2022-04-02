#ifndef _FIND_SUBSTRING_H_
#define _FIND_SUBSTRING_H_

/* Libraries */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Functions */
int *find_substring(char const *s, char const **words, int nb_words, int *n);
unsigned long hash(const char *s, int end);

#endif /* _FIND_SUBSTRING_H_ */
