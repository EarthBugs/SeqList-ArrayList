#pragma once

//顺序表和链表的父类，用于统一指针
class List
{
public:
	virtual void Insert(int index, int value) = 0;//插入函数，参数为插入位置和插入值
	virtual int Delete(int index) = 0;//删除函数，参数为待删除元素的下标，返回值为被删除元素值
	virtual int Locate(int value) = 0;//搜索函数，参数为待搜索元素的值，返回值为该元素的下标(若未能搜索到该值则返回-1)
	virtual int GetLength() = 0;//长度函数，返回值为该表长度
	virtual void PrintList() = 0;//打印线性表的内容
};		