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



//ʹ�ù���ϵͳ����ʵ�ֹ���
class speechManeger
{
public:
	//����
	speechManeger();
	//����
	~speechManeger();



//��Ҫ����

	//չʾ�˵�
	void show_Menu();

	//ѡ�ֳ�ʼ��
	void init_Speaker();

	//ѡ�ֳ�ǩ
	void draw_Speaker();

	//����ѡ��˳��
	void show_Speaker_drawOrder_1(vector<int>& v);//��ǰ��˳��,��һ��
	void show_Speaker_drawOrder_2(vector<int>& v);//��ǰ��˳��,�ڶ���
	void show_Speaker_scoreOrder_1();//��ֺ�˳��1
	void show_Speaker_scoreOrder_2();//��ֺ�˳��2
	void show_Victory();

	//ʹ��m_MapSpeaker��v1��д��
	//void re_Write_Vec_By_MapSpeaker(vector<int>& v1, vector<int>& v2);

	//��ÿ��ѡ�ִ��
	void doScore_1(vector<int> & v);
	void doScore_2(vector<int> & v);
	
	//��ʼ������
	void initSpeechContainers();

	//��ʼ����
	void start_Speech();

	//�����¼
	void saveRecord();

	//������������
	void load_Record();

	//�鿴�����¼
	void see_Record();

	//��ձ�����¼
	void clear_List();

	//�˳�����
	void exit_speechManeger();


public:
	int m_Index;						//��¼��������
private:
	//���ݿ�

	map<int, speaker> m_MapSpeaker;		//�����洢ѡ������
	vector<int> v1;						//��һ�ֳ�ʼ����(���žͿ�����)	12��
	vector<int> v2;						//�ڶ��ֳ�ʼ����					6��
	vector<int> vVictory;				//����ǰ��������
	map<int, vector<string>> m_Record;	//���������¼
	bool file_IsEmpty;					//�ж�.csv�ļ��Ƿ�Ϊ��
};
