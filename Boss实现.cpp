#include"Boss.h"


//���캯��
Boss::Boss(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = dId;
}
//��ʾ��Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << m_Id;
	cout << "\tְ��������" << m_Name;
	cout << "\t��λ��" << this->getDeptName();
	cout << "\t��λְ�𣺹���˾��������" << endl;
}
//��ȡ��λ
string Boss::getDeptName()
{
	return string("�ܲ�");
}