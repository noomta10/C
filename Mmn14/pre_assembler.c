#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pre_assembler.h"
#include "assembler.h"
#include "utils.h"


static void add_mcro_to_table(char* mcro_name, char* mcro_value, mcros_table_entry** first_mcro_entry) {
	mcros_table_entry* new_mcro_entry = malloc_with_check(sizeof(mcros_table_entry));
	int total_length;

	/* If table is empty, add first mcro */
	if (*first_mcro_entry == NULL) {
		new_mcro_entry->name = malloc_with_check(strlen(mcro_name) + 1);
		new_mcro_entry->value = malloc_with_check(strlen(mcro_value) + 1);
		new_mcro_entry->next = NULL;
		strcpy(new_mcro_entry->name, mcro_name);
		strcpy(new_mcro_entry->value, mcro_value);
		*first_mcro_entry = new_mcro_entry;
		return;
	}

	mcros_table_entry* current_mcro_entry = *first_mcro_entry;

	/* If mcro already exists in the table, append value to mcro */
	while (current_mcro_entry != NULL) {
		if (strcmp(current_mcro_entry->name, mcro_name) == 0) {
			total_length = strlen(current_mcro_entry->value) + strlen(mcro_value);
			current_mcro_entry->value = realloc_with_check(current_mcro_entry->value, (total_length + 1));
			strcpy(current_mcro_entry->value, current_mcro_entry->value);
			strcat(current_mcro_entry->value, mcro_value);
			current_mcro_entry->value[total_length] = '\0';
			printf("DDD: %s\n", current_mcro_entry->value);
			return;
		}

		current_mcro_entry = current_mcro_entry->next;
	}



}


static boolean mcro_in_table(mcros_table_entry** first_mcro_entry, char* first_word, char* file_name, FILE* template_file) {
	mcros_table_entry* current_mcro_entry = *first_mcro_entry;

	/* If the mcros table is empty, return FALSE */
	if (first_mcro_entry == NULL) {
		return FALSE;
	}
	
	/* Loops through the table to check if the first word is a defined macro in the table */
	while (current_mcro_entry) {
		/* If the first word is a defined macro in the table, write its value to the template file, and return TRUE */
		if (strcmp(first_word, current_mcro_entry->name) == 0) {
			fprintf(template_file, "%s", current_mcro_entry->value);
			return TRUE;
		}

		current_mcro_entry = current_mcro_entry->next;
	}

	return FALSE;
}


void pre_assembler(FILE* source_file, char file_name) {
	char line[MAX_LINE_LENGTH];
	mcros_table_entry* first_mcro_entry = NULL;
	FILE* template_file = fopen("template_file.txt", "a");
	boolean mcro_exists = FALSE;
	char* mcro_name = NULL;

	/* Read file line by line until the end */
	while (fgets(line, sizeof(line), source_file) != NULL) {
		char* first_word = strtok(line, " \t\n");

		/* If first word is a defined mcro in the table, write its value to the template file and continue */
		if (mcro_in_table(&first_mcro_entry, first_word, file_name, template_file)){
			continue;
	    }

		/* Start of a mcro definition */
		if (strcmp(first_word, "mcro") == 0) {
			mcro_exists = TRUE;
			mcro_name = strtok(NULL, " \t\n");

			/* Allocate memory for the mcro name, and copy it */
			char* saved_mcro_name = malloc_with_check(strlen(mcro_name) + 1);
			strcpy(saved_mcro_name, mcro_name); 

			/* Mcros definition, adds its value to the table */
			while(1) {
				fgets(line, sizeof(line), source_file);

				/* Allocate memory for the line, and copy it */
				char* saved_line = malloc_with_check(sizeof(line));
				strcpy(saved_line, line);
				first_word = strtok(line, " \t\n");

				/* Stop if "endmcro" encountered */
				if (strcmp(first_word, "endmcro") == 0) {
					break;
				}

				add_mcro_to_table(saved_mcro_name, saved_line, &first_mcro_entry);
			}

			continue;
		}

		/* If the line is not a mcro definition, write it to the template file */
		fprintf(template_file, "%s", line);
	}

	/* Close the files */
	fclose(source_file);  
	fclose(template_file);

}