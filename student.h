#pragma once
#include"identity.h"

class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вΣ�������ѧ�š����룩
	Student(int stuId, std::string name, std::string password);

	//�˵�
	virtual void openMenu();

	//��ȡԤԼ��Ϣ(ԤԼ��ϢĬ����ѧ��ѧ����������)
	std::vector<Order> loadOrderFile();

	//д��ԤԼ
	void writeBackOrder(std::vector<Order>& vOrder);

	//��һ�»���
	std::vector<ComputerRoom> loadCompRoom();

	//����ԤԼ
	void applyDetail(int week, int day, int comp);

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//����ظ�ԤԼ
	bool orderIsExist(std::vector<Order> &vSunOrder,Order &od);

	//�ַ�������
	std::string getTimeStr(int week, int day);
	std::string getInfoStr(int info);

};