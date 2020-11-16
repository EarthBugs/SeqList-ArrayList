#include <iostream>
#include "SeqList.h"
using namespace std;

//�вι��캯��������ΪԴ�����Լ�Դ����ȡ������
SeqList::SeqList(int source[], int length)
{
	if (length > MaxSize) throw "Դ�������";//�����������ĳ����Ƿ����˳�����󳤶�
	//����Դ���飬��ǰȡ�����ȸ�ֵ����˳���
	for (int index = 0; index < length; index++)
		data[index] = source[index];
	this->length = length;//�������lengthֵ���豾����
}

//���뺯��������Ϊ����λ�úͲ���ֵ
void SeqList::Insert(int index, int value)
{
	if (length >= MaxSize) throw "����(����󳤶ȴ���˳�����󳤶�)";//������󳤶��Ƿ����˳�����󳤶�
	if (index < 0 || index > length + 1)throw "����λ�÷Ƿ�(С��0����ڳ���)";
	//����˳�����index�����Ԫ�غ���
	for (int j = length; j > index; j--)
		data[j] = data[j - 1];
	data[index] = value;
	length++;
}

//ɾ������������Ϊ��ɾ��Ԫ�ص��±꣬����ֵΪ��ɾ��Ԫ��ֵ
int SeqList::Delete(int index)
{
	if (length == 0)throw "����(˳���Ϊ��)";//����Ƿ��ǿձ�
	if (index < 0 || index >= length)throw "ɾ��λ�÷Ƿ�(С��0����ڳ���)";
	int temp = data[index];//�����ɾ������
	//���ֱ�����ǰ˳�����index�����ı���ǰ��
	for (int j = index + 1; j < length; j++)
		data[j - 1] = data[j];
	length--;
	return temp;
}

//��������������Ϊ������Ԫ�ص�ֵ������ֵΪ��Ԫ�ص��±�(��δ����������ֵ�򷵻�-1)
int SeqList::Locate(int value)
{
	//������ǰ˳����ҳ��Ƿ����valueԪ��
	for (int index = 0; index < length; index++)
		if (data[index] == value)return index;
	return -1;
}

//����˳������±���С��NULL
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

//���Ⱥ���������ֵΪ�ñ���
int SeqList::GetLength()
{
	return length;
}

//��ӡ���Ա������
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