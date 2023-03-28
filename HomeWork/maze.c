/*
#include <stdio.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct
{
	int loc_x[MAX_STACK_SIZE];
	int loc_y[MAX_STACK_SIZE];
	int top_x;
	int top_y;
}StackType;

typedef struct
{
	int r;
	int c;
}coordinate;

coordinate here;

void init_stack(StackType* s)
{
	s->top_x = -1;
	s->top_y = -1;
}

int full(StackType* s)
{
	return (s->top_x == MAX_STACK_SIZE - 1&&s->top_y==MAX_STACK_SIZE);
}

int empty(StackType* s)
{
	return (s->top_x == -1&&s->top_y==-1);
}

void push(StackType* s, coordinate a)
{
	if (full(s))
	{
		printf("������ �� á���ϴ�.");
	}
	else
	{
		
		s->loc_x[++(s->top_x)] = a.r;
		s->loc_y[++(s->top_y)] = a.c;
	}
}



char maze[6][6] = {
	{ '1', '1', '0', '1', '0', '0' },
	{ '0', '1', '0', '1', '0', '0' },
	{ '0', '1', '1', '1', '1', '0' },
	{ '0', '1', '0', '0', '1', '1' },
	{ '0', '1', '0', '0', '1', '0' },
	{ '0', '1', '0', '0', '1', '1' },
};

void push_loc(StackType* s, int r, int c)
{
	if (r < 0 || c < 0||r>=6||c>=6)
	{
		return;
	}
	if (maze[r][c] != '0' && maze[r][c] != '.')
	{
		coordinate tmp = { r,c };
		push(s, tmp);
		
	}
}
coordinate pop(StackType* s)
{
	coordinate b = { 0,0 };
	if (empty(s))
	{
		printf("������ �� ������ϴ�.");
		return;
	}
	else
	{
		b.r = s->loc_x[(s->top_x)--];
		b.c = s->loc_y[(s->top_y)--];
	}
	return b;
}

void maze_print(char maze[6][6])
{
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

int main_maze(void)
{
	int r = 0;
	int c = 0;
	StackType s;
	init_stack(&s);
	maze[r][c] = '.';
	while (!full(&s))
	{
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r, c - 1);
		push_loc(&s, r+1, c);
		push_loc(&s, r, c+1);
		push_loc(&s, r-1, c );

		if (empty(&s))
		{
			printf("Ż��Ұ�");
		}
		else
		{
			here = pop(&s);
		}
		if (here.r==6&&here.c==6)
		{
			printf("����");
			break;
		}
	}
	return 0;
}







	2���� �迭�� �̷� 1�� ����
	int 2���� ���� ��ġ ����
	�㰡 ������ �� �ִ� ��ġ�� ���� 2���� ������ ����
	�������� (1,1) ��������  (N,M)���� ����(N,M�� ��İ���-1)
	���� �㸦 �������� �����¿� �˻��� �ؼ� ���� 1�̸� push, '.'�Ǵ� 0�̸� �׳� �Ѿ.
	0��'.'�� ��,�׸��� ������ �ڸ��� �ǹ���.
	push�� ������ �̵��� �ؾ��ϴµ� �̵��� pop�� ����ؼ� �ش���ǥ�� �̵��ϴ°ɷ� ����(push�� �������̹Ƿ� pop�� push�� ����)
	���� �����⿡�� 1�� ���ٸ�, pop�� �ѹ� �� �����.
	�ϴ��� �������
*/