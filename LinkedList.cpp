#include <iostream>
#include "LinkedList.h"
using namespace std;

//无参构造函数，建立仅有头结点的空链表
LinkedList::LinkedList()
{
	first = new Node;
	first->next = nullptr;
}

//有参构造函数，参数为源数组以及源数组取样长度
LinkedList::LinkedList(int source[], int length)
{
	Node* ptr;
	first = new Node;
	ptr = first;
	//将源数组的元素置入链表
	for (int index = 0; index < length; index++)
	{
		Node* temp;
		temp = new Node;
		temp->data = source[index];
		ptr->next = temp;
		ptr = temp;
	}
	ptr->next = nullptr;//链表最后一个结点的指针为空指针
}

//析构函数
LinkedList::~LinkedList()
{
	Node* ptr;
	//遍历链表，删除链表第一个元素，直到链表为空
	while (first != nullptr)
	{
		ptr = first;
		first = first->next;
		delete ptr;
	}
}

//插入函数，参数为插入位置(从0计数)和插入值
void LinkedList::Insert(int index, int value)
{
	Node* ptr = first;
	int counter = 0;
	//遍历链表，找到第index个节点
	while (ptr != nullptr && counter < index)
	{
		ptr = ptr->next;
		counter++;
	}
	if (ptr == nullptr)throw "插入位置非法！";
	//插入指定值
	else
	{
		Node* temp = new Node;
		temp->data = value;
		temp->next = ptr->next;
		ptr->next = temp;
	}
}

//删除函数，参数为待删除元素的位置(从0计数)，返回值为被删除元素值
int LinkedList::Delete(int index)
{
	Node* ptr = first;
	int counter = 0;
	//遍历链表，找到第index个节点
	while (ptr != nullptr && counter < index)
	{
		ptr = ptr->next;
		counter++;
	}
	if (ptr == nullptr)throw "删除位置非法！";
	//插入指定值
	else
	{
		Node* temp = ptr->next;
	}
}