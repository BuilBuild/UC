#include<stdio.h>

/*
char * strcpy(char * dst, const char * src);
*/
char* t_strcpy(char *dest, const char *src)
{
//	printf("size dest: %lu\n", sizeof(*dest)/sizeof(char));
	int i;
	for(i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

int main(void)
{

	char buff[32];
	char *msg = "hello beijing";
	t_strcpy(buff, msg);
	printf("buff: %s\n", buff);		
	return 0;
}
