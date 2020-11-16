#include <iostream>
#include "SeqList.h"
using namespace std;

int main()
{
	SeqList* seqlist = nullptr;

	//ѭ��ִ������do-while���֣������û��Ƴ�����
	bool exit_flag = 0;
	do
	{
		int input;

		//���벢�������Ϸ��� 
		int error_flag = 0;
		do
		{
			cout << "ѡ��Ҫ���еĲ���(�����Ӧ���)(������-1��ȡ����)��";
			cin >> input;

			switch (input)
			{

			case -1://�������
			{
				cout << "0.�˳�����" << endl << "1.������˳���" << endl << "2.���Զ������鴴��˳���" << endl << "3.��˳���ִ�в������" << endl << "4.��˳���ִ��ɾ������" << endl << "5.��˳���ִ����������" << endl << "6.��ȡ˳���ĳ���" << endl << "7.��˳�����˳��������" << endl;
				break;
			}

			case 0:case 1:case 2:break;

			case 3:case 4:case 5:case 6:case 7:
			{
				//�ж�seqlistָ���Ƿ�Ϊ�գ�Ϊ���������ָ��Ķ�����в���
				if (seqlist == nullptr)
				{
					cout << "���ȴ���˳���" << endl;
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

		case 0://�˳�����
		{
			exit_flag = 1;
			break;
		}

		case 1://������˳���
		{
			seqlist = new SeqList();
			cout << "	�Ѵ��������б�" << endl;
			break;
		}

		case 2://���Զ������鴴��˳���
		{
			int sourcelist[] = { 0, 1, 2, 3, 4, 5, 6 };
			cout << "	�Ѵ������飺[0, 1, 2, 3, 4, 5, 6]" << endl;
			seqlist = new SeqList(sourcelist, 7);
			cout << "	�����������鴴��˳���" << endl;
			break;
		}

		case 3://��ָ��˳���ִ�в������
		{
			int index;
			int value;
			cout << "	���������Ԫ��ֵ��";
			cin >> value;
			cout << "	���������λ��(�±�)��";
			cin >> index;
			seqlist->Insert(index, value);
			cout << "	�Ѳ���ָ��Ԫ�ء�" << endl;
			break;
		}

		case 4://��ָ��˳���ִ��ɾ������
		{
			int index;
			cout << "	�������ɾ��Ԫ��λ��(�±�)��";
			cin >> index;
			int deleted = seqlist->Delete(index);
			cout << "	��ɾ���±�Ϊ" << index << "��Ԫ�أ���ֵΪ��" << deleted << endl;
			break;
		}

		case 5://��ָ��˳���ִ����������
		{
			int value;
			cout << "	�����������ֵ��";
			cin >> value;
			int index = seqlist->Locate(value);
			if (index == -1)
				cout << "	δ���ҵ�ָ��Ԫ�ء�" << endl;
			else
				cout << "	�Ѳ��ҵ�ָ��Ԫ�أ����±�Ϊ��" << index << endl;
			break;
		}

		case 6://��ȡָ��˳���ĳ���
		{
			cout << "	��˳���ĳ���Ϊ��" << seqlist->GetLength() << endl;
			break;
		}

		case 7://��˳�����ָ��˳��������
		{
			cout << "	��˳��������Ϊ��" << endl;
			cout << "	";
			seqlist->PrintList();
			cout << endl;
			break;
		}
		}
	} while (!exit_flag);
	cout << "�����������˳���" << endl;
}