#include <iostream>
#include "LinkedList.h"
using namespace std;

//�޲ι��캯������������ͷ���Ŀ�����
LinkedList::LinkedList()
{
	first = new Node;
	first->next = nullptr;
}

//�вι��캯��������ΪԴ�����Լ�Դ����ȡ������
LinkedList::LinkedList(int source[], int length)
{
	Node* ptr;
	first = new Node;
	ptr = first;
	//��Դ�����Ԫ����������
	for (int index = 0; index < length; index++)
	{
		Node* temp;
		temp = new Node;
		temp->data = source[index];
		ptr->next = temp;
		ptr = temp;
	}
	ptr->next = nullptr;//�������һ������ָ��Ϊ��ָ��
}

//��������
LinkedList::~LinkedList()
{
	Node* ptr;
	//��������ɾ�������һ��Ԫ�أ�ֱ������Ϊ��
	while (first != nullptr)
	{
		ptr = first;
		first = first->next;
		delete ptr;
	}
}

//���뺯��������Ϊ����λ��(��0����)�Ͳ���ֵ
void LinkedList::Insert(int index, int value)
{
	Node* ptr = first;
	int counter = 0;
	//���������ҵ���index���ڵ�
	while (ptr != nullptr && counter < index)
	{
		ptr = ptr->next;
		counter++;
	}
	if (ptr == nullptr)throw "����λ�÷Ƿ���";
	//����ָ��ֵ
	else
	{
		Node* temp = new Node;
		temp->data = value;
		temp->next = ptr->next;
		ptr->next = temp;
	}
}

//ɾ������������Ϊ��ɾ��Ԫ�ص�λ��(��0����)������ֵΪ��ɾ��Ԫ��ֵ
int LinkedList::Delete(int index)
{
	Node* ptr = first;
	int counter = 0;
	//���������ҵ���index���ڵ�
	while (ptr != nullptr && counter < index)
	{
		ptr = ptr->next;
		counter++;
	}
	if (ptr == nullptr)throw "ɾ��λ�÷Ƿ���";
	//����ָ��ֵ
	else
	{
		Node* temp = ptr->next;
	}
}