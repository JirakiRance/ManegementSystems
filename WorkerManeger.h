#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#define FILENAME "E:\\WPS\\TXT\\workerFile.txt"

#include"Worker.h"
#include"Employee.h"
#include"Maneger.h"
#include"Boss.h"

class WorkerManeger
{
public:
	//����
	WorkerManeger();

	
	//չʾ�˵�
	void showMenu();
	//�˳�
	void exitSystem();
	//����
	void addWorker();
	//�����ļ�
	void save();
	//�����ļ�����
	bool m_FileIsEmpty;
	//ͳ���ļ�������
	int getWorkerNum();
	//��ʼ��ְ��
	void initialWorker();
	//��ʾְ��
	void showWorker();
	//ɾ��ְ��
	void deleteWorker();
	//ְ���Ƿ����(1���ڣ�0������)
	int Work_IsExist(int num);
	//�޸�ְ��
	void modefyWorker();
	//����ְ��
	void findWorker();
	//����
	void Sort();
	//����λ��
	void Swap_Worker(Worker* w1, Worker* w2);
	//����ĵ�
	void Delete_All();

	//����
	~WorkerManeger();

protected:
	Worker ** m_WorkerArr;//ְ������
	int m_WorkerNum;//ְ������
};
