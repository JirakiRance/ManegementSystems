#pragma once
#include"Worker.h"

class Employee :public Worker
{
public:
	Employee(int id, string name, int dId);

	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ����
	string getDeptName();
};