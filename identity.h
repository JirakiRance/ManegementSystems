#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include"globalFile.h"
#include"order.h"
#include"computerRoom.h"

class Identity
{
public:
	//²Ù×÷²Ëµ¥
	virtual void openMenu() = 0;
	int m_Id;
	std::string m_Name;
	std::string m_Password;
};