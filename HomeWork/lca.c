#include <stdio.h>
#define MAX_NODE 50001
#define MAX_DEPTH 20
#define swap(a,b) {int tmp=a; a=b; b=tmp;}

//항상 v가 u보다 깊다고 가정함. 

int parent[MAX_NODE][MAX_DEPTH];
int depth[MAX_DEPTH];
int visited[MAX_NODE];

int findLCA(int u, int v) {
	if (depth[u] > depth[v])  //v가 u보다 깊어야 하므로 swap사용
		{
			swap(u, v);
		}
	for (int i = MAX_DEPTH - 1; i >= 0; i--) //만약 깊이 차이가 5 이고 거슬러 올라갈 때는 4->1 로 i가 큰 수에서 작아지게 만들어짐
	{
		if (depth[v] - depth[u] >= (1 << i))  //v와 u의 깊이 차이롤 비트연산자로 비교
		{
			v = parent[v][i];
		}
	}
	if (u == v)
	{
		return u;
	}
	
	for (int i = MAX_DEPTH - 1; i >= 0; i--) //위와 마찬가지로 거슬러 올라갈 때는 역순으로 i가 작아지게 해줘야 정확한 부모를 찾을 수 있음
	{
		if (parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];				/*만약 for문 안에 else(u와 v가 같을 때)를 넣는다면 init과정에서 모두 0으로 초기화 되어있는 값과
										  맞아떨어져 문제가 생길 수 있음. ex) tree[10][15] = 0, tree[2][15] = 0; 그러므로 else문 실행*/
		}									
	}
	return parent[u][0];
}

void init_tree(int node) {												
	for (int i = 0; i <= node; i++)
	{													//depth와 visited, tree를 모두 초기화시켜주는 작업이다.
		depth[i] = 0;									//depth는 0부터 시작하고, visited는 방문여부를 초기화한다.(0 : 미방문, 1 : 방문)
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
		int ancestor = parent[cur][i - 1];					//현재 노드의 조상을 등록해주는 작업이다.
		parent[cur][i] = parent[ancestor][i - 1];				//반복문에서 약간의 불필요한 작업이 수행되지만 영향 X
	}
}

int main(void) {
	int u, v;
	int node;
	printf("노드 갯수를 입력 : ");
	scanf("%d", &node);
	for (int i = 0; i < node-1; i++) {
		printf("노드 입력 : ");
		scanf("%d %d", &u, &v);
		if (visited[u] == 0 && visited[v] == 1) //v가 u보다 깊어야함
		{
			swap(u, v);
		}
		if (!visited[u])				//방문안했을 때
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
	printf("공통조상의 갯수를 입력 : ");
	scanf("%d", &lca);
	for (int j = 0; j < lca; j++)
	{
		printf("찾으려는 공통조상을 입력 : ");
		scanf("%d %d", &a, &b);
		printf("공통조상 : %d\n", findLCA(a, b));
	}
}