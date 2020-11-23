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
	//遍历链表，找到第index个结点
	while (ptr != nullptr && counter < index)
	{
		ptr = ptr->next;
		counter++;
	}
	if (ptr == nullptr)
		cout << "		插入位置非法！" << endl;
	//插入指定值结点
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
	//遍历链表，找到第index-1个结点
	while (ptr != nullptr && counter < index)
	{
		ptr = ptr->next;
		counter++;
	}
	if (ptr == nullptr)
		cout << "		删除位置非法！" << endl;
	//删除指定值结点
	else
	{
		Node* temp = ptr->next;
		int value_temp = temp->data;
		ptr->next = temp->next;
		delete temp;
		return value_temp;
	}
}

//搜索函数，参数为待搜索元素的值，返回值为该元素的位置(从零计数)(若未能搜索到该值则返回-1)
int LinkedList::Locate(int value)
{
	Node* ptr = first;
	int counter = 0;
	//遍历链表，找到值为value的结点
	while (ptr != nullptr)
	{
		if (ptr->data == value) return counter;
		ptr = ptr->next;
		counter++;
	}
	return -1;
}

//长度函数，返回值为该表长度
int LinkedList::GetLength()
{
	Node* ptr = first;
	int counter = 0;
	//当ptr不为空指针时遍历链表，每次循环计数器自加
	while (ptr != nullptr)
	{
		ptr = ptr->next;
		counter++;
	}
	return counter;
}

//打印链表的内容
void LinkedList::PrintList()
{
	Node* ptr = first->next;
	cout << "[";
	//当ptr不为空指针时遍历链表，输出其内容
	while (ptr != nullptr)
	{
		cout << ptr->data;
		if (ptr->next != nullptr)cout << ", ";
		ptr = ptr->next;
	}
	cout << "]";
}