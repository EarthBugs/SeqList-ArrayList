#include <iostream>
#include "SeqList.h"
using namespace std;

//有参构造函数，参数为源数组以及源数组取样长度
SeqList::SeqList(int source[], int length)
{
	if (length > MaxSize) throw "源数组过长";//检测输入数组的长度是否大于顺序表最大长度
	//遍历源数组，将前取样长度个值置入顺序表
	for (int index = 0; index < length; index++)
		data[index] = source[index];
	this->length = length;//将传入的length值赋予本对象
}

//插入函数，参数为插入位置和插入值
void SeqList::Insert(int index, int value)
{
	if (length >= MaxSize) throw "上溢(插入后长度大于顺序表最大长度)";//检测插入后长度是否大于顺序表最大长度
	if (index < 0 || index > length + 1)throw "插入位置非法(小于0或大于长度)";
	//遍历顺序表，将index及其后元素后移
	for (int j = length; j > index; j--)
		data[j] = data[j - 1];
	data[index] = value;
	length++;
}

//删除函数，参数为待删除元素的下标，返回值为被删除元素值
int SeqList::Delete(int index)
{
	if (length == 0)throw "下溢(顺序表为空)";//检测是否是空表
	if (index < 0 || index >= length)throw "删除位置非法(小于0或大于长度)";
	int temp = data[index];//缓存待删除变量
	//部分遍历当前顺序表，将index及其后的变量前移
	for (int j = index + 1; j < length; j++)
		data[j - 1] = data[j];
	length--;
	return temp;
}

//搜索函数，参数为待搜索元素的值，返回值为该元素的下标(若未能搜索到该值则返回-1)
int SeqList::Locate(int value)
{
	//遍历当前顺序表，找出是否包含value元素
	for (int index = 0; index < length; index++)
		if (data[index] == value)return index;
	return -1;
}

//查找顺序表中下标最小的NULL
int SeqList::GetFirstNullIndex()
{
	if (length == 0)
		return 0;
	for (int index = 0; index < length; index++)
	{
		if (data[index] != NULL)
			return index;
	}
}

//长度函数，返回值为该表长度
int SeqList::GetLength()
{
	return length;
}

//打印线性表的内容
void SeqList::PrintList()
{
	cout << "[";
	for (int index = 0; index < length; index++)
	{
		cout << data[index];
		if ((index + 1) != NULL)
			cout << ", ";
	}
	cout << "]";
}