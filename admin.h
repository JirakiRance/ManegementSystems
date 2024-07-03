#pragma once
#include"identity.h"
#include"teacher.h"
#include"student.h"
#include<algorithm>


class Admin :public Identity
{
public:

	//Ĭ�Ϲ���
	Admin();
	//�вι���(����Ա��š�����������)
	Admin(int adId, std::string name, std::string pwd);

	//�˵�
	virtual void openMenu();

	//��ȡidentity����
	std::vector<Identity*> loadIdentityFile(std::string fileName, int personType);

	//д��identity����(һ����)
	void writeBackSubFile(std::string fileName, std::vector<Identity*>& vIdentityData);

	//��ȡ��������
	std::vector<ComputerRoom> loadCompFile();

	//д�ػ�������
	void writeBackCompFile(std::vector<ComputerRoom> &vComp);

	//����ظ�����
	bool roomIsExist(std::vector<ComputerRoom> &vComp, ComputerRoom& cr);

	//������id��ȫ��
	int getCompId(std::string str);

	//��ӻ�������
	void addComputerRoom();

	//��ȡ��������
	std::vector<Order> loadOrderFile();

	//����˺�
	void addAccount();

	//�鿴�˺�
	void showAccount();

	//��������
	void showRoomDetail(int week, int day);

	//�鿴������Ϣ
	void showCompuRoomInfo();

	//���ԤԼ��¼
	void clearReservation();
};
