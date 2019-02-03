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

typedef int Status;
typedef int ElementType;

typedef struct ListNode
{
    /* data */
    ElementType data;   //���������
    struct ListNode *next;     //ָ����һ���ڵ��ָ��
}Node,*PNode;


PNode CreateList(void);
void TraverseList(PNode List);
Status IndexList(PNode List, int index, ElementType *e);
Status FindList(PNode List, ElementType var, int *index);


int main(int argc, char const *argv[])
{
    ElementType var;
    int index;
    int find_index;
    ElementType index_date;
    PNode List = CreateList();
    TraverseList(List);

    printf("������Ҫ��ѯ�Ľڵ�:");
    scanf("%d",&index);
    if(IndexList(List, index, &index_date)){
    printf("�����������,λ�ڵ�%d���ڵ������Ϊ:%d\n", index, index_date);   
    }
    printf("��������Ҫ��ѯ������:");
    scanf("%d", &var);
    if(FindList(List, var, &find_index)){
    printf("������ѯ������%d������ĵ�%d���ڵ�\n", var, find_index);

    }
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
    printf("��������Ҫ�����ڵ�ĸ���:");
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
    else
    {
     printf("��������ĳ���Ϊ%d\n",PList_Trav->data);
     PList_Trav = PList_Trav->next;
     i++;
    }
    while(PList_Trav !=NULL){
        printf("��%d���ڵ������Ϊ:%d\n",i,PList_Trav->data);
        PList_Trav = PList_Trav->next;
        i++;
    }
}

/*---------------------��������--------------
1. ���жϴ������������ݵĺ�����
2. ��������
*/

Status IndexList(PNode List, int index, int * e){
   
    if (List == NULL) {
        printf("ͷָ��Ϊ��,��������ʧ��\n");
        exit(-1);
    }
    if (index>List->data) {
        printf("�����ĳ��ȳ�����������\n");
        return ERROR;
    }
    else if (index < 1)
    {
        printf("�����ĳ��Ȳ����Ϲ淶\n");
        return ERROR;
    }
    

    PNode PIndex = List->next;
    for(int i = 1; i < index; i++)
    {   
        PIndex = PIndex->next;
    }
    *e = PIndex->data;
//    printf("�����������,λ�ڵ�%d���ڵ������Ϊ:%d\n", index, PIndex->data);   
    return OK;
}


/*--------------��ѯ����---------------
1. �ж�����ĳ���
2. ��ͷ��ʼ����,ֱ��ƥ��.
*/

Status FindList(PNode List, ElementType var, int *index){
    if (List == NULL) {
        printf("ͷָ��Ϊ�գ���������ʧ��\n");
        exit(-1);
    }
    int node_index = 0; // �ڵ��λ�� 
    if (List->data == 0){   // �ж���������ĳ��ȣ����Ϊ0���Ͳ���Ҫ������
        printf("����ĳ���Ϊ0\n");
        return ERROR;
    };
    PNode PFind = List->next; 
    node_index++;

    while((PFind != NULL)&&(PFind->data!=var)){
        PFind = PFind->next;
        node_index++;

    }
    if (PFind == NULL) {
        printf("��ѯ�޹�\n");
        return ERROR;
    }
    
    *index = node_index;
//    printf("������ѯ������%d������ĵ�%d���ڵ�\n", PFind->data, node_index);
    return OK;
}