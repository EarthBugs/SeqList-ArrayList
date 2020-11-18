#pragma once
#include "List.h"

struct Node
{
	int data;
	Node* next;
};

class LinkedList: public List
{
private:
	Node* first;//ͷ���
public:
	LinkedList();//�޲ι��캯������������ͷ���Ŀ�����
	LinkedList(int source[], int length);//�вι��캯��������ΪԴ�����Լ�Դ����ȡ������
	~LinkedList();//��������
	void Insert(int index, int value);//���뺯��������Ϊ����λ��(��0����)�Ͳ���ֵ
	int Delete(int index);//ɾ������������Ϊ��ɾ��Ԫ�ص�λ��(��0����)������ֵΪ��ɾ��Ԫ��ֵ
	int Locate(int value);//��������������Ϊ������Ԫ�ص�ֵ������ֵΪ��Ԫh�ص�λ��(�������)(��δ����������ֵ�򷵻�-1)
	int GetLength();//���Ⱥ���������ֵΪ�ñ���
	void PrintList();//��ӡ���������
};