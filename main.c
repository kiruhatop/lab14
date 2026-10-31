/*
Жигунов Кирилл Андреевич
ПИ 1-1
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
	if (strlen(text)>30)
	{
	    puts("Too long"); return 1;
	}
	printf("Text: [%s]\n", text);
	printf("Bytes: %zu\n", strlen(text));
	return 0;
}

