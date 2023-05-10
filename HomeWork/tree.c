/*
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_ARRAY_SIZE 100

typedef struct TreeNode {
	int data;
}TreeNode;


TreeNode* treeArr[MAX_ARRAY_SIZE] = { NULL };

TreeNode* insert_node(treeArr,int key,int cur) {

	if (treeArr[cur] == NULL)
	{
		return new_node(treeArr, key);
	}
	if (key < treeArr[cur].data)
	{
		treeArr[2 * cur] = insert_node(treeArr[2 * cur], key);
		return treeArr[2 * cur];
	}
	else if (key > treeArr[cur].data)
	{
		treeArr[2 * cur + 1] = insert_node(treeArr[2 * cur + 1, key]);
		return treeArr[2 * cur + 1];
	}
	
	
}

TreeNode* new_node(treeArr,int item,int cur) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = item;
	treeArr[cur] = temp;
	treeArr[2 * cur] = NULL;
	treeArr[2 * cur + 1] = NULL;
	return treeArr[cur];

	///////////////////////////////////////////
	srand(time(NULL));
	for (int i = 0; i < 64; i++) {
		random = rand() % 10 + 1;
		for (int j = 0; j < MAX_ARRAY_SIZE; j++)
		{
			if (treeArr[j] == random)
			{
				i--;
				break;
			}
			else
			{
				insert_node(cur, random);
			}
		}
	}
}
*/





