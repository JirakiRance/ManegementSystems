#pragma once
#include"Worker.h"

class Maneger :public Worker
{
public:
	Maneger(int id, string name, int dId);

	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ����
	string getDeptName();
};
