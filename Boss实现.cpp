#include"Boss.h"


//构造函数
Boss::Boss(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}
//显示信息
void Boss::showInfo()
{
	cout << "职工编号：" << m_Id;
	cout << "\t职工姓名：" << m_Name;
	cout << "\t岗位：" << this->getDeptName();
	cout << "\t岗位职责：管理公司所有事务" << endl;
}
//获取岗位
string Boss::getDeptName()
{
	return string("总裁");
}