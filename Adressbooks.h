#pragma once
#include"Person.h"

class Adressbooks
{
public:
	//������װ

	//չʾ�˵�
	void show_Menu();
	
	//�����ϵ��
	void Add_Person();

	//��ʾ��ϵ��
	void Show_Persons();

	//ɾ����ϵ��
	void Del_Person();

	//����::����
	void swap(Person& p1, Person& p2);

	//����::�����ֲ���
	int locatePerson(string name);

	//������ϵ��
	void LookUp_Person();

	//�޸���ϵ��
	void Modify_Person();

	//���ͨѶ¼
	void Clear();

	//����
	Adressbooks();

	//����
	~Adressbooks();

public:
	Person m_PersonArray[MAX];
	int m_Num;
};