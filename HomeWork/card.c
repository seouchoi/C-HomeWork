/*
#include <stdio.h>
#include<stdlib.h>
#define MAX_CARD_SIZE 10000


typedef int element;
typedef struct 
{
	int front;
	int rear;
	element cardTop[MAX_CARD_SIZE];
}Queue;

void init(Queue* q)
{
	q->front = -1;
	q->rear = -1;
}
int full(Queue* q)
{
	if (q->rear == MAX_CARD_SIZE - 1)
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
		printf("큐가 포화상태입니다.");
	}
	else
	{
		q->cardTop[++(q->rear)] = card;
	}
}
int dequeue(Queue* q)
{
	if (empty(q))
	{
		printf("큐가 비었습니다.");
		return 0;
	}
	else
	{
		int item = q->cardTop[++(q->front)];
		return item;
	}
}
int peek(Queue* q)
{
	if (empty(q))
	{
		printf("큐가 비었습니다. peek불가능.");
		return 0;
	}
	else
	{
		int peeker = q->cardTop[q->front + 1];
		return peeker;
	}
}

int main(void)
{
	Queue q;
	init(&q);
	int a;
	scanf_s("%d", &a);

	int count = 1;

	for (int i = 1; i < a + 1; i++)
	{
		enqueue(&q, i);
	}
	for (int j = 0; j < MAX_CARD_SIZE; j++)
	{
		if (count % 2 == 0)
		{
			enqueue(&q, peek(&q));
		}
		dequeue(&q);
		if (q.front == q.rear)
		{
			break;
		}
		count += 1;
	}
	printf("%d", q.cardTop[q.rear]);
	return 0;
}
*/