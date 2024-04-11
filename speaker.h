#pragma once
#include<string>
#include<map>

class speaker
{
public:
	speaker(char name);
	speaker(std::string name);
	~speaker();

	//对外接口
	std::string getName();
	double get_First_Score();
	double get_Second_Score();
	void set_First_Score(double score);
	void set_Second_Score(double score);

private:
	std::string m_Name;//姓名
	double m_Score[2];//分数，可以有两轮
};







