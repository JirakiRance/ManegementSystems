#pragma once
#include"Worker.h"

class Maneger :public Worker
{
public:
	Maneger(int id, string name, int dId);

	//显示个人信息
	void showInfo();
	//获取岗位名称
	string getDeptName();
};
