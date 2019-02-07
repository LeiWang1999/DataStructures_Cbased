#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

#define STACK_MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElementType;


// ��������
typedef struct Node
{
    ElementType data;
    struct Node * next;
}Node, *PNode;

// ���е�Ԫ��Ӧ��ָ������Ľڵ�
typedef struct Quene
{
    PNode PFront;
    PNode PRear;
}Quene, *PQuene;

PQuene InitQuene(void);
Status InsertQuene(PQuene LinkQuene, ElementType var);
Status DeleteQueneNode(PQuene LinkQuene, ElementType *var);

int main(int argc, char const *argv[])
{
    PQuene LinkQuene = InitQuene();
    char ch;
    printf("�������ַ���:");
    scanf("%c",&ch);
    while(ch!='\n'){
        InsertQuene(LinkQuene, ch);
        scanf("%c", &ch);
    }
    printf("�����еĽ��:");
    while(LinkQuene->PFront->next != NULL){
        DeleteQueneNode(LinkQuene,&ch);
        printf("%c",ch);
    }

    return 0;
}

// ��ʼ������
PQuene InitQuene(void){
    PQuene LinkQuene = (PQuene)malloc(sizeof(Quene));
    assert(LinkQuene);
    LinkQuene->PFront = LinkQuene->PRear = (PNode)malloc(sizeof(Node));
    assert(LinkQuene->PFront);
    assert(LinkQuene->PRear);
    LinkQuene->PFront->next = NULL;
    return LinkQuene;
}


// ��β��������
Status InsertQuene(PQuene LinkQuene, ElementType var){
    
    PNode InsertNode = (PNode)malloc(sizeof(Node));
    assert(InsertNode); 
    InsertNode->data = var;
    InsertNode->next = NULL;
    LinkQuene->PRear->next = InsertNode;
    LinkQuene->PRear = InsertNode;
    
    return OK;
}

Status DeleteQueneNode(PQuene LinkQuene, ElementType *var){
    if (LinkQuene->PFront == LinkQuene->PRear) {
        printf("������Ϊ��\n");
        return ERROR;
    }
    else
    {
        PNode p = (PNode)malloc(sizeof(Node));
        p = LinkQuene->PFront->next;
        *var = p->data;
        LinkQuene->PFront->next = p->next;
        if (LinkQuene->PRear == p) {
            LinkQuene->PRear = LinkQuene->PFront;
        }
        free(p);
        return OK;
    }
    
    return OK;

}

Status DeleteQuene(PQuene LinkQuene){

    assert(LinkQuene);

    while(LinkQuene->PFront){
        LinkQuene->PRear = LinkQuene->PFront->next;
        free(LinkQuene->PRear);
        LinkQuene->PFront = LinkQuene->PRear;
    }
    
    return ERROR;
}