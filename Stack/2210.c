//  ������ת��ʮ���� ��ջʵ��

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElementType;


typedef struct stack
{
    ElementType * base;
    ElementType * top;
    int stackSize;
} Stack,*PStack;



PStack initStack(void);
Status Push(PStack s, ElementType data);
Status Pop(PStack s, ElementType* data);
int StackLen(PStack s);
Status ClearStack(PStack s);
Status DeleteStack(PStack s);

int main(int argc, char const *argv[])
{
    PStack s = initStack();
    ElementType ch;
    int sum = 0;
    int count = 0;
    printf("���������������:");
    scanf("%c",&ch);
    while(ch != '\n'){
        if (Push(s, ch)) {
           printf("����%c��ջ�ɹ�\n",ch);
        }
        scanf("%c",&ch);
    }
    printf("��ջ���ÿռ�Ϊ:%d\nȫ���ռ��СΪ:%d\n",s->top-s->base,s->stackSize);

    count = s->top-s->base;
    for(int i = 0; i < count; i++)
    {   Pop(s,&ch);
        sum += (ch-48)*pow(2,i);
    }
    printf("ת���Ľ��Ϊ:%d\n", sum);

    return 0;
}


// ��ʼ����ջ�����ض�ջ�ṹ��ָ��
PStack initStack(void){
    PStack s = (PStack)malloc(sizeof(Stack));
    s->base = (ElementType *)malloc(sizeof(ElementType) * STACK_MAX_SIZE);
    if (s->base == NULL) {
        printf("ջ��ΪNULL, ��ʼ��ջʧ��\n");
        exit(-1);
    }

    s->top = s->base;
    s->stackSize = STACK_MAX_SIZE;
    return s;
}


Status Push(PStack s, ElementType data){
    if (s->top - s->base == s->stackSize) {
        printf("��ջ����,������ջʧ��\n");
        return ERROR;
    }
    *(s->top) = data;
    s->top++;
    return OK;
}

Status Pop(PStack s, ElementType* data){
    if (s->top == s->base) {
        printf("��ջ�ѿ�,���ݳ�ջʧ��\n");
        return ERROR;
    }

    s->top--;
    *data = *(s->top);

    return OK;
}


//���ض�ջ�ĳ���
int StackLen(PStack s){
    return s->top-s->base;
}

//��ն�ջ
Status ClearStack(PStack s){
    s->top = s->base;
    return OK;
}

//ɾ����ջ
Status DeleteStack(PStack s){

    if (s->base == NULL) {
        printf("ջ��ΪNULL, ��ջɾ��ʧ��\n");
        return ERROR;    
    }

    int lenth = s->stackSize;
    
    for(int i = 0; i < lenth; i++)
    {
        free(s->base);
        s->base++;
    }
    s->stackSize = 0;
    s->base = s->top = NULL;
    return OK;
}
