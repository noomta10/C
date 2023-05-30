#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "pre_assembler.h"
#include "assembler.h"
#include "utils.h"
#include <string.h>


static void add_mcro_to_table(char* mcro_name, char* mcro_value, mcros_table_entry* first_mcro) {
	/* If the mcros table is empty */
	if (first_mcro->name == NULL) {
		first_mcro->name = mcro_name;
		return;
	}

}


static boolean mcro_in_table(mcros_table_entry* first_mcros_table_entry, char* first_word, char* file_name, FILE* template_file) {
	mcros_table_entry* mcros_table_entry = first_mcros_table_entry;

	/* If the mcros table is empty, return FALSE */
	if (mcros_table_entry->name == NULL) {
		return FALSE;
	}
	
	/* Loops through the table to check if the first word is a defined macro in the table */
	while (mcros_table_entry->name != NULL) {
		/* If the first word is a defined macro in the table, write its value to the template file, and return TRUE*/
		if (strcmp(first_word, mcros_table_entry->name) == 0) {
			fprintf(template_file, "%s", mcros_table_entry->value);
			return TRUE;
		}

		mcros_table_entry = mcros_table_entry->next;
	}

	return FALSE;
}


void pre_assembler(FILE* source_file, char file_name) {
	char line[MAX_LINE_LENGTH];
	mcros_table_entry first_mcro = { NULL, NULL, NULL };
	FILE* template_file = fopen("template_file.txt", "a");
	boolean mcro_exists = FALSE;
	char* mcro_name;

	/* Read file line by line until the end */
	while (fgets(line, sizeof(line), source_file) != NULL) {
		char* first_word = strtok(line, " \t");

		/* If first word is a defined mcro in the table, write its value to the template file and continue */
		if (mcro_in_table(&first_mcro, first_word, file_name, template_file)) {
			continue;
		}

		/* If it is the start of a mcro definition */
		if (strcmp(first_word, "mcro") == 0) {
			mcro_exists = TRUE;
			mcro_name = strtok(NULL, " \t");
			add_mcro_to_table(mcro_name, NULL, &first_mcro);
			continue;
		}

		/* If it is a simple line that is not related to mcros, write it to the template file */
		fprintf(template_file, "%s", line);


	}

	/* Close the file */
	fclose(source_file);  // Close the file
}