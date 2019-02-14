//  ������ת��ʮ���� ��ջʵ��
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"


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
