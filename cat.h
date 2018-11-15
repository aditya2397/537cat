#ifndef CAT_H
#define CAT_H

#include <stddef.h>
#include <stdbool.h>

#include "array_list.h"

#define BUFFER_SIZE 80

array_list *read_lines(char *filename);
char **add_line_to_lines(
	char **lines,
	char *line,
       	size_t *lines_count,
       	size_t *lines_max
);
char *get_valid_line(FILE *fp);
void skip_characters_till_newline(FILE *fp);
bool is_valid_line(char *line);

#endif
