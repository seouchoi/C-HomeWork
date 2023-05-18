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
		printf("������ �� á���ϴ�.");
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
		printf("������ ������ϴ�.");
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
	printf("���� ���� �Է� : ");
	scanf_s("%d", &j);
	printf("���ڿ� �Է� : ");
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