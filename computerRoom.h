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
	int m_ComId;//机房号
	int m_MaxCapacity;//最大容量
};