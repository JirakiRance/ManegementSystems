#include"shuffler.h"

int Jshuffler::thisTime = 0;
Jshuffler::Jshuffler(int maxNum)
{
	this->thisTime++;
	this->m_MaxNumber = maxNum;
	this->m_Order = new int[maxNum];
	for (int i = 0; i < this->m_MaxNumber; i++)
	{
		this->m_Order[i] = 0;
	}
}
Jshuffler::~Jshuffler()
{
	if (this->m_Order != NULL)
		delete[] this->m_Order;
}
void Jshuffler::doShuffle()
{
	std::deque<int> d;//��������洢
	for (int i = 0; i < this->m_MaxNumber; i++)
	{
		d.push_back(i + 1);
	}
	while (d.size())
	{
		std::random_shuffle(d.begin(), d.end());
		this->m_Order[this->m_MaxNumber-d.size()] = *(d.begin());
		d.pop_front();
	}
}
void Jshuffler::showOrder()
{
	std::cout << "��������" << this->thisTime << "��ʹ�������" << std::endl;
	for (int i=0;i<this->m_MaxNumber;i++)
	{
		std::cout << this->m_Order[i] << " ";
	}
	std::cout << std::endl<< std::endl;
}