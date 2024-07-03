#pragma once
#include"identity.h"

class Teacher :public Identity
{
public:

	//默认构造
	Teacher();
	//有参构造(职工号、姓名、密码)
	Teacher(int empId, std::string name, std::string pwd);

	//菜单
	virtual void openMenu();

	//获取预约信息(预约信息默认以学生学号升序排列)
	std::vector<Order> loadOrderFile();

	//写回预约
	void writeBackOrder(std::vector<Order>& vOrder);

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//字符串处理
	std::string getTimeStr(int week, int day);
	std::string getInfoStr(int info);
};