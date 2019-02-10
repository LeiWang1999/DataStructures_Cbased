// System : Win10
// Compiler : gcc with Vscode
// author : princeling

#include <stdio.h>

void hanio(int n, char x, char y ,char z);

static int count = 0;

int main(int argc, char const *argv[])
{
    int depth;
    printf("�����뺺ŵ���Ĳ���:");
    scanf("%d",&depth);
    hanio(depth,'x','y','z');
    printf("һ��ִ����%d��\n",count);
    return 0;
}



/*
-----��һ������Ϊ��Ҫ�ƶ��Ŀ���,�ڶ�������Ϊ��ʼ����,���ĸ�����ΪĿ������
# hanoi
# �ƶ���n��Բ�̵�z��������Ҫ��ǰn-1��Բ�̴�x���ƶ���y����
# ���ƶ�n-1��Բ�̵�y����ʱ����Ҫ��z������y��
# �ƶ�n-1��Բ�̵�y������Ҫ�ƶ�n-2��Բ�̴�x���ƶ���z��
# �ƶ�n-2��Բ�̵�z������Ҫ�ƶ�n-3��Բ�̴�x���ƶ���y��
# .........
# �ƶ�2��Բ�̵�Ŀ������������������Ҫ�ƶ�1��Բ�̴�x���ƶ����м���
# �ƶ�һ��Բ�̵�Ŀ������������������Ҫx�� -> Ŀ����
# �����Ҫ��y����Ϊ��ʼ����x��Ϊ�м�����z��ΪĿ����
*/
void hanio(int n, char x, char y ,char z){
    if (n == 1) {
        printf("%c->%c\n",x,z);  // �� ���һ������ �ƹ�ȥ
        count++;
    }
    else
    {   count++;
        hanio(n-1,x,z,y);      // ��n-1�������ƶ��� y
        printf("%c->%c\n",x,z); // �� ��n�������ƶ��� z
        hanio(n-1,y,x,z);   //�� n-1�������ƶ����� z��
    }
}