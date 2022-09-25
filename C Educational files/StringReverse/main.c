#include <stdio.h>
#include <string.h>

int main()
{
  	char Str[100];
  	int i, len;

  	printf("\n Please Enter any String :  ");
  	gets(Str);

  	len = strlen(Str);

 	printf("\n String after Reversing : ");
  	for (i = len - 1; i >= 0; i--)
  	{
  		printf("%c", Str[i]);
  	}

  	return 0;
}
