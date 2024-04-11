#include"Adressbooks.h"

//����
Adressbooks::Adressbooks()
{
	this->m_Num = 0;
}
//����
Adressbooks::~Adressbooks()
{
	this->m_Num = 0;
}


//չʾ�˵�
void Adressbooks::show_Menu()
{
	cout << "* * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * ��ӭ��ʹ��ͨѶ¼����ϵͳ! * * * *" << endl;
	cout << "* * * * * 0���˳�ͨѶ¼ * * * * * * * * *" << endl;
	cout << "* * * * * 1�������ϵ�� * * * * * * * * *" << endl;
	cout << "* * * * * 2����ʾ��ϵ�� * * * * * * * * *" << endl;
	cout << "* * * * * 3��ɾ����ϵ�� * * * * * * * * *" << endl;
	cout << "* * * * * 4��������ϵ�� * * * * * * * * *" << endl;
	cout << "* * * * * 5���޸���ϵ�� * * * * * * * * *" << endl;
	cout << "* * * * * 6�����ͨѶ¼ * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * *" << endl;
}

//�����ϵ��
void Adressbooks::Add_Person()
{
	//ͨѶ¼�Ƿ������ж�
	if (this->m_Num == MAX)
	{
		cout << "��ǰͨѶ¼����!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//����׼��
	string name;
	long long phone;
	string adress;

	//��ȡ����
	cout << "����������ϵ�˵�������"; cin >> name; 
	cout << "����������ϵ�˵ĵ绰���룺"; cin >> phone;
	cout << "����������ϵ�˵�סַ��"; cin >> adress; cout << endl;

	this->m_PersonArray[m_Num].m_Name = name;
	this->m_PersonArray[m_Num].m_Phone = phone;
	this->m_PersonArray[m_Num].m_Adress = adress;

	m_Num++;

	//��ʾ
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʾ��ϵ��
void Adressbooks::Show_Persons()
{
	//ͨѶ¼�Ƿ�Ϊ���ж�
	if (this->m_Num == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��!" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�������
	for (int i = 0; i < this->m_Num; i++)
	{
		cout << "������\t" << this->m_PersonArray[i].m_Name;
		cout << "\t��ϵ�绰��\t" << this->m_PersonArray[i].m_Phone;
		cout << "\tסַ��\t" << this->m_PersonArray[i].m_Adress;
		cout << endl;
	}
	system("pause");
	system("cls");
}

//����::����
void Adressbooks::swap(Person& p1, Person& p2)
{
	Person temp = p1;
	p1 = p2;
	p2 = temp;
}

//����::�����ֲ���
int Adressbooks::locatePerson(string name)
{
	for (int i = 0; i < this->m_Num; i++)
	{
		if (this->m_PersonArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��
void Adressbooks::Del_Person()
{
	//ͨѶ¼�Ƿ�Ϊ���ж�
	if (this->m_Num == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	string locate_Name;
	cout << "��������ɾ������ϵ�˵�������"; cin >> locate_Name;
	
	int index = this->locatePerson(locate_Name);

	if (index == -1)
	{
		cout << "δ�ҵ�����Ϊ" << locate_Name << "����ϵ�ˣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = index; i < this->m_Num-1; i++)
		{
			this->swap(this->m_PersonArray[i], this->m_PersonArray[i + 1]);
		}
		m_Num--;
	}
	cout << "ɾ���ɹ���" << endl;
	system("pause");
	system("cls");
	return;
}

//������ϵ��
void Adressbooks::LookUp_Person()
{
	//ͨѶ¼�Ƿ�Ϊ���ж�
	if (this->m_Num == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	string locate_Name;
	cout << "����������ҵ���ϵ�˵�������"; cin >> locate_Name;

	int index = this->locatePerson(locate_Name);
	if (index == -1)
	{
		cout << "δ�ҵ�����Ϊ" << locate_Name << "����ϵ�ˣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "������\t" << this->m_PersonArray[index].m_Name;
		cout << "��ϵ�绰��\t" << this->m_PersonArray[index].m_Phone;
		cout << "סַ��\t" << this->m_PersonArray[index].m_Adress;
		cout << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void Adressbooks::Modify_Person()
{
	//ͨѶ¼�Ƿ�Ϊ���ж�
	if (this->m_Num == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	string locate_Name;
	cout << "���������޸ĵ���ϵ�˵�������"; cin >> locate_Name;

	int index = this->locatePerson(locate_Name);
	if (index == -1)
	{
		cout << "δ�ҵ�����Ϊ" << locate_Name << "����ϵ�ˣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "������������ϵ��������"; cin >> this->m_PersonArray[index].m_Name;
		cout << endl;
		cout << "������������ϵ����ϵ�绰��"; cin >> this->m_PersonArray[index].m_Phone;
		cout << endl;
		cout << "������������ϵ��סַ��"; cin >> this->m_PersonArray[index].m_Adress;
		cout << endl;
	}
	cout << "�޸ĳɹ���" << endl;
	system("pause");
	system("cls");
}

//���ͨѶ¼
void Adressbooks::Clear()
{
	//ͨѶ¼�Ƿ�Ϊ���ж�
	if (this->m_Num == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "ȷ�����ͨѶ¼?" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;

	int select_For_Clear;
	//����ѡ1��2����ѡ
FLAG_for_ReseletClear:
	cin>>select_For_Clear;

	if (select_For_Clear != 1 && select_For_Clear != 2)
	{
		goto FLAG_for_ReseletClear;
	}
	else if (select_For_Clear == 2)
	{
		cout << "��ȡ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (select_For_Clear == 1)
	{
		this->m_Num = 0;
		cout << "�����" << endl;
		system("pause");
		system("cls");
		return;
	}
}

