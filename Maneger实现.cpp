#include"Maneger.h"


//构造函数
Maneger::Maneger(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}
//显示信息
void Maneger::showInfo()
{
	cout << "职工编号：" << m_Id;
	cout << "\t职工姓名：" << m_Name;
	cout << "\t岗位：" << this->getDeptName();
	cout << "\t岗位职责：完成老板交给的任务" << endl;
}
//获取岗位
string Maneger::getDeptName()
{
	return string("经理");
}