/*
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct
{
	element data;
	element count;
	struct ListNode *link;
}ListNode;

ListNode* head = NULL;

ListNode* insert_last(ListNode* head, element data,element count)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	node->count = count;
	if (head == NULL)
	{
		head = node;
		node->link = head;	
	}

	else
	{
		node->link = head->link;
		head->link = node;
		
	}
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	else
	{
		removed = pre->link;
		pre->link = removed->link;
		printf("%d, ", removed->data);
		free(removed);
	}
	return head;
}


int main(void)
{
	int people;
	int period;
	scanf_s("%d", &people);
	scanf_s("%d", &period);
	printf("<");
	for (int i = people; i > 0; i--)
	{
		head=insert_last(head, i,0);
	}
	ListNode* visit = head->link;
	ListNode* preVisit = visit;
	while (1)
	{	
		visit->count++;
		if (visit->count % period == period-1) {
			preVisit = visit;
			delete(head, visit);
			if (visit->link == visit)
			{
				printf("%d", visit->data);
				
				break;
			}
			visit->count = preVisit->count;
		}
		
		else
		{
			preVisit = visit;
			visit = visit->link;	
			visit->count = preVisit->count;
		}
		
	}
	printf(">");
}
*/

