#include <stdio.h>
#define MAX_NODE 50001
#define MAX_DEPTH 20
#define swap(a,b) {int tmp=a; a=b; b=tmp;}

//�׻� v�� u���� ��ٰ� ������. 

int parent[MAX_NODE][MAX_DEPTH];
int depth[MAX_DEPTH];
int visited[MAX_NODE];

int findLCA(int u, int v) {
	if (depth[u] > depth[v])  //v�� u���� ���� �ϹǷ� swap���
		{
			swap(u, v);
		}
	for (int i = MAX_DEPTH - 1; i >= 0; i--) //���� ���� ���̰� 5 �̰� �Ž��� �ö� ���� 4->1 �� i�� ū ������ �۾����� �������
	{
		if (depth[v] - depth[u] >= (1 << i))  //v�� u�� ���� ���̷� ��Ʈ�����ڷ� ��
		{
			v = parent[v][i];
		}
	}
	if (u == v)
	{
		return u;
	}
	
	for (int i = MAX_DEPTH - 1; i >= 0; i--) //���� ���������� �Ž��� �ö� ���� �������� i�� �۾����� ����� ��Ȯ�� �θ� ã�� �� ����
	{
		if (parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];				/*���� for�� �ȿ� else(u�� v�� ���� ��)�� �ִ´ٸ� init�������� ��� 0���� �ʱ�ȭ �Ǿ��ִ� ����
										  �¾ƶ����� ������ ���� �� ����. ex) tree[10][15] = 0, tree[2][15] = 0; �׷��Ƿ� else�� ����*/
		}									
	}
	return parent[u][0];
}

void init_tree(int node) {												
	for (int i = 0; i <= node; i++)
	{													//depth�� visited, tree�� ��� �ʱ�ȭ�����ִ� �۾��̴�.
		depth[i] = 0;									//depth�� 0���� �����ϰ�, visited�� �湮���θ� �ʱ�ȭ�Ѵ�.(0 : �̹湮, 1 : �湮)
		visited[i] = 0;
		for (int j = 0; j < MAX_DEPTH; j++)
		{
			parent[i][j] = 0;
		}
	}
}

void makeTree(int cur, int root, int curDepth) {
	visited[cur] = 1;
	depth[cur] = curDepth;
	parent[cur][0] = parent;
	
	for (int i = 1; i < MAX_DEPTH; i++)
	{
		int ancestor = parent[cur][i - 1];					//���� ����� ������ ������ִ� �۾��̴�.
		parent[cur][i] = parent[ancestor][i - 1];				//�ݺ������� �ణ�� ���ʿ��� �۾��� ��������� ���� X
	}
}

int main(void) {
	int u, v;
	int node;
	printf("��� ������ �Է� : ");
	scanf("%d", &node);
	for (int i = 0; i < node-1; i++) {
		printf("��� �Է� : ");
		scanf("%d %d", &u, &v);
		if (visited[u] == 0 && visited[v] == 1) //v�� u���� ������
		{
			swap(u, v);
		}
		if (!visited[u])				//�湮������ ��
		{
			makeTree(u, 0, 1);
		}
		if (!visited[v])
		{
			makeTree(v, u, depth[u] + 1);
		}
	}
	int lca;
	int a, b;
	printf("���������� ������ �Է� : ");
	scanf("%d", &lca);
	for (int j = 0; j < lca; j++)
	{
		printf("ã������ ���������� �Է� : ");
		scanf("%d %d", &a, &b);
		printf("�������� : %d\n", findLCA(a, b));
	}
}