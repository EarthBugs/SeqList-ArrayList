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
	Node* first;//头结点
public:
	LinkedList();//无参构造函数，建立仅有头结点的空链表
	LinkedList(int source[], int length);//有参构造函数，参数为源数组以及源数组取样长度
	~LinkedList();//析构函数
	void Insert(int index, int value);//插入函数，参数为插入位置(从0计数)和插入值
	int Delete(int index);//删除函数，参数为待删除元素的位置(从0计数)，返回值为被删除元素值
	int Locate(int value);//搜索函数，参数为待搜索元素的值，返回值为该元h素的位置(从零计数)(若未能搜索到该值则返回-1)
	int GetLength();//长度函数，返回值为该表长度
	void PrintList();//打印链表的内容
};