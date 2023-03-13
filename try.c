//#include <stdio.h>
//int strindex(char s[], char t[])
///* Find right most occurrence of string t in string s */
//{
//	int return_val = -1;
//	int s_ndx, t_ndx, tmp_s;
//	for (s_ndx = 0; s[s_ndx] != '\0'; s_ndx++)
//	{
//		for (t_ndx = 0, tmp_s = s_ndx; t[t_ndx] == s[tmp_s]
//			&& t[t_ndx] != '\0'; t_ndx++, tmp_s++)
//			;
//		if (t[t_ndx] == '\0')
//			return_val = s_ndx;
//	}
//	return (return_val);
//}
//main12()
//{
//	char search_st[] = "hello bye bye hello";
//	char search_for[] = "hello";
//	printf("right most occurance of");
//	printf(" \"%s\" in \"%s\" is at index %d\n",
//		search_for,
//		search_st,
//		strindex(search_st, search_for));
//}