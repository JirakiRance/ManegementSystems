#pragma once
#include"identity.h"

class Teacher :public Identity
{
public:

	//Ĭ�Ϲ���
	Teacher();
	//�вι���(ְ���š�����������)
	Teacher(int empId, std::string name, std::string pwd);

	//�˵�
	virtual void openMenu();

	//��ȡԤԼ��Ϣ(ԤԼ��ϢĬ����ѧ��ѧ����������)
	std::vector<Order> loadOrderFile();

	//д��ԤԼ
	void writeBackOrder(std::vector<Order>& vOrder);

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//�ַ�������
	std::string getTimeStr(int week, int day);
	std::string getInfoStr(int info);
};