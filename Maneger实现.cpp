#include"Maneger.h"


//���캯��
Maneger::Maneger(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}
//��ʾ��Ϣ
void Maneger::showInfo()
{
	cout << "ְ����ţ�" << m_Id;
	cout << "\tְ��������" << m_Name;
	cout << "\t��λ��" << this->getDeptName();
	cout << "\t��λְ������ϰ彻��������" << endl;
}
//��ȡ��λ
string Maneger::getDeptName()
{
	return string("����");
}