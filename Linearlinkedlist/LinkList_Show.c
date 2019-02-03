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
PNode FindList(PNode List, ElementType var);


int main(int argc, char const *argv[])
{
    ElementType var;
    PNode List = CreateList();
    TraverseList(List);
    printf("��������Ҫ��ѯ������:");
    scanf("%d", &var);
    FindList(List, var);
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

/*--------------��ѯ����---------------
1. �ж�����ĳ���
2. ��ͷ��ʼ����,ֱ��ƥ��.
*/

PNode FindList(PNode List, ElementType var){
    if (List == NULL) {
        printf("ͷָ��Ϊ�գ���������ʧ��\n");
        exit(-1);
    }
    int node_index = 0; // �ڵ��λ�� 
    if (List->data == 0){   // �ж���������ĳ��ȣ����Ϊ0���Ͳ���Ҫ������
        printf("����ĳ���Ϊ0\n");
        return List;
    };
    PNode PFind = List->next; 
    node_index++;

    while((PFind != NULL)&&(PFind->data!=var)){
        PFind = PFind->next;
        node_index++;
    }

    printf("������ѯ������%d������ĵ�%d���ڵ�", PFind->data, node_index);
    return PFind;
}