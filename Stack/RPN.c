//  �沨��������

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define STACK_MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define STR_DOUBLE_MAX 10

typedef int Status;
typedef double ElementType;


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
    char ch;
    char str[STR_DOUBLE_MAX];
    int i=0;
    double e;
    double f;
    double result;
    printf("#####################�沨��������#####################\n");
    printf("��������ʽ(�س���������):");
    scanf("%c", &ch);
    while(ch!='\n'){

        while(isdigit(ch) ||ch=='.' ){
            str[i++] = ch;
            str[i] = '\0';
            if (i==STR_DOUBLE_MAX) {
                printf("����С��ת����Χ\n");
                return -1;
            }
            
            scanf("%c", &ch);
            if (ch == ' ') {
                Push(s, atof(str));
                i = 0;
                break;
            }
           

        }
        
        switch (ch)
        {
            case '+':
                Pop(s, &e);
                Pop(s, &f);
                Push(s, e+f);
                break;
            case '-':
                Pop(s, &e);
                Pop(s, &f);
                Push(s, f-e);
                break;
            case '*':
                Pop(s, &e);
                Pop(s, &f);
                Push(s, f*e);
                break;
            case '/':
                Pop(s, &e);
                Pop(s, &f);
                if (!e) {
                    printf("����Ϊ0, ����\n");
                    return -1;
                }
                Push(s, f/e);
                break;
        }
        scanf("%c",&ch);
    }

    if (Pop(s, &result)) {
        printf("����Ľ����:%f\n", result);
    }

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
