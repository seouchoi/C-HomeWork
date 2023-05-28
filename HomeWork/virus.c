/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX 100
//인접 리스트를 이용한다. 그리고 DFS를 사용해봄.
//DFS에서 함수가 호출 될 때마다 항상 1씩 카운트해준다. (처음 할때는 하면안됨)

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
        printf("정점 갯수 추가 한도 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n)
    {
        printf("삽입오류");
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
        insert_edge(g, start-1, end-1);             //무방향 그래프이므로 반드시 시작과 끝, 끝과 시작에 간선 삽입을 해줘야함.
        insert_edge(g, end - 1, start - 1);
    }
    printf("%d",dfs_list(g, 0));
    
    free(g);
}
*/