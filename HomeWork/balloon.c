
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct DListNode
{
    element data;
    element number;
    struct DListNode* plink;
    struct DListNode* nlink;
}DListNode;

void init(DListNode* phead)
{
    phead->plink = phead;
    phead->nlink = phead;
    phead->number = NULL;
    phead->data = NULL;
}

void dinsert_first(DListNode* head, element data,element number)
{
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->number = number;
    newnode->data = data;
    newnode->nlink = head;
    newnode->plink = head;
    head->nlink = newnode;
    head->plink = newnode;
}

void dinsert(DListNode* before, element data,element number)
{
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->number = number;
    newnode->data = data;
    newnode->plink = before;
    newnode->nlink = before->nlink;
    before->nlink->plink = newnode;
    before->nlink = newnode;
}

int ddelete(DListNode* head, DListNode* removed)
{
    if (head == removed)return;
    removed->plink->nlink = removed->nlink;
    removed->nlink->plink = removed->plink;
    printf("터뜨린 풍선 : %d\n",removed->data);
    int a = removed->number;
    printf("나온 숫자 : %d\n", a);
    free(removed);
    return a;
}

typedef struct countNode
{
    
    struct countNode* cntnlink;
    struct countNode* cntplink;
}countNode;

void init_countNode(DListNode* head, countNode* c)
{
    
    c->cntnlink = head;
    c->cntplink = head;
}

DListNode* left_countNode(countNode* c,DListNode* tmp)
{
    tmp = tmp->plink;
    c->cntnlink = tmp->nlink;
    c->cntplink = tmp->plink;
    
    if (tmp->data == 0)
    {
        tmp = tmp->plink;
        c->cntnlink = tmp->nlink;
        c->cntplink = tmp->plink;
    }
    return tmp;
}
DListNode* right_countNode(countNode* c, DListNode* tmp)
{
    tmp = tmp->nlink;
    c->cntnlink = tmp->nlink;
    c->cntplink = tmp->plink;
   
    if (tmp->data == 0)
    {
        tmp = tmp->nlink;
        c->cntnlink = tmp->nlink;
        c->cntplink = tmp->plink;
    }
    return tmp;
}

int main(void)
{
    srand(time(NULL));
    int input;
    scanf_s("%d", &input);
    int number = rand() % (2 * input + 1) - input;
    DListNode* head =(DListNode*)malloc(sizeof(DListNode));
    countNode* c =(countNode*)malloc(sizeof(countNode));
    DListNode* tmp_next = (DListNode*)malloc(sizeof(DListNode));
    DListNode* tmp = head;
    init(head);
    dinsert_first(head, input, number);

    for (int i = input-1; i > 0; i--)
    {
        number = rand() % (2 * input + 1) - input;
        dinsert(head, i,number);
    }
    init_countNode(head, c);
    tmp=right_countNode(c, tmp);
    tmp_next = tmp->nlink;
    int nodeNum = ddelete(head, tmp);
    tmp = tmp_next;

    while (1)
    {
        if (head == head->nlink)
        {
            break;
        }
        if (nodeNum < 0)
        {
            for (int j = nodeNum; j < 0; j++)
            {
                tmp = left_countNode(c, tmp);
                
            }
            tmp_next = tmp->nlink;
            if (tmp_next == head)
            {
                tmp_next = tmp_next->nlink;
            }
            nodeNum = ddelete(head, tmp);   
            tmp = tmp_next;
        }
        else if (nodeNum >= 0)
        {
            for (int k = 0; k < nodeNum-1; k++)
            {
                tmp = right_countNode(c, tmp);
                
            }
            tmp_next = tmp->nlink;
            if (tmp_next == head)
            {
                tmp_next = tmp_next->nlink;
            }
            nodeNum = ddelete(head, tmp);
            tmp = tmp_next;
        }
    }
    
}

//현재위치노드 tmp를 생성해야함.