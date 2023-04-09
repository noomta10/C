#define INT_SIZE sizeof(int)
#define ENLARGE_SIZE(size) ++size
#define INT_FOUND 1
#define MEMORY_ERROR 1
#define TRUE 1 
#define FALSE 0
#define INITIAL_ARRAY_SIZE 0


struct dynamic_array get_set();
void add_number_to_array(struct dynamic_array* my_array, int number);
int number_in_array(struct dynamic_array my_array, int number);
void print_set(struct dynamic_array set);
void print_full_array(struct dynamic_array full_array);