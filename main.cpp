#include <iostream>
#include "SeqList.h"
using namespace std;

int main()
{
	SeqList* seqlist = nullptr;

	//循环执行以下do-while部分，除非用户推出程序
	bool exit_flag = 0;
	do
	{
		int input;

		//输入并检测输入合法性 
		int error_flag = 0;
		do
		{
			cout << "选择将要进行的操作(输入对应序号)(可输入-1获取帮助)：";
			cin >> input;

			switch (input)
			{

			case -1://输出帮助
			{
				cout << "0.退出程序" << endl << "1.创建空顺序表" << endl << "2.以自定义数组创建顺序表" << endl << "3.对顺序表执行插入操作" << endl << "4.对顺序表执行删除操作" << endl << "5.对顺序表执行搜索操作" << endl << "6.获取顺序表的长度" << endl << "7.按顺序输出顺序表的内容" << endl;
				break;
			}

			case 0:case 1:case 2:break;

			case 3:case 4:case 5:case 6:case 7:
			{
				//判断seqlist指针是否为空，为空则不允许对指向的对象进行操作
				if (seqlist == nullptr)
				{
					cout << "请先创建顺序表！" << endl;
					error_flag = 1;
				}
				break;
			}

			default://用户输入不属于上述任意选项时，将error_flag置1并输出提示语句，重新开始循环
				cout << "输入非法！" << endl;
				error_flag = 1;
				break;

			}

		} while (error_flag == 1);

		//执行对应命令

		switch (input)
		{

		case 0://退出程序
		{
			exit_flag = 1;
			break;
		}

		case 1://创建空顺序表
		{
			seqlist = new SeqList();
			cout << "	已创建空序列表" << endl;
			break;
		}

		case 2://以自定义数组创建顺序表
		{
			int sourcelist[] = { 0, 1, 2, 3, 4, 5, 6 };
			cout << "	已创建数组：[0, 1, 2, 3, 4, 5, 6]" << endl;
			seqlist = new SeqList(sourcelist, 7);
			cout << "	已以如上数组创建顺序表。" << endl;
			break;
		}

		case 3://对指定顺序表执行插入操作
		{
			int index;
			int value;
			cout << "	请输入插入元素值：";
			cin >> value;
			cout << "	请输入插入位置(下标)：";
			cin >> index;
			seqlist->Insert(index, value);
			cout << "	已插入指定元素。" << endl;
			break;
		}

		case 4://对指定顺序表执行删除操作
		{
			int index;
			cout << "	请输入待删除元素位置(下标)：";
			cin >> index;
			int deleted = seqlist->Delete(index);
			cout << "	已删除下标为" << index << "的元素，其值为：" << deleted << endl;
			break;
		}

		case 5://对指定顺序表执行搜索操作
		{
			int value;
			cout << "	请输入待搜索值：";
			cin >> value;
			int index = seqlist->Locate(value);
			if (index == -1)
				cout << "	未查找到指定元素。" << endl;
			else
				cout << "	已查找到指定元素，其下标为：" << index << endl;
			break;
		}

		case 6://获取指定顺序表的长度
		{
			cout << "	该顺序表的长度为：" << seqlist->GetLength() << endl;
			break;
		}

		case 7://按顺序输出指定顺序表的内容
		{
			cout << "	该顺序表的内容为：" << endl;
			cout << "	";
			seqlist->PrintList();
			cout << endl;
			break;
		}
		}
	} while (!exit_flag);
	cout << "程序已正常退出。" << endl;
}