#pragma once
#include<iostream>
using namespace std;
#include<string>

//ְ��������
class Worker
{
	friend class WorkerManeger;
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

protected:
	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//���ڲ��ű��
};

