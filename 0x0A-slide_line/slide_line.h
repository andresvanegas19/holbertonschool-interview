#ifndef _SLIDE_LINE_H_
#define _SLIDE_LINE_H_

/* Delcare libraries */
#include <stdlib.h>

/* Delcare the macros */
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0

/* Delcare functions */
int slide_line(int *line, size_t size, int direction);

#endif /* _SLIDE_LINE_H_ */
