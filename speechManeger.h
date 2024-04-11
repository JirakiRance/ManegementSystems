#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<map>
#include<string>
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>
#include"speaker.h"
#define FILENAME "D:\\C++\\works\\speech.csv"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::map;
using std::string;
using std::deque;



//使用管理系统类来实现功能
class speechManeger
{
public:
	//构造
	speechManeger();
	//析构
	~speechManeger();



//主要功能

	//展示菜单
	void show_Menu();

	//选手初始化
	void init_Speaker();

	//选手抽签
	void draw_Speaker();

	//遍历选手顺序
	void show_Speaker_drawOrder_1(vector<int>& v);//抽前后顺序,第一轮
	void show_Speaker_drawOrder_2(vector<int>& v);//抽前后顺序,第二轮
	void show_Speaker_scoreOrder_1();//打分后顺序，1
	void show_Speaker_scoreOrder_2();//打分后顺序，2
	void show_Victory();

	//使用m_MapSpeaker对v1重写入
	//void re_Write_Vec_By_MapSpeaker(vector<int>& v1, vector<int>& v2);

	//对每个选手打分
	void doScore_1(vector<int> & v);
	void doScore_2(vector<int> & v);
	
	//初始化容器
	void initSpeechContainers();

	//开始比赛
	void start_Speech();

	//保存记录
	void saveRecord();

	//读入往届数据
	void load_Record();

	//查看往届记录
	void see_Record();

	//清空比赛记录
	void clear_List();

	//退出比赛
	void exit_speechManeger();


public:
	int m_Index;						//记录比赛轮数
private:
	//数据库

	map<int, speaker> m_MapSpeaker;		//用来存储选手数据
	vector<int> v1;						//第一轮初始容器(存编号就可以了)	12人
	vector<int> v2;						//第二轮初始容器					6人
	vector<int> vVictory;				//最终前三名容器
	map<int, vector<string>> m_Record;	//读入往届记录
	bool file_IsEmpty;					//判断.csv文件是否为空
};
