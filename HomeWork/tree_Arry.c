/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 10000

int treeArr[MAX_ARRAY_SIZE] = { 0 };

//���� ����
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

//���� ����
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

//���� ��ȸ
inorder(int cur) {
    if (treeArr[cur] != 0) {
        inorder(2 * cur);
        printf("%d ", treeArr[cur]);
        inorder(2 * cur + 1);
    }
}

//���� ��ȸ
preorder(int cur) {
    if (treeArr[cur] != 0) {
        printf("%d ", treeArr[cur]);
        preorder(2 * cur);
        preorder(2 * cur + 1);
    }
}

//���� ��ȸ
postorder(int cur) {
    if (treeArr[cur] != 0) {
        postorder(2 * cur);
        postorder(2 * cur + 1);
        printf("%d ", treeArr[cur]);
    }
}

search(int cur, int key) {
    if (key < treeArr[cur])
    {
        if (treeArr[2 * cur] == 0) {
            printf("Fail ==========\n");
            return;
        }
        search(2 * cur, key);
        
    }
    else if (key > treeArr[cur])
    {
        if (treeArr[2 * cur + 1] == 0) {
            printf("Fail ==========\n");
            return;
        }
        search(2 * cur + 1, key);
    }
    else {
        printf("Pass ==========\n");
    }
}

//
int main(void) {
    int cur = 1;
    int random;
    int registerd[MAX_ARRAY_SIZE] = { 0 }; // ��ϵ� ���ڸ� �����ϴ� �迭(random���� �ߺ��� ���� �� �� ������ ȿ�������� �Ÿ��� ����)
    srand(time(NULL));
    //random���� ��忡 ��� insert��
    for (int i = 0; i < 64; i++) {
        random = rand() % 64 + 1;
        for (int j = 0; j <= i; j++)
        {
            if (registerd[j] == random)
            {
                i--;
            }
            else if (registerd[j] == 0)
            {
                registerd[j] = random;
                insert_node(cur, random);
            }
        }
    }
    //��� ����
    int choice;
    int key;
    while (1) {
        printf("0. ����, 1. ���� ��ȸ, 2. ���� ��ȸ, 3. ���� ��ȸ, 4. ���� Ž��, 5. ���� ����\n");
        printf("����� �����ϼ��� : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("�����մϴ�.");
            return;
        case 1:
            printf("\n���� ��ȸ : ");
            preorder(cur);
            printf("\n\n");
            break;
        case 2:
            printf("\n���� ��ȸ : ");
            inorder(cur);
            printf("\n\n");
            break;
        case 3:
            printf("\n���� ��ȸ : ");
            postorder(cur);
            printf("\n\n");
            break;
        case 4:           
            printf("Ž���� ���ڸ� �Է��ϼ��� : ");
            scanf("%d", &key);
            printf("========== �˻���� : ");
            search(cur, key);       
            printf("\n"); 
            break;
        case 5:
            printf("������ ���ڸ� �Է��ϼ��� : ");
            scanf("%d", &key);
            delete_node(cur, key);
            printf("=== %d��(��) ���������� �����Ͽ����ϴ�. ===\n\n", key);
            break;
        }
    }
    
}
*/