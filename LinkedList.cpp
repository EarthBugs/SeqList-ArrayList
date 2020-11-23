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
	//���������ҵ���index�����
	while (ptr != nullptr && counter < index)
	{
		ptr = ptr->next;
		counter++;
	}
	if (ptr == nullptr)
		cout << "		����λ�÷Ƿ���" << endl;
	//����ָ��ֵ���
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
	//���������ҵ���index-1�����
	while (ptr != nullptr && counter < index)
	{
		ptr = ptr->next;
		counter++;
	}
	if (ptr == nullptr)
		cout << "		ɾ��λ�÷Ƿ���" << endl;
	//ɾ��ָ��ֵ���
	else
	{
		Node* temp = ptr->next;
		int value_temp = temp->data;
		ptr->next = temp->next;
		delete temp;
		return value_temp;
	}
}

//��������������Ϊ������Ԫ�ص�ֵ������ֵΪ��Ԫ�ص�λ��(�������)(��δ����������ֵ�򷵻�-1)
int LinkedList::Locate(int value)
{
	Node* ptr = first;
	int counter = 0;
	//���������ҵ�ֵΪvalue�Ľ��
	while (ptr != nullptr)
	{
		if (ptr->data == value) return counter;
		ptr = ptr->next;
		counter++;
	}
	return -1;
}

//���Ⱥ���������ֵΪ�ñ���
int LinkedList::GetLength()
{
	Node* ptr = first;
	int counter = 0;
	//��ptr��Ϊ��ָ��ʱ��������ÿ��ѭ���������Լ�
	while (ptr != nullptr)
	{
		ptr = ptr->next;
		counter++;
	}
	return counter;
}

//��ӡ���������
void LinkedList::PrintList()
{
	Node* ptr = first->next;
	cout << "[";
	//��ptr��Ϊ��ָ��ʱ�����������������
	while (ptr != nullptr)
	{
		cout << ptr->data;
		if (ptr->next != nullptr)cout << ", ";
		ptr = ptr->next;
	}
	cout << "]";
}