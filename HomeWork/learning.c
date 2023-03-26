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
	return (s->top == -1); // ��������� 1, �ƴϸ� 0
}
int is_full(StackType* s)
{
	return(s->top ==(MAX_STACK_SIZE-1)); // ������������ 1, �ƴϸ� 0
}
void push(StackType* s, char next_ch)
{
	if (is_full(s)) // ���� 1�̸� Ż��
	{
		return;
	}
	else
	{
		s->a[++(s->top)] = next_ch; //���� 0�̸� ž���ٰ� ��ȣ�ֱ�
	}
}

char pop(StackType* s)
{
	if (is_empty(s)) //���� 1�̸� Ż��
	{
		return 0;
	}
	else
	{
		return s->a[(s->top)--]; //���� 0�̸� ž���ִ� ��ȣ�� ������ ������
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
		next_ch = arr[i]; //���ڿ����� ���ڸ� �ϳ��ϳ� next_ch�� ����
	
		switch (next_ch)  //��ȣ�����ƴ��� �˻���
		{
		
		case '(': case'[':
			push(&s, next_ch); //��ȣ��� push���ٰ� �������
			break;

		case ')': case']': //�ݴ� ��ȣ��� ���þȿ� �ִ� ��ȣ�� ������ �´��� ����
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
	if (!is_empty(&s)) //������������� 0�� ������
	{
		return 0;
	}
	return 1; //��� ������ �����ϸ� 1�� ������.
	
}

int main_learning(void)
{	
	char a[MAX_STACK_SIZE];
	printf("�ƹ� �����̳� �Է��ϼ��� : ");
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