#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

#define MAX_STRLENTH 255


typedef int Status;
typedef char* String;

int* KMP_Next(String Matched, int Matched_lenth);
int KMP_Select(String SelString, int SelString_lenth, String Matched, int Matched_lenth, int * Next);

int main(int argc, char const *argv[])
{
    char *Matched = (char *)malloc(sizeof(char)*MAX_STRLENTH);
    char *SelString = (char *)malloc(sizeof(char)*MAX_STRLENTH);
    printf("������ԭʼ�ַ���:");
    scanf("%s",SelString);
    printf("������ƥ����ַ���:");
    scanf("%s",Matched);

    printf("��ʼ��ѯ\nԭʼ�ַ���Ϊ:%s\n�����ַ���Ϊ:%s\n",SelString,Matched);

    int Matched_lenth = strlen(Matched);
    int *Next = KMP_Next(Matched, Matched_lenth);

    int location = KMP_Select(SelString, strlen(SelString), Matched, strlen(Matched), Next);

    if(location)
    printf("����ƥ����ַ�����ԭ�ַ����ĵ�%d��\n", location);
    else printf("û����Ҫƥ����ַ����أ�\n");
    

    free(Next);
    return 0;
}



// ����KMP��Next����
int* KMP_Next(String Matched, int Matched_lenth){
    int *Next = (int*)malloc(sizeof(int)*(Matched_lenth));
    int j = 0;  //ǰ׺
    int i = 1;  //��׺


    Next[0] = 0;

    while((Matched_lenth - 1)){
    // ���ƥ���˾�ǰ׺��׺������,����ֵ,���==�ַ�������,��Next�����������
    if (Matched[i] == Matched[j]) {
        j++;
        Next[i] = j;
        i++;
    }
    else
    {   //  ���Matched[i] != Matched[j]
        if (j == 0) {
            Next[i] = 0;
            i++;
        }
        else
        {
            j = Next[j-1];
        }
           
    }
    if (i == Matched_lenth) {
        break;
    }
    
    }
    return Next;
}


int KMP_Select(String SelString, int SelString_lenth, String Matched, int Matched_lenth, int * Next){
    int i = 0; //selstring index
    int j = 0; //matched index
    while(TRUE){
        if (SelString[i]==Matched[j]) { // if done match next
            i++;
            j++;
            if (j == Matched_lenth ){ 
                printf("ƥ��ɹ�\n");
                return i-Matched_lenth;
            }
        }
        else    // if failed . Next
        {   
            j = Next[j];
        }
        if (i == SelString_lenth) {
            return 0;
        }
        

    }
    return i-Matched_lenth;
}

