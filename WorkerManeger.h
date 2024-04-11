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
	//构造
	WorkerManeger();

	
	//展示菜单
	void showMenu();
	//退出
	void exitSystem();
	//增加
	void addWorker();
	//保存文件
	void save();
	//读入文件数据
	bool m_FileIsEmpty;
	//统计文件中人数
	int getWorkerNum();
	//初始化职工
	void initialWorker();
	//显示职工
	void showWorker();
	//删除职工
	void deleteWorker();
	//职工是否存在(1存在，0不存在)
	int Work_IsExist(int num);
	//修改职工
	void modefyWorker();
	//查找职工
	void findWorker();
	//排序
	void Sort();
	//交换位置
	void Swap_Worker(Worker* w1, Worker* w2);
	//清空文档
	void Delete_All();

	//析构
	~WorkerManeger();

protected:
	Worker ** m_WorkerArr;//职工数组
	int m_WorkerNum;//职工数量
};
