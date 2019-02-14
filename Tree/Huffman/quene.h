#ifndef __QUENE_DEFINED__
#define __QUENE_DEFINED__
#include "huffman.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0


typedef int Status;
typedef struct ElementType{
    PtrHuffmanTreeNode var;
    unsigned int priority;
}ElementType;

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
    int size;
}Quene, *PQuene;

PQuene InitQuene(void);
Status InsertQuene(PQuene LinkQuene, ElementType var);
Status DeleteQueneNode(PQuene LinkQuene, ElementType *var);
Status DeleteQuene(PQuene LinkQuene);

#endif