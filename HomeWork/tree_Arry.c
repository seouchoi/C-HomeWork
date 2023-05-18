/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 10000

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

//중위 순회
inorder(int cur) {
    if (treeArr[cur] != 0) {
        inorder(2 * cur);
        printf("%d ", treeArr[cur]);
        inorder(2 * cur + 1);
    }
}

//전위 순회
preorder(int cur) {
    if (treeArr[cur] != 0) {
        printf("%d ", treeArr[cur]);
        preorder(2 * cur);
        preorder(2 * cur + 1);
    }
}

//후위 순회
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
    int registerd[MAX_ARRAY_SIZE] = { 0 }; // 등록된 숫자를 저장하는 배열(random에서 중복된 수를 좀 더 빠르고 효율적으로 거르기 위함)
    srand(time(NULL));
    //random으로 노드에 모두 insert함
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
    //기능 구현
    int choice;
    int key;
    while (1) {
        printf("0. 종료, 1. 전위 순회, 2. 중위 순회, 3. 후위 순회, 4. 숫자 탐색, 5. 숫자 삭제\n");
        printf("기능을 선택하세요 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("종료합니다.");
            return;
        case 1:
            printf("\n전위 순회 : ");
            preorder(cur);
            printf("\n\n");
            break;
        case 2:
            printf("\n중위 순회 : ");
            inorder(cur);
            printf("\n\n");
            break;
        case 3:
            printf("\n후위 순회 : ");
            postorder(cur);
            printf("\n\n");
            break;
        case 4:           
            printf("탐색할 숫자를 입력하세요 : ");
            scanf("%d", &key);
            printf("========== 검색결과 : ");
            search(cur, key);       
            printf("\n"); 
            break;
        case 5:
            printf("삭제할 숫자를 입력하세요 : ");
            scanf("%d", &key);
            delete_node(cur, key);
            printf("=== %d을(를) 성공적으로 삭제하였습니다. ===\n\n", key);
            break;
        }
    }
    
}
*/