#pragma once
#include"Person.h"

class Adressbooks
{
public:
	//函数封装

	//展示菜单
	void show_Menu();
	
	//添加联系人
	void Add_Person();

	//显示联系人
	void Show_Persons();

	//删除联系人
	void Del_Person();

	//辅助::交换
	void swap(Person& p1, Person& p2);

	//辅助::按名字查找
	int locatePerson(string name);

	//查找联系人
	void LookUp_Person();

	//修改联系人
	void Modify_Person();

	//清空通讯录
	void Clear();

	//构造
	Adressbooks();

	//析构
	~Adressbooks();

public:
	Person m_PersonArray[MAX];
	int m_Num;
};