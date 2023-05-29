typedef struct mcros_table_entry {
	struct mcros_table_entry* next;
	char* name;
	char* value;
} mcros_table_entry;

void pre_assembler(FILE* source_file);
static void add_mcro_to_table(char* mcro_name, char* mcro_value, mcros_table_entry* mcros_table_entry);