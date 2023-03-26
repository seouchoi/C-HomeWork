/*
#include <stdio.h>
#include <algorithm>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int N) {
    top++;
    stack[top] = N;
};

int main_cpp(void) {

    int n = 0;
    scanf_s("%d", &n);

    for (int i = 1; i <= n; i++) {
        push(i);
    }

    do {
        for (int i = 0; i <= top; i++) {
            printf("%d", stack[i]);
        }
        printf("\n");
    } while (std::next_permutation(stack, stack + top + 1));

    return 0;
}
*/