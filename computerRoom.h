#pragma once
#include<iostream>
#include"globalFile.h"

class ComputerRoom
{
public:
	ComputerRoom(int comId, int capa)
	{
		this->m_ComId = comId;
		this->m_MaxCapacity = capa;
	}
	bool operator<(ComputerRoom& cr)
	{
		return this->m_ComId < cr.m_ComId;
	}
public:
	int m_ComId;//������
	int m_MaxCapacity;//�������
};