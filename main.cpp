#include <iostream>
#include "SeqList.h"
#include "LinkedList.h"
using namespace std;

int main()
{
	List* list = nullptr;

	//ѭ��ִ������do-while���֣������û��Ƴ�����
	bool exit_flag = 0;
	do
	{
		int input;

		//���벢�������Ϸ��� 
		int error_flag = 0;
		do
		{
			cout << "ѡ��Ҫ���еĲ���(�����Ӧ���)(������0��ȡ����)��";
			cin >> input;

			switch (input)
			{

			case 0://�������
			{
				cout << "1.�˳�����\n2.������˳���\n3.���Զ������鴴��˳���\n4.����������\n5.���Զ������鴴������\n6.�Ա�ִ�в������\n7.�Ա�ִ��ɾ������\n8.�Ա�ִ����������\n9.��ȡ��ĳ���\n10.��˳������������" << endl;
				break;
			}

			case 1:case 2:case 3:case 4:case 5:break;

			case 6:case 7:case 8:case 9:case 10:
			{
				//�ж�seqlistָ���Ƿ�Ϊ�գ�Ϊ���������ָ��Ķ�����в���
				if (list == nullptr)
				{
					cout << "���ȴ�����" << endl;
					error_flag = 1;
				}
				break;
			}

			default://�û����벻������������ѡ��ʱ����error_flag��1�������ʾ��䣬���¿�ʼѭ��
				cout << "����Ƿ���" << endl;
				error_flag = 1;
				break;

			}

		} while (error_flag == 1);

		//ִ�ж�Ӧ����
		switch (input)
		{

		case 1://�˳�����
		{
			exit_flag = 1;
			break;
		}

		case 2://������˳���
		{
			list = new SeqList();
			cout << "	�Ѵ��������б�" << endl;
			break;
		}

		case 3://���Զ������鴴��˳���
		{
			int sourcelist[] = { 0, 1, 2, 3, 4, 5, 6 };
			cout << "	�Ѵ������飺[0, 1, 2, 3, 4, 5, 6]" << endl;
			list = new SeqList(sourcelist, 7);
			cout << "	�����������鴴��˳���" << endl;
			break;
		}

		case 4://����������
		{
			list = new LinkedList();
			cout << "	�Ѵ���������" << endl;
			break;
		}

		case 5://���Զ������鴴������
		{
			int sourcelist[] = { 0, 1, 2, 3, 4, 5, 6 };
			cout << "	�Ѵ������飺[0, 1, 2, 3, 4, 5, 6]" << endl;
			list = new LinkedList(sourcelist, 7);
			cout << "	�����������鴴������" << endl;
			break;
		}

		case 6://��ָ����ִ�в������
		{
			int index;
			int value;
			cout << "	���������Ԫ��ֵ��";
			cin >> value;
			cout << "	���������λ��(�±�)��";
			cin >> index;
			list->Insert(index, value);
			cout << "	�Ѳ���ָ��Ԫ�ء�" << endl;
			break;
		}

		case 7://��ָ����ִ��ɾ������
		{
			int index;
			cout << "	�������ɾ��Ԫ��λ��(�±�)��";
			cin >> index;
			int deleted = list->Delete(index);
			cout << "	��ɾ���±�Ϊ" << index << "��Ԫ�أ���ֵΪ��" << deleted << endl;
			break;
		}

		case 8://��ָ����ִ����������
		{
			int value;
			cout << "	�����������ֵ��";
			cin >> value;
			int index = list->Locate(value);
			if (index == -1)
				cout << "	δ���ҵ�ָ��Ԫ�ء�" << endl;
			else
				cout << "	�Ѳ��ҵ�ָ��Ԫ�أ����±�Ϊ��" << index << endl;
			break;
		}

		case 9://��ȡָ����ĳ���
		{
			cout << "	��˳���ĳ���Ϊ��" << list->GetLength() << endl;
			break;
		}

		case 10://��˳�����ָ���������
		{
			cout << "	��˳��������Ϊ��" << endl;
			cout << "	";
			list->PrintList();
			cout << endl;
			break;
		}
		}
	} while (!exit_flag);
	cout << "�����������˳���" << endl;
}