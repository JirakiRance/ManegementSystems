#pragma once
#include<deque>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<string>

class Jshuffler
{
public:
	Jshuffler(int maxNum);
	~Jshuffler();

	void doShuffle();
	void showOrder();
	
private:
	int m_MaxNumber;
	int * m_Order;		//������˳��
	static int thisTime;
};