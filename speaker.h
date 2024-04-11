#pragma once
#include<string>
#include<map>

class speaker
{
public:
	speaker(char name);
	speaker(std::string name);
	~speaker();

	//����ӿ�
	std::string getName();
	double get_First_Score();
	double get_Second_Score();
	void set_First_Score(double score);
	void set_Second_Score(double score);

private:
	std::string m_Name;//����
	double m_Score[2];//����������������
};







