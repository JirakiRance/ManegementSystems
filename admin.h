#pragma once
#include"identity.h"
#include"teacher.h"
#include"student.h"
#include<algorithm>


class Admin :public Identity
{
public:

	//默认构造
	Admin();
	//有参构造(管理员编号、姓名、密码)
	Admin(int adId, std::string name, std::string pwd);

	//菜单
	virtual void openMenu();

	//获取identity数据
	std::vector<Identity*> loadIdentityFile(std::string fileName, int personType);

	//写回identity数据(一样的)
	void writeBackSubFile(std::string fileName, std::vector<Identity*>& vIdentityData);

	//获取机房数据
	std::vector<ComputerRoom> loadCompFile();

	//写回机房数据
	void writeBackCompFile(std::vector<ComputerRoom> &vComp);

	//检查重复机房
	bool roomIsExist(std::vector<ComputerRoom> &vComp, ComputerRoom& cr);

	//检测机房id安全性
	int getCompId(std::string str);

	//添加机房数据
	void addComputerRoom();

	//获取订单数据
	std::vector<Order> loadOrderFile();

	//添加账号
	void addAccount();

	//查看账号
	void showAccount();

	//机房详情
	void showRoomDetail(int week, int day);

	//查看机房信息
	void showCompuRoomInfo();

	//清空预约记录
	void clearReservation();
};
