/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX 100
//���� ����Ʈ�� �̿��Ѵ�. �׸��� DFS�� ����غ�.
//DFS���� �Լ��� ȣ�� �� ������ �׻� 1�� ī��Ʈ���ش�. (ó�� �Ҷ��� �ϸ�ȵ�)

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* adj_Head[MAX_VERTEX];
}GraphType;

bool visited[MAX_VERTEX];
int count = 0;

void init(GraphType* g) {
    g->n = 0;
    for (int i = 0; i < MAX_VERTEX; i++)
    {
        g->adj_Head[i] = NULL;
    }
}

void insert_vertex(GraphType* g, int vertex) {
    if (g->n + 1 > MAX_VERTEX)
    {
        printf("���� ���� �߰� �ѵ� �ʰ�");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n)
    {
        printf("���Կ���");
        return;
    }
    GraphNode* node;
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = end;
    node->link = g->adj_Head[start];
    g->adj_Head[start] = node;  
}

//DFS
int dfs_list(GraphType* g, int v) {
    
    GraphNode* w;
    visited[v] = true;
    count++;
    for (w = g->adj_Head[v]; w; w = w->link)
    {
        if (!visited[w->vertex])
        {
            dfs_list(g, w->vertex);
        }
    }
    return count-1;
}
int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    int computer;
    scanf_s("%d", &computer);
    for (int i = 0; i < computer; i++)
    {
        insert_vertex(g, computer);
    }
    int pair;
    int start, end;
    scanf_s("%d", &pair);
    for (int j = 0; j < pair; j++)
    {
        scanf_s("%d %d", &start, &end);
        insert_edge(g, start-1, end-1);             //������ �׷����̹Ƿ� �ݵ�� ���۰� ��, ���� ���ۿ� ���� ������ �������.
        insert_edge(g, end - 1, start - 1);
    }
    printf("%d",dfs_list(g, 0));
    
    free(g);
}
*/