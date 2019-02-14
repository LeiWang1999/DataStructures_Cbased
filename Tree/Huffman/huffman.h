#if !defined(__HUFFMAN_DEFINED__)
#define __HUFFMAN_DEFINED__

typedef struct HuffmanTreeNode
{   
    char symbol;                        // symbolָ���� ��ŵ��ַ�
    struct HuffmanTreeNode * LeftChild;
    struct HuffmanTreeNode * RightChild;
}HuffmanTreeNode, *PtrHuffmanTreeNode;  // ���������Ľڵ� 

typedef struct HuffmanTree
{
    PtrHuffmanTreeNode root;
}HuffmanTree,*PtrHuffmanTree;  // ���������ĸ��ڵ�


typedef struct HuffmanLabelNode
{
    char symbol;    // ��ŵ��ַ�
    char * code;    // �浵�ַ�������
    struct HuffmanLabelNode * next;
}HuffmanLabelNode, *PtrHuffmanLabelNode;

typedef struct HuffmanTable
{
    PtrHuffmanLabelNode first;
    PtrHuffmanLabelNode last;
}HuffmanTable,*PtrHuffmanTable;

PtrHuffmanTree buildTree(char * inputstring);
PtrHuffmanTable buildTable(PtrHuffmanTree huffman_tree);
void encode(PtrHuffmanTable table, char * stringtoEncode);
void decode(PtrHuffmanTree tree, char * stringtoDecode);

#endif // __HUFFMAN_DEFINED__
