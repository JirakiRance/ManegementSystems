#pragma once
#include<iostream>
using namespace std;
#include<string>

//职工抽象类
class Worker
{
	friend class WorkerManeger;
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

protected:
	int m_Id;//职工编号
	string m_Name;//职工姓名
	int m_DeptId;//所在部门编号
};

