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
		printf("스택이 꽉 찼습니다.");
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
		printf("스택이 텅 비었습니다.");
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
			printf("탈출불가");
		}
		else
		{
			here = pop(&s);
		}
		if (here.r==6&&here.c==6)
		{
			printf("성공");
			break;
		}
	}
	return 0;
}







	2차원 배열로 미로 1개 생성
	int 2개로 쥐의 위치 생성
	쥐가 움직일 수 있는 위치를 담은 2차원 스택을 생성
	시작점을 (1,1) 도착점을  (N,M)으로 설정(N,M은 행렬갯수-1)
	현재 쥐를 기준으로 상하좌우 검색을 해서 만약 1이면 push, '.'또는 0이면 그냥 넘어감.
	0과'.'은 벽,그리고 지나간 자리를 의미함.
	push가 끝나면 이동을 해야하는데 이동은 pop을 사용해서 해당좌표로 이동하는걸로 결정(push가 무작위이므로 pop도 push를 따라감)
	만약 모든방향에서 1이 없다면, pop을 한번 더 사용함.
	일단은 여기까지
*/