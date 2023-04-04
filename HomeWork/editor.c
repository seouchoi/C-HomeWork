#include <stdio.h>
#include <string.h>
#define MAX_LIST_SIZE 200

typedef char element;

typedef struct
{
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

void init(ArrayListType* L)
{
	L->size = 0;
}

int full(ArrayListType* L)
{
	return (L->size == MAX_LIST_SIZE);
}

int empty(ArrayListType* L)
{
	return (L->size == 0);
}

void insert(ArrayListType* L, int pos, element item)
{
	if (!full(L) && (pos >= 0) && (pos <= L->size))
	{
		for (int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

element delet(ArrayListType* L, int pos)
{
	element item;

	if (pos < 0 || pos >= L->size)
	{
		printf("위치오류");
	}
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
	{
		L->array[i] = L->array[i + 1];
	}
	L->size--;
	return item;
}

void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
	{
		printf("%c", L->array[i]);
	}
	printf("\n");
}

//커서 함수
typedef struct
{
	int cuspos;
}Cursor;
void init_cursor(ArrayListType* L, Cursor* C)
{
	C->cuspos = L->size - 1;
}
int left_cursor(Cursor* C)
{
	if (C->cuspos == -1)
	{
		return 0;
	}
	else
	{
		C->cuspos = C->cuspos - 1;
	}
	return C->cuspos;
}
int right_cursor(Cursor* C, ArrayListType* L)
{
	if (C->cuspos >= L->size - 1)
	{
		return 0;
	}
	else
	{
		C->cuspos = C->cuspos + 1;
	}
	return C->cuspos;
}
void delet_cursor(Cursor* C, ArrayListType* L)
{
	if (C->cuspos == -1)
	{
		return;
	}
	else
	{
		delet(L, C->cuspos);
		C->cuspos--;
	}
}
void insert_cursor(Cursor* C, ArrayListType* L, element item)
{
	insert(L, C->cuspos + 1, item);
	C->cuspos = C->cuspos + 1;
}

int main(void)
{
	ArrayListType L;
	Cursor C;

	init(&L);
	int count = 0;
	char a[MAX_LIST_SIZE];
	scanf_s("%s", a,MAX_LIST_SIZE);
	char b;
	char item;
	int order;
	for (int i = 0; i < strlen(a); i++)
	{
		insert(&L, i, a[i]);
	}
	init_cursor(&L, &C);
	scanf_s("%d", &order);
	while (count < order) {
		scanf_s(" %c", &b);
		switch (b)
		{
		case'L':left_cursor(&C);
			break;
		case'D':right_cursor(&C, &L);
			break;
		case'B':delet_cursor(&C, &L);
			break;
		case'P':
			getchar();
			scanf_s("%c", &item);
			insert_cursor(&C, &L, item);
			break;
		}
		count++;
	}
	
	print_list(&L);
}