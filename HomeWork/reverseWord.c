/*
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 25

char arr[MAX_STACK_SIZE][MAX_STACK_SIZE];
int top = -1;

int full()
{
	return (top == MAX_STACK_SIZE - 1);
}
int empty()
{
	return(top == -1);
}
void push(char *token)
{
	if (full())
	{
		printf("스택이 꽉 찼습니다.");
	}
	else 
	{
		strcpy(arr[++(top)], token);
	}
}
char* pop()
{
	if (empty())
	{
		printf("스택이 비었습니다.");
		return 0;
	}
	else
	{
		return arr[(top)--];
	}
}


int main_reverse(void)
{
	char str[MAX_STACK_SIZE];
	char* token;
	int i;
	int j;
	printf("문장 갯수 입력 : ");
	scanf_s("%d", &j);
	printf("문자열 입력 : ");
	getchar();

	for (i = 0; i < j; i++)
	{
		fgets(str, MAX_STACK_SIZE, stdin);
			if (str[strlen(str) - 1] == '\n')
			{
				str[strlen(str) - 1] = '\0';
			}
		token = strtok(str, " ");
		while (token != NULL)
		{
			push(token);
			token = strtok(NULL, " ");
		}
		printf("Case #%d: ", i + 1);
		while (!empty())
		{
			printf("%s ",pop());
		}
		printf("\n");
	}
}
*/