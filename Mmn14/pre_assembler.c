#include <stdio.h>
#include "pre_assembler.h"
#include "assembler.h"
#include "utils.h"

void pre_assembler(FILE* source_file) {
	char line[MAX_LINE_LENGTH];

	/* Read file line by line until the end */
	while (fgets(line, sizeof(line), source_file) != NULL) {
		printf("%s\n", get_next_element(line));  // Do something with the line (printing in this case)
	}

	fclose(source_file);  // Close the file
}



static void add_mcro_to_table(char* mcro_name, char* mcro_value, mcros_table_entry* mcros_table_entry)
{
	return;
}
