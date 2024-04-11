#include"speaker.h"

//选手类构造函数
speaker::speaker(std::string name)
{
	this->m_Name = std::string ("Speaker_").append(name);
	this->m_Score[0] = 0;
	this->m_Score[1] = 0;
}
speaker::speaker(char name)
{
	this->m_Name = std::string("Speaker_").append(1,name);
	this->m_Score[0] = 0;
	this->m_Score[1] = 0;
}

speaker::~speaker() {};


std::string speaker::getName()
{
	return this->m_Name;
}
double speaker::get_First_Score()
{
	return this->m_Score[0];
}
double speaker::get_Second_Score()
{
	return this->m_Score[1];
}
void speaker::set_First_Score(double score)
{
	this->m_Score[0] = score;
}
void speaker::set_Second_Score(double score)
{
	this->m_Score[1] = score;
}
