#include <iostream>
#include "SeqList.h"
#include "LinkedList.h"
using namespace std;

int main()
{
	List* list = nullptr;

	//循环执行以下do-while部分，除非用户推出程序
	bool exit_flag = 0;
	do
	{
		int input;

		//输入并检测输入合法性 
		int error_flag = 0;
		do
		{
			cout << "选择将要进行的操作(输入对应序号)(可输入0获取帮助)：";
			cin >> input;

			switch (input)
			{

			case 0://输出帮助
			{
				cout << "1.退出程序\n2.创建空顺序表\n3.以自定义数组创建顺序表\n4.创建空链表\n5.以自定义数组创建链表\n6.对表执行插入操作\n7.对表执行删除操作\n8.对表执行搜索操作\n9.获取表的长度\n10.按顺序输出表的内容" << endl;
				break;
			}

			case 1:case 2:case 3:case 4:case 5:break;

			case 6:case 7:case 8:case 9:case 10:
			{
				//判断seqlist指针是否为空，为空则不允许对指向的对象进行操作
				if (list == nullptr)
				{
					cout << "请先创建表！" << endl;
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

		case 1://退出程序
		{
			exit_flag = 1;
			break;
		}

		case 2://创建空顺序表
		{
			list = new SeqList();
			cout << "	已创建空序列表" << endl;
			break;
		}

		case 3://以自定义数组创建顺序表
		{
			int sourcelist[] = { 0, 1, 2, 3, 4, 5, 6 };
			cout << "	已创建数组：[0, 1, 2, 3, 4, 5, 6]" << endl;
			list = new SeqList(sourcelist, 7);
			cout << "	已以如上数组创建顺序表。" << endl;
			break;
		}

		case 4://创建空链表
		{
			list = new LinkedList();
			cout << "	已创建空链表。" << endl;
			break;
		}

		case 5://以自定义数组创建链表
		{
			int sourcelist[] = { 0, 1, 2, 3, 4, 5, 6 };
			cout << "	已创建数组：[0, 1, 2, 3, 4, 5, 6]" << endl;
			list = new LinkedList(sourcelist, 7);
			cout << "	已以如上数组创建链表。" << endl;
			break;
		}

		case 6://对指定表执行插入操作
		{
			int index;
			int value;
			cout << "	请输入插入元素值：";
			cin >> value;
			cout << "	请输入插入位置(下标)：";
			cin >> index;
			list->Insert(index, value);
			cout << "	已插入指定元素。" << endl;
			break;
		}

		case 7://对指定表执行删除操作
		{
			int index;
			cout << "	请输入待删除元素位置(下标)：";
			cin >> index;
			int deleted = list->Delete(index);
			cout << "	已删除下标为" << index << "的元素，其值为：" << deleted << endl;
			break;
		}

		case 8://对指定表执行搜索操作
		{
			int value;
			cout << "	请输入待搜索值：";
			cin >> value;
			int index = list->Locate(value);
			if (index == -1)
				cout << "	未查找到指定元素。" << endl;
			else
				cout << "	已查找到指定元素，其下标为：" << index << endl;
			break;
		}

		case 9://获取指定表的长度
		{
			cout << "	该顺序表的长度为：" << list->GetLength() << endl;
			break;
		}

		case 10://按顺序输出指定表的内容
		{
			cout << "	该顺序表的内容为：" << endl;
			cout << "	";
			list->PrintList();
			cout << endl;
			break;
		}
		}
	} while (!exit_flag);
	cout << "程序已正常退出。" << endl;
}