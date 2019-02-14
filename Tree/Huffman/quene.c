#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include "quene.h"



// ��ʼ������
PQuene InitQuene(void){
    PQuene LinkQuene = (PQuene)malloc(sizeof(Quene));
    assert(LinkQuene);
    LinkQuene->PFront = LinkQuene->PRear = (PNode)malloc(sizeof(Node));
    assert(LinkQuene->PFront);
    assert(LinkQuene->PRear);
    LinkQuene->PFront->next = NULL;
    LinkQuene->size = 0;
    return LinkQuene;
}


// ͨ���Ƚ�������  
Status InsertQuene(PQuene LinkQuene, ElementType var){
    
    PNode InsertNode = (PNode)malloc(sizeof(Node));
    assert(InsertNode); 
    InsertNode->data = var;
    InsertNode->next = NULL;
/*    LinkQuene->PRear->next = InsertNode;
    LinkQuene->PRear = InsertNode;
*/
    if (LinkQuene->size == 0 || LinkQuene->PFront->next == 0) {
        LinkQuene->PFront->next = InsertNode;
        LinkQuene->PRear = InsertNode;
        LinkQuene->size++;
    }
    else
    {  
        if (var.priority <= LinkQuene->PFront->next->data.priority) {   //����������ݵ����ȼ�С�ڵ�һ��Ԫ��
            // �Ѳ������ݵ�ָ��ָ��ԭ���ĵ�һ��,�ڰ�front��nextָ���������
            InsertNode->next = LinkQuene->PFront->next;
            LinkQuene->PFront->next = InsertNode;
            LinkQuene->size++;
            return OK;
        }
        else
        {   PNode iterator = LinkQuene->PFront->next; // ������ָ����еĵ�һ��Ԫ��
            while(iterator->next){  //�����һ��Ԫ�ص�ʱ��ֹͣ
                if (var.priority <= iterator->next->data.priority) {
                    // ����������ȼ��ȵ�������ָ���ȼ�ҪС
                    // ��ѽڵ�����ڵ�����֮ǰ����Ҫ�Ƚϵ���next
                    // ��˺��������һ���ڵ㣬��������һ���ڵ㶼��ƥ��
                    // �������е���ĩβ
                    InsertNode->next = iterator->next;
                    iterator->next = InsertNode;
                    LinkQuene->size++;
                    return OK;
                }
                iterator = iterator->next;
            }
            if (iterator->next == NULL) {
                iterator->next = InsertNode;
                InsertNode->next = NULL;
                LinkQuene->size++;
                return OK;
            }
            
        }
        
    }
    

    return OK;
}


//��ͷɾ�����ݣ��������ݸ�ֵvar��Status����״̬��
Status DeleteQueneNode(PQuene LinkQuene, ElementType *var){
    if (!LinkQuene->size) {
        printf("������Ϊ��\n");
        return ERROR;
    }
    else
    {
        PNode p = (PNode)malloc(sizeof(Node));
        p = LinkQuene->PFront->next;
        *var = p->data;
        LinkQuene->PFront->next = p->next;
        if (LinkQuene->PRear == p) {
            LinkQuene->PRear = LinkQuene->PFront;
        }
        free(p);
        LinkQuene->size--;
        return OK;
    }
    
    return OK;

}

//ɾ����������
Status DeleteQuene(PQuene LinkQuene){

    assert(LinkQuene);

    while(LinkQuene->PFront){
        LinkQuene->PRear = LinkQuene->PFront->next;
        free(LinkQuene->PRear);
        LinkQuene->PFront = LinkQuene->PRear;
    }
    
    return ERROR;
}

