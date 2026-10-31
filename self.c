/* 
Дектярев Михаил Павлович
П.И. 1-1
Строки и безопасный ввод
*/
#include <stdio.h>
#include <string.h>

int main(void) {
	char text[32];
	if (fgets(text, sizeof text, stdin) == NULL)
	{
	    puts("Input error"); return 1;
	}
	size_t pos = strspn(text, "\n");
	if (text[pos] == '\n') text[pos] = '\0';
	size_t len = strlen(text);
	if (len>30)
	{
	    puts("Too long"); return 1;
	}
	int digits = count_dig(text, len);
	int spaces = count_space(text, len);
	
	printf("Text: [%s]\n", text);
	printf("Bytes: %zu\n", strlen(text));
	printf("Digits: %d\n", digits);
	printf("Spaces: %d\n", spaces);
	return 0;
}

int count_dig(const char *str, size_t len) 
{
    int count = 0;
    for (size_t i = 0; i < len; ++i) 
    {
        if (str[i] >= '0' && str[i] <= '9') count++; 
    }
    return count; 
}

int count_space(const char *str, size_t len)
{
     int spaces = 0;
    for (size_t i = 0; i < len; ++i) {
        if (str[i] == ' ') 
        {
            spaces++;
        }
    }
    return spaces;
}
