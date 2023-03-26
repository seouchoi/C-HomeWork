/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100 

typedef struct
{
	char a[MAX_STACK_SIZE];
	
	int top;
}StackType;

void deftop(StackType *s) 
{
	s->top = -1;  
}
int is_empty(StackType* s) 
{
	return (s->top == -1); // 비어있으면 1, 아니면 0
}
int is_full(StackType* s)
{
	return(s->top ==(MAX_STACK_SIZE-1)); // 가득차있으면 1, 아니면 0
}
void push(StackType* s, char next_ch)
{
	if (is_full(s)) // 값이 1이면 탈출
	{
		return;
	}
	else
	{
		s->a[++(s->top)] = next_ch; //값이 0이면 탑에다가 기호넣기
	}
}

char pop(StackType* s)
{
	if (is_empty(s)) //값이 1이면 탈출
	{
		return 0;
	}
	else
	{
		return s->a[(s->top)--]; //값이 0이면 탑에있는 기호를 빼내서 리턴함
	}
}

int check(char *arr)
{
	StackType s;
	
	char next_ch, open_ch;
	int i;
	int n = strlen(arr);
	deftop(&s);

	for (i = 0; i < n; i++)
	{
		next_ch = arr[i]; //문자열에서 문자를 하나하나 next_ch에 대입
	
		switch (next_ch)  //괄호인지아닌지 검사함
		{
		
		case '(': case'[':
			push(&s, next_ch); //괄호라면 push에다가 집어넣음
			break;

		case ')': case']': //닫는 괄호라면 스택안에 있는 괄호랑 종류가 맞는지 비교함
			if (is_empty(&s)) 
			{
				return 0;
			}
			else
			{
				open_ch = pop(&s);
				if ((open_ch == '(' && next_ch != ')') || (open_ch == '[' && next_ch != ']'))
				{
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) //비어있지않으면 0을 리턴함
	{
		return 0;
	}
	return 1; //모든 조건이 만족하면 1을 리턴함.
	
}

int main_learning(void)
{	
	char a[MAX_STACK_SIZE];
	printf("아무 문장이나 입력하세요 : ");
	while (1)
	{
		fgets(a, MAX_STACK_SIZE, stdin);
		if (strcmp(a, ".\n") == 0)
		{
			break;
		}
		if (check(a) == 1)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}

*/