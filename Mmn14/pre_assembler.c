#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "pre_assembler.h"
#include "assembler.h"
#include "utils.h"
#include <string.h>


static void add_mcro_to_table(char* mcro_name, char* mcro_value, mcros_table_entry* first_mcro) {
	mcros_table_entry* current_mcro_entry = first_mcro;
	mcros_table_entry* new_mcro_entry = NULL;
	int total_length; 
	char* new_value;

	/* If the mcros table is empty, add first mcro */
	if (current_mcro_entry->name == NULL) {
		current_mcro_entry->name = mcro_name;
		current_mcro_entry->name = mcro_value;
		return;
	}

	/* Iterate through the table as long as mcros has a value */
	while (current_mcro_entry->name != NULL) {

		/* If mcros name was found in the table, append the line to its current value */
		if (strcmp(current_mcro_entry->name, mcro_name) == 0) {
			total_length = strlen(current_mcro_entry->value) + strlen(mcro_value);
			new_value = malloc_with_check(total_length + 1);
			strcpy(new_value, current_mcro_entry->value);
			strcat(new_value, mcro_value);
			new_value[total_length] = '\0';
			free(new_value);
			return;
		}
		
		/* Advance the pointer to the next entry */
		current_mcro_entry = current_mcro_entry->next;
	}

	/* If mcros name was not found in the table, add its name and value to the table */
	new_mcro_entry->name = mcro_name;
	new_mcro_entry->value = mcro_value;
	current_mcro_entry->next = new_mcro_entry;

}


static boolean mcro_in_table(mcros_table_entry* first_mcros_table_entry, char* first_word, char* file_name, FILE* template_file) {
	mcros_table_entry* mcros_table_entry = first_mcros_table_entry;

	/* If the mcros table is empty, return FALSE */
	if (mcros_table_entry->name == NULL) {
		return FALSE;
	}
	
	/* Loops through the table to check if the first word is a defined macro in the table */

	while (mcros_table_entry->value != NULL) {
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
	char* mcro_name = NULL;

	/* Read file line by line until the end */
	while (fgets(line, sizeof(line), source_file) != NULL) {
		char* first_word = strtok(line, " \t");

		/* If first word is a defined mcro in the table, write its value to the template file and continue */
		if (mcro_in_table(&first_mcro, first_word, file_name, template_file)) {
			continue;
		}


		/* If it is the start of a mcro definition, add its name to the table */
		if (strcmp(first_word, "mcro") == 0) {
			mcro_exists = TRUE;
			mcro_name = strtok(NULL, " \t");
			fprintf(template_file, "%s", line);

			do {
				fgets(line, sizeof(line), source_file);
				char* first_word = strtok(line, " \t");
				add_mcro_to_table(mcro_name, line, &first_mcro);
			} while (strcmp(first_word, "endmcro\n") != 0);

		}



		/* If the line is not a mcro definition, write it to the template file */
		fprintf(template_file, "%s", line);

	}

	/* Close the file */
	fclose(source_file);  // Close the file
}