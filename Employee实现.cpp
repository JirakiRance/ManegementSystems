#include"Employee.h"


//���캯��
Employee::Employee(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}
//��ʾ��Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ�" << m_Id; 
	cout << "\tְ��������" << m_Name;
	cout << "\t��λ��" << this->getDeptName();
	cout << "\t��λְ����ɾ�����������" << endl;
}
//��ȡ��λ
string Employee::getDeptName()
{
	return string("��ͨԱ��");
}