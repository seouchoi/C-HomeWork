/*
#include <stdio.h>
#include <string.h>
#define MAX_SIZE_STACK 25

typedef struct {
    char arr[MAX_SIZE_STACK][MAX_SIZE_STACK];
    int top;
} StackType;

void init_stack(StackType* s)
{
    s->top = -1;
}

int full(StackType* s)
{
    return (s->top == MAX_SIZE_STACK - 1);
}

int empty(StackType* s)
{
    return(s->top == -1);
}

void push(StackType* s, char* token)
{
    if (full(s))
    {
        printf("스택이 꽉 찼습니다.");
    }
    else
    {
        strcpy(s->arr[++(s->top)], token);
    }
}

char* pop(StackType* s)
{
    if (empty(s))
    {
        printf("스택이 텅 비었습니다.");
        return NULL;
    }
    else
    {
        return s->arr[(s->top)--];
    }
}

int main(void)
{
    StackType s;
    init_stack(&s);
    char str[MAX_SIZE_STACK];
    char* token;
    int i;
    printf("문장 갯수 입력 : ");
    scanf_s("%d", &i);
    printf("문자열 입력 : ");
    getchar();
    
    for (int j = 0; j < i; j++) {
        fgets(str, MAX_SIZE_STACK, stdin);  
        if (str[strlen(str) - 1] == '\n')
        {
            str[strlen(str) - 1] = '\0';
        }
        printf("Case %d#: ", j + 1);
        token = strtok(str, " ");
        while (token != NULL)
        {
            push(&s, token);
            token = strtok(NULL, " ");
        }

        while (!empty(&s))
        {
            printf("%s ", pop(&s));
        }
    }
  
}
*/
