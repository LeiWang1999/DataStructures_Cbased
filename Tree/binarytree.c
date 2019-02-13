#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAX_TREE_SIZE 100

typedef int ElementType;
typedef int Status;

typedef struct BiTNode
{
    ElementType data;
    struct BiTNode * LeftChild;
    struct BiTNode * RightChild;
}BiTNode, *PtrBiTNode;

void CreateBinaryTree(PtrBiTNode *Tree);
void visit(ElementType data, int level);
void PreOrderTraverse(PtrBiTNode root, int level);

int main(int argc, char const *argv[])
{
    PtrBiTNode root = (PtrBiTNode)malloc(sizeof(BiTNode));
    int level = 1;
    printf("��������ǰ�����������:");
    CreateBinaryTree(&root);
    PreOrderTraverse(root, level);
    return 0;
}

// ����������
void CreateBinaryTree(PtrBiTNode *root){
    
    char ch;
    scanf("%c", &ch);
    
    if (ch == ' ') {
        *root = NULL;
    }
    else
    {   // ǰ������ķ���������
        *root = (PtrBiTNode)malloc(sizeof(BiTNode));
        (*root)->data = ch;
        CreateBinaryTree(&(*root)->LeftChild);
        CreateBinaryTree(&(*root)->RightChild);
    }
}


// ���ʽڵ����
void visit(ElementType data, int level){
    printf("����%c�ڵ�%d��\n",data,level);
}

// ǰ�����������
void PreOrderTraverse(PtrBiTNode root, int level){
    if (root) {
        //ǰ�����˳��
        visit(root->data, level);// �ȷ��ʸ��ڵ�
        PreOrderTraverse(root->LeftChild,level+1);
        PreOrderTraverse(root->RightChild, level+1);
    }
}