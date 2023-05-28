#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_VERTEX 1000


typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTEX][MAX_VERTEX];
	int vdata[MAX_VERTEX];
}GraphType;

void init_Graph(GraphType*g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		g->vdata[i] = 0;
		for (int j = 0; j < MAX_VERTEX; j++)
		{
			g->adj_mat[i][j] = 0;
		}
	}
}

int count = 0;
bool visited[MAX_VERTEX];

void insert_vertex(GraphType* g,int v) {
	if (g->n + 1 > MAX_VERTEX)
	{
		printf("���� ���� ���� �ʰ�.");
		return;
	}
	g->vdata[g->n] = v;
	g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n)
	{
		printf("���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

typedef int element;
typedef struct
{
	int front;
	int rear;
	element bfs_queue[MAX_VERTEX];
}Queue;

void init_queue(Queue* q)
{
	q->front = -1;
	q->rear = -1;
}
int full(Queue* q)
{
	if (q->rear == MAX_VERTEX - 1)
	{
		return 1;
	}
	else
		return 0;
}
int empty(Queue* q)
{
	if (q->front == q->rear)
	{
		return 1;
	}
	else
		return 0;
}
void enqueue(Queue* q, element card)
{
	if (full(q))
	{
		printf("ť�� ��ȭ�����Դϴ�.");
	}
	else
	{
		q->bfs_queue[++(q->rear)] = card;
	}
}
int dequeue(Queue* q)
{
	if (empty(q))
	{
		printf("ť�� ������ϴ�.");
		return 0;
	}
	else
	{
		int item = q->bfs_queue[++(q->front)];
		return item;
	}
}

int bfs_mat(GraphType* g, int v, int input) { //input�� ������ ������ �Է¹��� ���� ���� (for���� ���������� ������ ���ؼ�)
	int w;
	Queue q;
	count++;
	init_queue(&q);
	visited[v] = true;
	enqueue(&q, v);
	while (!empty(&q))
	{
		v = dequeue(&q);
		for (w = 0; w < g->n; w++)
		{
			if (g->adj_mat[v][w] && !visited[w])
			{
				visited[w] = true;
				enqueue(&q, w);
			}
		}
	}
	for (int i = 0; i < input; i++)
	{
		if (!visited[i])
		{
			bfs_mat(g, i,input);
		}
	}
	return count;
}

int main(void) {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init_Graph(g);
	int n,edge;  //������ ����, ������ ����
	int start, end; //�������� ������
	scanf_s("%d %d", &n,&edge);
	for (int i = 0; i < n; i++)
	{
		insert_vertex(g, i);
	}
	for (int j = 0; j < edge; j++)
	{
		scanf_s("%d %d", &start, &end);
		insert_edge(g, start-1, end-1);
	}

	printf("%d", bfs_mat(g, 0, n));
	
	free(g);
	return 0;
}