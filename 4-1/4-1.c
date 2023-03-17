#include <stdio.h>

int strindex(char s[], char t[]);

main() {
	char s[] = "bye hello bye";
	char t[] = "bye";

	printf("Right most occurance of: %s\nIn string: %s\nIs: %d\n", t, s, strindex(s, t));

}

int strindex(char s[], char t[]) {
	int s_index, t_index, tmp_s;
	int return_value;
	return_value = -1;

	for (s_index = 0; s[s_index] != '\0'; s_index++) {
		for (t_index = 0, tmp_s = s_index; t[t_index] == s[tmp_s] && t[t_index] != '\0'; t_index++, tmp_s++)
			;

		if (t[t_index] == '\0')
			return_value = s_index;
	}

	return return_value;
}