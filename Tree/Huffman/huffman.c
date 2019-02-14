#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"
#include "quene.h"  // �˴�quene���Ǳ�׼���С�ΪHuffmanר�Ź�����λ��ͬһ�ļ���


void traverseTree(PtrHuffmanTreeNode treeNode, PtrHuffmanTable table, int k, char code[256]){
    if (treeNode->LeftChild == NULL && treeNode->RightChild == NULL) {
        code[k] = '\0';
        PtrHuffmanLabelNode aux = (PtrHuffmanLabelNode)malloc(sizeof(HuffmanLabelNode));
        aux->code = (char*)malloc(sizeof(char)*strlen(code)+1);
        strcpy(aux->code, code);
        aux->symbol = treeNode->symbol;
        aux->next = NULL;
		printf("%c�ı�����%s\n",aux->symbol,code); 
    if (!table->first) {
        table->first = aux;
        table->last = aux;
    }else
    {
        table->last->next = aux;
        table->last = aux;
    }
    }
    if (treeNode->LeftChild) {
        code[k] = '0';
        traverseTree(treeNode->LeftChild,table,k+1,code);

    }
    if (treeNode->RightChild) { 
        code[k] = '1';
        traverseTree(treeNode->RightChild,table,k+1,code);
    }

    
    
}

// ������������
PtrHuffmanTree buildTree(char * inputstring){
    // ����ͳ���ַ����ֵĴ���
    int * probability = (int *)malloc(sizeof(int)*256);

    // ��ʼ�����ִ�������
    for(size_t i = 0; i < 256; i++)
    {
        probability[i] = 0;
    }
    // ͳ���ַ���ӦANSCII����ִ���
    for(size_t i = 0;inputstring[i]!='\0'; i++)
    {
        probability[(unsigned char)inputstring[i]]++;
    }
    // ��ʼ������������
    PQuene HuffmanQueen = InitQuene();
    
    for(size_t i = 0; i < 256; i++)
    {
        if(probability[i]){
        printf("%c������%d�Σ���Ӧ��ANSCII��Ϊ%d\n",(char)i,probability[i],(int)i);
        }
    }

    // �γɹ���������
    for(size_t i = 0; i < 256; i++)
    {
        if(probability[i]){
            PtrHuffmanTreeNode aux = (PtrHuffmanTreeNode)malloc(sizeof(HuffmanTreeNode));
            aux->symbol = (char)i;
            aux->LeftChild = NULL;
            aux->RightChild = NULL;

            ElementType * element = (ElementType*)malloc(sizeof(ElementType));
            element->priority = probability[i];
            element->var = aux;
            
            InsertQuene(HuffmanQueen,*element);
        }
    }
    free(probability); // ���ִ�������ʧȥ�ô����ͷ���

    // ���ɹ�������
    while(HuffmanQueen->size!=1){
        int priority = HuffmanQueen->PFront->next->data.priority; //��һ�����ݵ����ȼ�
        priority += HuffmanQueen->PFront->next->next->data.priority;
        ElementType* element_child = (ElementType *) malloc(sizeof(ElementType));
        DeleteQueneNode(HuffmanQueen,element_child);
        PtrHuffmanTreeNode LeftChild = element_child->var;
        DeleteQueneNode(HuffmanQueen,element_child);
        PtrHuffmanTreeNode RightChild = element_child->var;

        PtrHuffmanTreeNode NewNode = (PtrHuffmanTreeNode)malloc(sizeof(HuffmanLabelNode));
        NewNode ->LeftChild = LeftChild;
        NewNode ->RightChild = RightChild;

        ElementType element_insert;
        element_insert.var = NewNode;
        element_insert.priority = priority;
        InsertQuene(HuffmanQueen, element_insert);
        
    }
    PtrHuffmanTree tree = (PtrHuffmanTree)malloc(sizeof(HuffmanTree));

    ElementType element_root;
    DeleteQueneNode(HuffmanQueen,&element_root);

    tree->root = element_root.var;
    return tree;
}

PtrHuffmanTable buildTable(PtrHuffmanTree huffman_tree){
    PtrHuffmanTable table = (PtrHuffmanTable)malloc(sizeof(HuffmanTable));
    table->first = NULL;
    table->last = NULL;
    
    char code[256];
    int k = 0 ;
    traverseTree(huffman_tree->root , table,k,code);
    
    printf("%c",table->first->symbol);
    return table; 
}

void encode(PtrHuffmanTable table,char * stringtoEncode){
    PtrHuffmanLabelNode traversal;
    printf("Encoding...........\ninputstring:%s\nEncodedstring:",stringtoEncode);

    for(size_t i = 0;stringtoEncode[i] != '\0'; i++)
    {
        traversal = table->first;
        while(traversal->symbol != stringtoEncode[i]) traversal= traversal->next;
        printf("%s",traversal->code);
    }
    printf("\n");
}


void decode(PtrHuffmanTree tree, char * stringtoDecode){
    PtrHuffmanTreeNode traversal = tree->root;

    printf("\n\nDecoding.......\n\n InputString:%s\n",stringtoDecode);
    printf("decodestring:");
    for(size_t i = 0;stringtoDecode[i]!='\0'; i++)
    {
        if (traversal->LeftChild == NULL || traversal->RightChild == NULL) {
            printf("%c",traversal->symbol);
            traversal = tree->root;
        }
        if (stringtoDecode[i] == '0') {
            traversal = traversal->LeftChild;
        }
        else if (stringtoDecode[i] == '1') {
            traversal = traversal->RightChild;
        }
        else
        {
            printf("�������˳���0��1������ַ��أ�\n");
            return;
        }
        
    }
    if (traversal->LeftChild == NULL && traversal->RightChild == NULL) {
        printf("%c",traversal->symbol);
    }
    
    
}
