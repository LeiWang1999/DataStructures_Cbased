//  ��׺���ʽת����ǰ׺���ʽ

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

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
void dal2rpn(PStack s);
int main(int argc, char const *argv[])
{
    PStack s = initStack();
    dal2rpn(s);
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


/*dal2rpn
ת��������Ҫ�õ�ջ������������£�
1��������������������Ǿ�ֱ�ӽ��������
2����������������������ǽ�����뵽ջ�У�����������ʱ����Ҳ�������ջ�С�
3���������һ�������ţ���ջԪ�ص������������Ĳ��������ֱ������������Ϊֹ��ע�⣬������ֻ�������������
4����������κ������Ĳ��������磨��+���� ��*�������������ȣ���ջ�е���Ԫ��ֱ���������ָ������ȼ���Ԫ��(����ջΪ��)Ϊֹ����������ЩԪ�غ󣬲Ž������Ĳ�����ѹ�뵽ջ�С���һ����Ҫע�⣬ֻ��������" ) "����������ǲŵ���" ( "������������Ƕ����ᵯ��" ( "��
5��������Ƕ����������ĩβ����ջ������Ԫ�����ε�����*/
void dal2rpn(PStack s){

    char ch;
    ElementType e;
    printf("��������յ���׺���ʽ:");
    scanf("%c", &ch);
    while(TRUE){
        while (isdigit(ch)) {
            printf("%c",ch);
            scanf("%c", &ch);
            if (!isdigit(ch)) {
                printf(" ");
            }
        }
        if (ch == ')')     //�����)��һֱ������() # (�����
        {
            Pop(s,&e);
            while(e != '('){
                printf("%c", e);
                Pop(s,&e);
            }
        }
        else if (ch == '+' || ch== '-')
        {
            if (!StackLen(s)) {
                Push(s, ch);    // �����ջ������ջ���������γ�ջ
            }
            else
            {
                do
                {
                    Pop(s, &e);
                    if ('(' == e) {
                        Push(s,e);
                    }
                    else
                    {
                        printf("%c ",e);
                    }
                    
                } while (!StackLen(s) && e !='(');  //��ջ�ջ��ߵ���(, ע��(�����
                Push(s, ch);
            }
            
            
        }
        else if (ch == '*' || ch == '/')
        {
            Push(s, ch);
        }
        else
            if (ch != '\n')    printf("�������\n");
        if (ch=='\n') {
            break;
        }else   scanf("%c", &ch);
    }
    while(StackLen(s)){
        Pop(s, &e);
        printf("%c ", e);
    }
}