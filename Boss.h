#pragma once
#include"Worker.h"

class Boss :public Worker
{
public:
	Boss(int id, string name, int dId);

	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ����
	string getDeptName();
};