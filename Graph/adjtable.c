// �ڽӱ�洢ͼ�ṹ

#define  MAX_VERTEX_NUM 20//��󶥵����
#define  VertexType int//�������ݵ�����
#define  InfoType int//ͼ�л����߱߰�������Ϣ������
typedef struct ArcNode{
    int adjvex;//�ڽӵ��������е�λ���±�
    struct ArcNode * nextarc;//ָ����һ���ڽӵ��ָ��
    InfoType * info;//��Ϣ��
}ArcNode;
typedef struct VNode{
    VertexType data;//�����������
    ArcNode * firstarc;//ָ���ڽӵ��ָ��
}VNode,AdjList[MAX_VERTEX_NUM];//�洢������ͷ��������
typedef struct {
    AdjList vertices;//ͼ�ж��������
    int vexnum,arcnum;//��¼ͼ�ж������ͱ߻���
    int kind;//��¼ͼ������
}ALGraph;