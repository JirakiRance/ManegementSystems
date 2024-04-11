#include"Employee.h"


//构造函数
Employee::Employee(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}
//显示信息
void Employee::showInfo()
{
	cout << "职工编号：" << m_Id; 
	cout << "\t职工姓名：" << m_Name;
	cout << "\t岗位：" << this->getDeptName();
	cout << "\t岗位职责：完成经理交给的任务" << endl;
}
//获取岗位
string Employee::getDeptName()
{
	return string("普通员工");
}