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
Status InsertList(PNode List, int pos, ElementType data);
Status DeleteNode(PNode List, int pos);
Status DeleteList(PNode List);
Status Josephus(PNode List);

int main(int argc, char const *argv[])
{
    PNode List = CreateList();
    TraverseList(List);
    Josephus(List);
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
    int lenth = 41;
    int var = 0;
    // ��һ��
    PNode PHead = (PNode)malloc(sizeof(Node));
    if (PHead == NULL) {
        /* code */
        printf("�ռ�������\n");
        exit(-1);
    }
    PNode PTail = PHead;
    PTail->next = PHead;
//    printf("��������Ҫ�����ڵ�ĸ���:");
//    scanf("%d",&lenth);
    PHead->data = lenth;    // Ϊͷ�ڵ�����ݸ�ֵ����ֵΪ����ĳ���
    for(int i = 0; i < lenth; i++)
    {
        PNode PNew = (PNode)malloc(sizeof(Node));
        if (PNew == NULL) {
            printf("��%d���ڵ����ʧ��",i+1);
            exit(-1);
        }
        // �ڶ���
//        printf("�������%d���ڵ������:",i+1);
//        scanf("%d",&var);
        var++;
        PNew->data = var;
        // ������
        PNew->next = PHead->next;
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
    do{
        printf("��%d���ڵ������Ϊ:%d\n",i,PList_Trav->data);
        PList_Trav = PList_Trav->next;
        i++;
    }while(PList_Trav !=List->next);
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


/*------------------��������----------------------
����������pos��ǰ�����һ������
1. �½�һ���ڵ�Pnew�������ݸ�ֵ
2. ��Pnew-nextָ��pos
3. ��posǰ�Ľڵ�-nextָ��pnew
*/
Status InsertList(PNode List, int pos, ElementType data){
    if (List == NULL) {
        printf("ͷָ��Ϊ��, ��������ʧ��\n");
        exit(-1);
    }
    if (pos<1 || pos >List->data+1) {
        printf("pos�������۷�Χ��, ��������ʧ��\n");
        return ERROR;
    }
    PNode PList = List;
    PNode PNew = (PNode)malloc(sizeof(Node));       //#######�ǵ�Ҫ���ٿռ�
    PNew->data = data;
    for(int i = 0; i < pos-1; i++)
    {
        PList = PList->next;   
    }
    // ��ʱi��ֵΪpos-1 PListΪpos-1�Ľڵ�

    PNew->next = PList->next; // �ڶ���
    PList->next = PNew;     // ������
    List->data++;
    return OK;
    
}



/*--------------------ɾ���ڵ�----------------
1. ������ pos�ڵ�֮ǰ�Ľڵ�
2. ���˽ڵ��ָ��ָ��pos����һ���ڵ�
3. �ͷ�pos�ڵ�
*/
Status DeleteNode(PNode List, int pos){
    if (List == NULL) {
        printf("ͷָ��Ϊ��, ɾ���ڵ�ʧ��\n");
        exit(-1);   
    }
    
    PNode PDele = List;
    PNode Temp;
    // ��ʱ.PDeleָ��pos-1
    Temp = PDele->next;
    PDele->next = Temp->next;
    free(Temp);
    return OK;
}



/*-------------------ɾ������------------------
1. ���������ͷ��ڴ�
Note : ����ɾ��ͷ�ڵ�
*/
Status DeleteList(PNode List){
    if (List==NULL) {
        printf("ͷָ��Ϊ��, ɾ������ʧ��\n");
        exit(-1);
    }
    PNode PDele = List->next;
    List->next = NULL;  // �������� �������ʧ��
    List->data = 0;
    PNode Temp = PDele;
    while(PDele!=NULL){
        Temp = PDele->next;
        free(PDele);
        PDele = Temp;
    }
    return OK;
}

Status Josephus(PNode List){
    PNode PList = List->next;
    int count = 1;
    printf("%d ", PList->data);
    while(List->data){
        count++;
        if (count == 3) {
            printf("died ",PList->data);
            DeleteNode(PList, 1);
            List->data--;
            count = 1;
            PList = PList->next;
            
        }
        else PList = PList->next;
        printf("%d ", PList->data);
        
    }

    
}
