#pragma once
#include "List.h"

const int MaxSize = 10;//线性表的最大长度

class SeqList:public List
{
private:
	int data[MaxSize];
	int length;//线性表长度
public:
	SeqList() { length = 0; }//无参构造函数，构造长度为零的顺序表
	SeqList(int source[], int length);//有参构造函数，参数为源数组以及源数组取样长度
	void Insert(int index,int value);//插入函数，参数为插入位置和插入值
	int Delete(int index);//删除函数，参数为待删除元素的下标，返回值为被删除元素值
	int Locate(int value);//搜索函数，参数为待搜索元素的值，返回值为该元素的下标(若未能搜索到该值则返回-1)
	int GetLength();//长度函数，返回值为该表长度
	void PrintList();//打印线性表的内容
};