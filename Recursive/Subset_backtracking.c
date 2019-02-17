// �������� ������ϵ������Ӽ�

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;


char * init_set(int size);

Status show_subset(int i, int size, char * set);


int main(int argc, char const *argv[])
{
    int size = 0;
    printf("�����뼯�ϵĳ���:");
    scanf("%d",&size);
    char* set = init_set(size);
    printf("�Ӽ�Ϊ:\n");
    show_subset(0,size,set);
    return 0;
}

char * init_set(int size){
    char * set = (char *)malloc(sizeof(char)*size);
    printf("�������ڳ�ʼ��....\n");
    for(size_t i = 0; i < size; i++)
    {
        set[i] = i;
    }
    printf("���ϵ�����Ϊ:{");
    for(size_t i = 0; i < size; i++)
    {
        printf("%d,",set[i]);
    }
    printf("\b}\n");
    return set;
}

Status show_subset(int i, int size, char* set){
    // ֻ��Ҫ��ӡ������λ���±�
    if(i==size){
        printf("{");
        for(size_t i = 0; i < size; i++)
        {
            if(set[i])
            printf("%d,",i);
        }
        printf("}\n");
    }
    else{
        set[i] = 1;
        show_subset(i+1,size,set);
        set[i] = 0;
        show_subset(i+1,size,set);
    }
}