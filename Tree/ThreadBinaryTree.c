#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAX_TREE_SIZE 100

typedef int ElementType;
typedef int Status;
typedef enum{Child, Thread} Flag;

typedef struct BiTNode
{
    ElementType data;
    struct BiTNode * LeftChild;
    struct BiTNode * RightChild;
    Flag LF;    // 0 -> ChildNode 1-> FrontNode
    Flag RF;    // 0 -> ChildNode 1-> rearNode
}BiTNode, *PtrBiTNode;

// ȫ�ֱ��� ���ǰ�����
PtrBiTNode pre;


void CreateBinaryTree(PtrBiTNode *Tree);
void visit(ElementType data, int level);
void PreOrderTraverse(PtrBiTNode root, int level);
void MidOrderTraverse(PtrBiTNode root, int level);
void ThreadTreeInit(PtrBiTNode root);
void InitPre_Thread(PtrBiTNode root);


int main(int argc, char const *argv[])
{
    PtrBiTNode root = (PtrBiTNode)malloc(sizeof(BiTNode));
    int level = 1;
    printf("��������ǰ�����������:");
    CreateBinaryTree(&root);
    InitPre_Thread(root);
    return 0;
}

// ����������   ϰ����ǰ���������
void CreateBinaryTree(PtrBiTNode *root){
    
    char ch;
    scanf("%c", &ch);
    
    if (ch == ' ') {
        *root = NULL;
    }
    else
    {   // ǰ��������ķ���������
        *root = (PtrBiTNode)malloc(sizeof(BiTNode));
        (*root)->data = ch;
        (*root)->LF = Child;
        (*root)->RF = Child;

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
        //ǰ�����˳�� ������
        visit(root->data, level);
        PreOrderTraverse(root->LeftChild,level+1);
        PreOrderTraverse(root->RightChild, level+1);
    }
}

// �������������
void MidOrderTraverse(PtrBiTNode root, int level){
    if (root) {
        // �������˳�� �����
        MidOrderTraverse(root->LeftChild,level+1);
        visit(root->data, level);
        MidOrderTraverse(root->RightChild, level+1);
    }
}

// �������������������������
void ThreadTreeInit(PtrBiTNode root){
    if (root) {
        // �������˳�� �����
        ThreadTreeInit(root->LeftChild);  // һ·����������
        
        if (!root->LeftChild) {
            root->LF = Thread;
            root->LeftChild = pre;
        }
        if (!pre->RightChild) {
            pre->RF = Thread;
            pre->RightChild = root;         // A**B**C  RootΪB����preΪA�� RootΪCʱ��PreΪB
        }
        pre = root;
        ThreadTreeInit(root->RightChild); // һ·����������
    }
}

// ��ʼ��Pre�ڵ㣬��ʼ��ȫ�ֱ�����ʱ��û�г�ֵ���׳�����
void InitPre_Thread(PtrBiTNode root){
    PtrBiTNode p = (PtrBiTNode)malloc(sizeof(BiTNode));
    pre = p;
    pre->LF = Child;
    pre->RF = Thread;
    pre->RightChild = pre;
    if (root) {
        pre->LeftChild = root;
        ThreadTreeInit(root);   // ����������������,�����Ľڵ�ָ��p . p����ָ��Root�����root�����ڣ���ָ������
        pre->RightChild = p;
        pre->RF = Thread;
    }
    else
    {
        pre->RightChild = pre;
    }
}