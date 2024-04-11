#include"Adressbooks.h"

//构造
Adressbooks::Adressbooks()
{
	this->m_Num = 0;
}
//析构
Adressbooks::~Adressbooks()
{
	this->m_Num = 0;
}


//展示菜单
void Adressbooks::show_Menu()
{
	cout << "* * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * 欢迎您使用通讯录管理系统! * * * *" << endl;
	cout << "* * * * * 0、退出通讯录 * * * * * * * * *" << endl;
	cout << "* * * * * 1、添加联系人 * * * * * * * * *" << endl;
	cout << "* * * * * 2、显示联系人 * * * * * * * * *" << endl;
	cout << "* * * * * 3、删除联系人 * * * * * * * * *" << endl;
	cout << "* * * * * 4、查找联系人 * * * * * * * * *" << endl;
	cout << "* * * * * 5、修改联系人 * * * * * * * * *" << endl;
	cout << "* * * * * 6、清空通讯录 * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * *" << endl;
}

//添加联系人
void Adressbooks::Add_Person()
{
	//通讯录是否已满判断
	if (this->m_Num == MAX)
	{
		cout << "当前通讯录已满!" << endl;
		system("pause");
		system("cls");
		return;
	}

	//数据准备
	string name;
	long long phone;
	string adress;

	//获取数据
	cout << "请输入新联系人的姓名："; cin >> name; 
	cout << "请输入新联系人的电话号码："; cin >> phone;
	cout << "请输入新联系人的住址："; cin >> adress; cout << endl;

	this->m_PersonArray[m_Num].m_Name = name;
	this->m_PersonArray[m_Num].m_Phone = phone;
	this->m_PersonArray[m_Num].m_Adress = adress;

	m_Num++;

	//提示
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
}

//显示联系人
void Adressbooks::Show_Persons()
{
	//通讯录是否为空判断
	if (this->m_Num == 0)
	{
		cout << "当前通讯录为空!" << endl;
		system("pause");
		system("cls");
		return;
	}
	//遍历输出
	for (int i = 0; i < this->m_Num; i++)
	{
		cout << "姓名：\t" << this->m_PersonArray[i].m_Name;
		cout << "\t联系电话：\t" << this->m_PersonArray[i].m_Phone;
		cout << "\t住址：\t" << this->m_PersonArray[i].m_Adress;
		cout << endl;
	}
	system("pause");
	system("cls");
}

//辅助::交换
void Adressbooks::swap(Person& p1, Person& p2)
{
	Person temp = p1;
	p1 = p2;
	p2 = temp;
}

//辅助::按名字查找
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

//删除联系人
void Adressbooks::Del_Person()
{
	//通讯录是否为空判断
	if (this->m_Num == 0)
	{
		cout << "当前通讯录为空!" << endl;
		system("pause");
		system("cls");
		return;
	}

	string locate_Name;
	cout << "请输入需删除的联系人的姓名："; cin >> locate_Name;
	
	int index = this->locatePerson(locate_Name);

	if (index == -1)
	{
		cout << "未找到姓名为" << locate_Name << "的联系人！" << endl;
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
	cout << "删除成功！" << endl;
	system("pause");
	system("cls");
	return;
}

//查找联系人
void Adressbooks::LookUp_Person()
{
	//通讯录是否为空判断
	if (this->m_Num == 0)
	{
		cout << "当前通讯录为空!" << endl;
		system("pause");
		system("cls");
		return;
	}

	string locate_Name;
	cout << "请输入需查找的联系人的姓名："; cin >> locate_Name;

	int index = this->locatePerson(locate_Name);
	if (index == -1)
	{
		cout << "未找到姓名为" << locate_Name << "的联系人！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "姓名：\t" << this->m_PersonArray[index].m_Name;
		cout << "联系电话：\t" << this->m_PersonArray[index].m_Phone;
		cout << "住址：\t" << this->m_PersonArray[index].m_Adress;
		cout << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void Adressbooks::Modify_Person()
{
	//通讯录是否为空判断
	if (this->m_Num == 0)
	{
		cout << "当前通讯录为空!" << endl;
		system("pause");
		system("cls");
		return;
	}

	string locate_Name;
	cout << "请输入需修改的联系人的姓名："; cin >> locate_Name;

	int index = this->locatePerson(locate_Name);
	if (index == -1)
	{
		cout << "未找到姓名为" << locate_Name << "的联系人！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "请重新输入联系人姓名："; cin >> this->m_PersonArray[index].m_Name;
		cout << endl;
		cout << "请重新输入联系人联系电话："; cin >> this->m_PersonArray[index].m_Phone;
		cout << endl;
		cout << "请重新输入联系人住址："; cin >> this->m_PersonArray[index].m_Adress;
		cout << endl;
	}
	cout << "修改成功！" << endl;
	system("pause");
	system("cls");
}

//清空通讯录
void Adressbooks::Clear()
{
	//通讯录是否为空判断
	if (this->m_Num == 0)
	{
		cout << "当前通讯录为空!" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "确认清空通讯录?" << endl;
	cout << "1、确定" << endl;
	cout << "2、取消" << endl;

	int select_For_Clear;
	//若不选1或2，重选
FLAG_for_ReseletClear:
	cin>>select_For_Clear;

	if (select_For_Clear != 1 && select_For_Clear != 2)
	{
		goto FLAG_for_ReseletClear;
	}
	else if (select_For_Clear == 2)
	{
		cout << "已取消" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (select_For_Clear == 1)
	{
		this->m_Num = 0;
		cout << "已清空" << endl;
		system("pause");
		system("cls");
		return;
	}
}

