#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"
#include "cat.h"

array_list *read_lines(char *filename) {
	assert(filename && "filename is NULL");

	size_t lines_max = 16;
	size_t lines_count = 0;
	char **lines = malloc(lines_max * sizeof(*lines));
	assert(lines && "lines malloc failed");

	FILE *fp = fopen(filename, "r");
	assert(fp && "file couldn't be opened");

	char *line = NULL;
	while(1) {
		line = get_valid_line(fp);
		if(feof(fp)) {
			free(line);
			break;
		}
		lines = add_line_to_lines(lines, line, &lines_count, &lines_max);
	}

	array_list *linesArray = malloc(sizeof(*linesArray));
	assert(linesArray && "linesArray malloc failed");
	linesArray->data = lines;
	linesArray->n_entries = lines_count;
	return linesArray;
}

char **add_line_to_lines(
	char **lines,
	char *line,
	size_t *lines_count,
	size_t *lines_max
) {
	if (*lines_count == *lines_max) {
		*lines_max *= 2;
		lines = realloc(lines, (*lines_max) * sizeof(*lines));
		assert(lines && "lines realloc failed");
	}
	lines[*lines_count] = line;
	(*lines_count)++;

	return lines;
}

char *get_valid_line(FILE *fp) {
	assert(fp && "fp is NULL");

	char *line = malloc(BUFFER_SIZE * sizeof(*line));
	assert(line && "first line malloc failed");
	line[0] = '\0';
	size_t char_index = 0;

	char c = '\0';
	while(1) {
		c = fgetc(fp);
		if(feof(fp) || (c == '\n')) {
			line[char_index] = '\0';
			break;
		}
		if(char_index == BUFFER_SIZE - 1) {
			line[0] = '\0';
			char_index = 0;
			skip_characters_till_newline(fp);
			continue;
		}
		line[char_index] = c;
		char_index++;
	}

	return line;
}

void skip_characters_till_newline(FILE *fp) {
	assert(fp && "fp is NULL");

	char c = '\0';
	while(1) {
		c = fgetc(fp);
		if(feof(fp) || c == '\n') {
			break;
		}
	}
}
