#include <stdio.h>

int strindex(char s[], char t[]);

main11() {
	char s[] = "bye hello";
	char t[] = "hello";

	printf("Right most occurance of: %s\nIn string: %s\nIs: %d\n", t, s, strindex(s,t));
	
}

int strindex(char s[], char t[]) {
	int s_index, t_index, k;

	for (s_index = 0; s[s_index] != '\0'; s_index++) {
		for (t_index = 0, k = s_index; t[t_index] == s[k] && t[t_index] != '\0'; t_index++, k++)
			;
		if (t[t_index] == '\0')
			return s_index;
		return -11;

	}
}