#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

#define MAX_POS_X 8
#define MAX_POS_Y 8

typedef int Status;
int solution_count = 0;


// ��ʼ������
Status InitChess(int pos[][MAX_POS_Y]);

// �������귶Χ��0-7 �Ὣ������Χ���1,���ӱ��2
Status SetChess(int pos[][MAX_POS_Y], int pos_x, int pos_y);

Status ShowChess(int pos[][MAX_POS_Y]);

Status TestChess(int pos[][MAX_POS_Y], int pos_x, int pos_y);

Status ClearChess(int pos[][MAX_POS_Y]);


int main(int argc, char const *argv[])
{
    int pos[MAX_POS_X][MAX_POS_Y];
    InitChess(pos);    // ��ʼ������
//    SetChess(pos,3,4);
    TestChess(pos,0,8);
//    ShowChess(pos);
    return 0;
}



Status InitChess(int pos[][MAX_POS_Y]){
    for(size_t i = 0; i < MAX_POS_Y; i++)
    {
        for(size_t j = 0; j < MAX_POS_Y; j++)
        {
            pos[i][j] = 0;
        }
        
    }
    return OK;
}

Status SetChess(int pos[][MAX_POS_Y], int pos_x, int pos_y){
    if (pos_x>=MAX_POS_Y || pos_y >=MAX_POS_Y || pos_x < 0 || pos_y < 0) {
        printf("��������겻�ڷ�Χ��\n");
        return ERROR;
    }

    pos[pos_x][pos_y] = 2;

    for(size_t i = 0; i < MAX_POS_X; i++)
    {
        if(pos[pos_x][i] != 2) pos[pos_x][i] = 1;
        if(pos[i][pos_y] != 2) pos[i][pos_y] = 1;        
    }
    
    for(int i = -7; i < MAX_POS_X; i++){  
        if(pos_x+i<8 && pos_y+i <8 && pos_x+i >=0 && pos_y+i >=0 && pos[pos_x+i][pos_y+i]!=2)
        pos[pos_x+i][pos_y+i] = 1;
    }

    // i,i i+1,i-1
    for(int i = -7; i < MAX_POS_X; i++){  
        if(pos_x+i<8 && pos_y-i <8 && pos_x+i >=0 && pos_y-i >=0 && pos[pos_x+i][pos_y-i]!=2)
        pos[pos_x+i][pos_y-i] = 1;
    }
    

    return OK;
}

Status ShowChess(int pos[][MAX_POS_Y]){
    printf("  ");
    for(size_t i = 0; i < 8; i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    
    for(size_t i = 0; i < MAX_POS_Y; i++)
    {
        printf("%d ",i);
        for(size_t j = 0; j < MAX_POS_X; j++)
        {
            printf("%d ", pos[i][j]);
        }
        printf("\n");
    }
    
}

// ��������
Status ClearChess(int pos[][MAX_POS_Y]){
    int count = MAX_POS_X;
    for(size_t i = 0; i < count; i++)
    {
        for(size_t j = 0; j < count; j++)
        {
            pos[i][j] = 0;
        }
        
    }
    return OK;
}   

Status CopyChess(int chess_copy[][MAX_POS_Y], int chess_copied[][MAX_POS_Y]){
    for(size_t i = 0; i < MAX_POS_X; i++)
    {
        for(size_t j = 0; j < MAX_POS_Y; j++)
        {
            chess_copy[i][j] = chess_copied[i][j];
        }
    
    }
    return OK;
}

/*
    �ݹ�:
    1. �ݹ������չ�
*/
Status TestChess(int pos[][MAX_POS_Y], int pos_x, int pos_y){

    int chess [MAX_POS_X][MAX_POS_Y];
//    ShowChess(pos);
    if(!CopyChess(chess, pos))
    {
        return ERROR;
    }


    if (pos_x == MAX_POS_X) {
        solution_count++;
        printf("���ǵ�%d�ֽⷨ\n",solution_count);
        ShowChess(chess);
    }
    else
    {
        for(size_t i = 0; i < pos_y; i++)
        {
            if (!pos[pos_x][i]) {
                SetChess(chess,pos_x,i);
                TestChess(chess, pos_x+1, pos_y);   
            }

        }
        
    }
    

    return OK;
}