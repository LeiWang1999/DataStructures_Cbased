// �����������������

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERtEX_NUM 20                   //�����������
#define VRType int                          //��ʾ����֮��Ĺ�ϵ�ı�������
#define VertexType int                     //ͼ�ж������������
typedef enum{false,true}bool;               //����bool�ͳ���
bool visited[MAX_VERtEX_NUM];               //����ȫ�����飬��¼��Ƕ����Ƿ񱻷��ʹ�

typedef struct {
    VRType adj;                             //������Ȩͼ���� 1 �� 0 ��ʾ�Ƿ����ڣ����ڴ�Ȩͼ��ֱ��ΪȨֵ��
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //�洢ͼ�ж�������
    AdjMatrix arcs;                         //��ά���飬��¼����֮��Ĺ�ϵ
    int vexnum,arcnum;                      //��¼ͼ�Ķ������ͻ����ߣ���
}MGraph;
//�����ֵܱ�ʾ����������ṹ
typedef struct CSNode{
    VertexType data;
    struct CSNode * lchild;//���ӽ��
    struct CSNode * nextsibling;//�ֵܽ��
}*CSTree,CSNode;
//���ݶ��㱾�����ݣ��жϳ������ڶ�ά�����е�λ��
int LocateVex(MGraph G,VertexType v){
    int i=0;
    //����һά���飬�ҵ�����v
    for (; i<G.vexnum; i++) {
        if (G.vexs[i]==v) {
            break;
        }
    }
    //����Ҳ����������ʾ��䣬����-1
    if (i>G.vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}
//��������ͼ
void CreateDN(MGraph *G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    getchar();
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=0;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2;
        scanf("%d,%d",&v1,&v2);
        int n=LocateVex(*G, v1);
        int m=LocateVex(*G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj=1;
        G->arcs[m][n].adj=1;//����ͼ�Ķ��׾��������Խ��߶Գ�
    }
}
int FirstAdjVex(MGraph G,int v)
{
    //�����������±�Ϊv�Ķ���֮���бߵĶ��㣬�������������е��±�
    for(int i = 0; i<G.vexnum; i++){
        if( G.arcs[v][i].adj ){
            return i;
        }
    }
    return -1;
}
int NextAdjVex(MGraph G,int v,int w)
{
    //��ǰһ������λ��w����һ��λ�ÿ�ʼ������֮���бߵĶ���
    for(int i = w+1; i<G.vexnum; i++){
        if(G.arcs[v][i].adj){
            return i;
        }
    }
    return -1;
}
void DFSTree(MGraph G,int v,CSTree*T){
    //�����ڷ��ʵĸö���ı�־λ��Ϊtrue
    visited[v]=true;
    bool first=true;
    CSTree q=NULL;
    //���α����ö���������ڽӵ�
    for (int w=FirstAdjVex(G, v); w>=0; w=NextAdjVex(G, v, w)) {
        //������ٽ���־λΪfalse��˵����δ����
        if (!visited[w]) {
            //Ϊ���ڽӵ��ʼ��Ϊ���
            CSTree p=(CSTree)malloc(sizeof(CSNode));
            p->data=G.vexs[w];
            p->lchild=NULL;
            p->nextsibling=NULL;
            //�ý��ĵ�һ���ڽӵ���Ϊ���ӽ�㣬�����ڽӵ���Ϊ���ӽ����ֵܽ��
            if (first) {
                (*T)->lchild=p;
                first=false;
            }
            //����Ϊ�ֵܽ��
            else{
                q->nextsibling=p;
            }
            q=p;
            //�Ե�ǰ���ʵĶ���Ϊ�����������������ڽӵ�
            DFSTree(G, w, &q);
        }
    }
}
//���������������ɭ�ֲ�ת��Ϊ������
void DFSForest(MGraph G,CSTree *T){
    (*T)=NULL;
    //ÿ������ı��Ϊ��ʼ��Ϊfalse
    for (int v=0; v<G.vexnum; v++) {
        visited[v]=false;
    }
    CSTree q=NULL;
    //����ÿ��������Ϊ��ʼ�㣬�����������������
    for (int v=0; v<G.vexnum; v++) {
        //����ö���ı��λΪfalse��֤��δ���ʹ�
        if (!(visited[v])) {
            //�½�һ����㣬��ʾ�ö���
            CSTree p=(CSTree)malloc(sizeof(CSNode));
            p->data=G.vexs[v];
            p->lchild=NULL;
            p->nextsibling=NULL;
            //�����δ�գ���ö�����Ϊ��������
            if (!(*T)) {
                (*T)=p;
           
            }
            //�ö�����Ϊ�������ֵܽ��
            else{
                q->nextsibling=p;
            }
            //ÿ�ζ�Ҫ��qָ��ָ���µĽ�㣬Ϊ�´���ӽ�����̵�
            q=p;
            //�Ըý��Ϊ��ʼ�㣬�����������������
            DFSTree(G,v,&p);
        }
    }
}
//ǰ�����������
void PreOrderTraverse(CSTree T){
    if (T) {
        printf("%d ",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->nextsibling);
    }
    return;
}
int main() {
    MGraph G;//����һ��ͼ�ı���
    CreateDN(&G);//��ʼ��ͼ
    CSTree T;
    DFSForest(G, &T);
    PreOrderTraverse(T);
    return 0;
}