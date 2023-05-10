#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 1100

int treeArr[MAX_ARRAY_SIZE] = { 0 };

//삽입 연산
insert_node(int cur, int key) {
    if (treeArr[cur] == 0)
    {
        treeArr[cur] = key;
    }
    if (key < treeArr[cur])
    {
        insert_node(2 * cur, key);
    }
    else if (key > treeArr[cur])
    {
        insert_node(2 * cur + 1, key);
    }
}

//삭제 연산
delete_node(int cur, int key) {
    if (key < treeArr[cur])
    {
        delete_node(2 * cur, key);
    }
    else if (key > treeArr[cur])
    {
        delete_node(2 * cur + 1, key);
    }
    else
    {
        if (treeArr[2 * cur + 1] != 0) {
            while (treeArr[2 * cur + 1] != 0)
            {
                treeArr[cur] = treeArr[2 * cur + 1];
                cur = 2 * cur + 1;
            }
            treeArr[cur] = 0;
        }
        else
        {
            while (treeArr[2 * cur] != 0)
            {
                treeArr[cur] = treeArr[2 * cur];
                cur = 2 * cur;
            }
            treeArr[cur] = 0;
        }

    }
}
inorder(int cur) {
    if (treeArr[cur] != 0) {
        inorder(2 * cur);
        printf("%d ", treeArr[cur]);
        inorder(2 * cur + 1);
    }
}

preorder(int cur) {
    if (treeArr[cur] != 0) {
        printf("%d ", treeArr[cur]);
        preorder(2 * cur);
        preorder(2 * cur + 1);
    }
}

postorder(int cur) {
    if (treeArr[cur] != 0) {
        postorder(2 * cur);
        postorder(2 * cur + 1);
        printf("%d ", treeArr[cur]);
    }
}

//
int main(void) {
    int cur = 1;
    int random;
    insert_node(cur, 20);
    insert_node(cur, 15);
    insert_node(cur, 22);
    insert_node(cur, 10);
    insert_node(cur, 17);
    insert_node(cur, 21);
    insert_node(cur, 23);
    insert_node(cur, 9);
    insert_node(cur, 12);
    insert_node(cur, 16);
    insert_node(cur, 18);

    inorder(cur);
    printf("\n");
    preorder(cur);
    printf("\n");
    postorder(cur);
   
}