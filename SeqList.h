#pragma once
#include "List.h"

const int MaxSize = 10;//���Ա����󳤶�

class SeqList:public List
{
private:
	int data[MaxSize];
	int length;//���Ա���
public:
	SeqList() { length = 0; }//�޲ι��캯�������쳤��Ϊ���˳���
	SeqList(int source[], int length);//�вι��캯��������ΪԴ�����Լ�Դ����ȡ������
	void Insert(int index,int value);//���뺯��������Ϊ����λ�úͲ���ֵ
	int Delete(int index);//ɾ������������Ϊ��ɾ��Ԫ�ص��±꣬����ֵΪ��ɾ��Ԫ��ֵ
	int Locate(int value);//��������������Ϊ������Ԫ�ص�ֵ������ֵΪ��Ԫ�ص��±�(��δ����������ֵ�򷵻�-1)
	int GetLength();//���Ⱥ���������ֵΪ�ñ���
	void PrintList();//��ӡ���Ա������
};