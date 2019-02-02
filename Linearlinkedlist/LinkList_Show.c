// System : Win10
// Compiler : gcc with Vscode
// author : princeling

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Static;
typedef int ElementType;

typedef struct ListNode
{
    /* data */
    ElementType data;   //���������
    struct ListNode *next;     //ָ����һ���ڵ��ָ��
}Node,*PNode;


PNode CreateList(void);
void TraverseList(PNode List);



int main(int argc, char const *argv[])
{
    PNode List = CreateList();
    TraverseList(List);
    return 0;
}



/*--------------------��������---------------------
����ʹ��β�巨: 
1. ����һ���µ�Node  PNew
2. ��PNew��������֮��,��ԭ����PTail��nextָ��PNew
3. ��PNew��nextָ��Null
4. PNew����µ�PTail
-------------------------------------------------*/
PNode CreateList(void){
    int lenth;
    int var;
    // ��һ��
    PNode PHead = (PNode)malloc(sizeof(Node));
    if (PHead == NULL) {
        /* code */
        printf("�ռ�������\n");
        exit(-1);
    }
    PNode PTail = PHead;
    PTail->next = NULL;
    printf("������ڵ�ĸ���:");
    scanf("%d",&lenth);
    PHead->data = lenth;    // Ϊͷ�ڵ�����ݸ�ֵ����ֵΪ����ĳ���
    for(int i = 0; i < lenth; i++)
    {
        PNode PNew = (PNode)malloc(sizeof(Node));
        if (PNew == NULL) {
            printf("��%d���ڵ����ʧ��",i+1);
            exit(-1);
        }
        // �ڶ���
        printf("�������%d���ڵ������:",i+1);
        scanf("%d",&var);
        PNew->data = var;
        // ������
        PNew->next = NULL;
        PTail->next = PNew;
        // ���Ĳ�
        PTail = PNew;
    }
    
    printf("�������ɹ�.\n");
    return PHead;   //����ͷָ��
}


/*-----------------��������----------------------
1. ����ͷָ��PHeadָ��ͷ����
2. ��������һֱ��nextָ��NULL
*/
void TraverseList(PNode List){
    PNode PList_Trav = List;
    int i = 0;
    if (PList_Trav == NULL) {
        printf("��������ʧ��\n");
        exit(-1);
    }
    
    while(PList_Trav !=NULL){
        printf("��%d���ڵ������Ϊ:%d\n",i,PList_Trav->data);
        PList_Trav = PList_Trav->next;
        i++;
    }
}