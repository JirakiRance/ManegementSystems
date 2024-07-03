#pragma once
#include"identity.h"

class Student :public Identity
{
public:
	//默认构造
	Student();
	//有参（姓名、学号、密码）
	Student(int stuId, std::string name, std::string password);

	//菜单
	virtual void openMenu();

	//获取预约信息(预约信息默认以学生学号升序排列)
	std::vector<Order> loadOrderFile();

	//写回预约
	void writeBackOrder(std::vector<Order>& vOrder);

	//看一下机房
	std::vector<ComputerRoom> loadCompRoom();

	//具体预约
	void applyDetail(int week, int day, int comp);

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//检查重复预约
	bool orderIsExist(std::vector<Order> &vSunOrder,Order &od);

	//字符串处理
	std::string getTimeStr(int week, int day);
	std::string getInfoStr(int info);

};