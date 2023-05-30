#include <stdio.h>
#include "pre_assembler.h"
#include "assembler.h"
#include "utils.h"
#include <string.h>

void pre_assembler(FILE* source_file) {
	char line[MAX_LINE_LENGTH];
	mcros_table_entry first_mcro = {NULL, NULL, NULL};

	/* Read file line by line until the end */
	while (fgets(line, sizeof(line), source_file) != NULL) {
		char* first_word = get_next_element(line);
		if (strcmp(first_word, "mcro")) {

		}
	}

	/* Close the file */
	fclose(source_file);  // Close the file
}



static void add_mcro_to_table(char* mcro_name, char* mcro_value, mcros_table_entry* first_mcro)
{
	return;
}


static boolean mcro_in_table(mcros_table_entry* mcros_table_entry) {

}