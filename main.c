#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "array_list.h"
#include "cat.h"

int main(int argc, char *argv[]) {
	assert(argc == 2 && "Needs file argument");

	array_list *lines = read_lines(argv[1]);
	printf("Number of lines: %ld\n", lines->n_entries);

	// OPTIONAL START
	// Since we're exiting immediately after using "lines", this is optional.
	// If we weren't going to immediately exit, this memory should be freed.
	size_t i = 0;
	for (; i < lines->n_entries; i++) {
		free(((char **)lines->data)[i]);
	}
	free(lines->data);
	free(lines);
	// OPTIONAL END

	return 0;
}

