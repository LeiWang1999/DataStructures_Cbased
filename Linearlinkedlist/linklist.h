#ifndef __LINKLIST_DEFINED__
#define __LINKLIST_DEFINED__

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


PNode CreateList(int lenth);
void TraverseList(PNode List);
Status IndexList(PNode List, int index, ElementType *e);
Status FindList(PNode List, ElementType var, int *index);
Status InsertList(PNode List, int pos, ElementType data);
Status DeleteNode(PNode List, int pos);
Status DeleteList(PNode List);


#endif