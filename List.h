#pragma once

//˳��������ĸ��࣬����ͳһָ��
class List
{
public:
	virtual void Insert(int index, int value) = 0;//���뺯��������Ϊ����λ�úͲ���ֵ
	virtual int Delete(int index) = 0;//ɾ������������Ϊ��ɾ��Ԫ�ص��±꣬����ֵΪ��ɾ��Ԫ��ֵ
	virtual int Locate(int value) = 0;//��������������Ϊ������Ԫ�ص�ֵ������ֵΪ��Ԫ�ص��±�(��δ����������ֵ�򷵻�-1)
	virtual int GetLength() = 0;//���Ⱥ���������ֵΪ�ñ���
	virtual void PrintList() = 0;//��ӡ���Ա������
};		