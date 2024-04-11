#include"WorkerManeger.h"

//WorkerManeger实现

WorkerManeger::WorkerManeger()
{
	//1、文件不存在
	ifstream ifs(FILENAME,ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在!" << endl;
		//初始化数据
		this->m_WorkerNum = 0;
		this->m_WorkerArr = NULL;
		//初始化"文件是否为空"
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2、文件存在，但是为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		//初始化数据
		this->m_WorkerNum = 0;
		this->m_WorkerArr = NULL;
		//初始化"文件是否为空"
		this->m_FileIsEmpty = true;//（文件为空置实）
		ifs.close();
		return;
	}

	//3、文件存在，并且有数据
	int num = this->getWorkerNum();
	//cout << "有" << num << "个人" << endl;//测试代码
	//更新属性
	this->m_WorkerNum = num;
	this->m_FileIsEmpty = false;
	
	//开辟空间
	this->m_WorkerArr = new Worker * [this->m_WorkerNum];
	//将文件中的数据录入数组
	this->initialWorker();
}
WorkerManeger::~WorkerManeger()
{
	if (this->m_WorkerArr != NULL)
	{
		delete[]this->m_WorkerArr;
		this->m_WorkerNum = 0;
	}
}

//保存文件
void WorkerManeger::save()
{
	//指定路径
	ofstream ofs(FILENAME,ios::out);
	//头提示栏
	/*ofs << "职工编号\t"
		<< "职工姓名\t"
		<< "职工岗位" << endl;*/
	//写入数据
	for (int i = 0; i < this->m_WorkerNum; i++)
	{
		ofs << this->m_WorkerArr[i]->m_Id << " ";
		ofs << this->m_WorkerArr[i]->m_Name << " ";
		ofs << this->m_WorkerArr[i]->m_DeptId;
		ofs << endl;
	}
	ofs.close();
}
//统计文件中人数
int WorkerManeger::getWorkerNum()
{
	ifstream ifs(FILENAME,ios::in);
	//准备读入
	int num = 0;

	char buf[1024];
	while (ifs.getline(buf,sizeof(buf)))
	{
		num++;
	}
	ifs.close();
	return num;
}
//初始化职工
void WorkerManeger::initialWorker()
{
	ifstream ifs(FILENAME, ios::in);

	//准备读入
	int id;
	string name;
	int dId;
	int index = 0;//标识下标
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)//普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2)//经理
		{
			worker = new Maneger(id, name, dId);
		}
		else if (dId == 3)//总裁
		{
			worker = new Boss(id, name, dId);
		}
		this->m_WorkerArr[index] = worker;
		index++;
	}
	ifs.close();
}

//展示菜单
void WorkerManeger::showMenu()
{
	cout << "********************************" << endl;
	cout << "*****欢迎使用职工管理系统！*****" << endl;
	cout << "*********0.退出管理系统*********" << endl;
	cout << "*********1.增加职工信息*********" << endl;
	cout << "*********2.显示职工信息*********" << endl;
	cout << "*********3.删除职工信息*********" << endl;
	cout << "*********4.修改职工信息*********" << endl;
	cout << "*********5.查找职工信息*********" << endl;
	cout << "*********6.按照编号排序*********" << endl;
	cout << "*********7.清空所有文档*********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}
//退出系统
void WorkerManeger::exitSystem()
{
	cout << "欢迎您下次使用本系统！(。^_^ 。)" << endl;
	system("pause");
	exit(0);
}
//添加职工
void WorkerManeger::addWorker()
{
	FLAG_ADD://回返标记

	int addNum = 0;
	cout << "请输入需要添加的员工数量："; cin >> addNum;

	if (addNum > 0&&addNum<6)
	{
		//开辟新空间，将旧空间数据转存至新空间

		//计算新空间
		int newSize = this->m_WorkerNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize * sizeof(Worker)];

		//若已有数据，进行覆盖操作
		if (this->m_WorkerArr != NULL)
		{
			for (int i = 0; i < this->m_WorkerNum; i++)
			{
				newSpace[i] = this->m_WorkerArr[i];
			}
		}

		//输入新数据
		int id=-1;
		string name="-1";
		int dSelect=-1;

		for (int i = 0; i < addNum; i++)
		{
			cout << "请输入第" << i + 1 << "位新职工编号："; cin >> id;
			cout << "请输入第" << i + 1 << "位新职工姓名："; cin >> name;

		
			cout << "请选择该职工岗位:" << endl << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、总裁" << endl;
			cin >> dSelect;


			//开始创建指针

			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Maneger(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			//指针创建完毕，开始添加
			newSpace[this->m_WorkerNum + i] = worker;

			//delete worker;
			//worker = NULL;

			//worker数据归还
			id = -1;
			name = "-1";
			dSelect = -1;
		}


		//记录完毕，删除旧空间并更新空间以及更新数量
		delete[] this->m_WorkerArr;
		this->m_WorkerArr = newSpace;
		this->m_WorkerNum = this->m_WorkerNum + addNum;

		//保存文件
		this->save();
		
		//删除new区新建空间
		//delete[] newSpace;
		//文件为空置虚
		this->m_FileIsEmpty = false;
		//提示
		cout << "已成功添加" << addNum << "名新职工信息！" << endl;
	}
	else if (addNum >= 6)
	{
		cout << "单次添加的人数过多，请分批添加" << endl;
		system("pause");
		goto FLAG_ADD;//回返到Add开头
	}
	else
	{
		cout << "输入有误，请重新输入" << endl;
		system("pause");
		goto FLAG_ADD;//回返到Add开头
	}
	system("pause");
	system("cls");
}
//显示职工
void WorkerManeger::showWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或文件不存在！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_WorkerNum; i++)
		{
			this->m_WorkerArr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//删除职工
void WorkerManeger::deleteWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或文件不存在！" << endl;
	}

	int num;
	cout << "请输入职工编号："; cin >> num;
	if (this->Work_IsExist(num)==-1)
	{
		cout << "未找到该职工！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = this->Work_IsExist(num); i < this->m_WorkerNum-1; i++)
		{
			this->m_WorkerArr[i] = this->m_WorkerArr[i + 1];
		}
		//delete this->m_WorkerArr[this->m_WorkerNum];
		//this->m_WorkerArr[this->m_WorkerNum] = NULL;
		this->m_WorkerNum--;
		
		save();

		cout << "删除成功！" << endl;
		system("pause");
		system("cls");
	}
	//判断还有没有人
	if (this->m_WorkerNum == 0)
	{
		this->m_FileIsEmpty = true;
	}
}
//职工是否存在(存在返回位置下标，不存在返回-1)
int WorkerManeger::Work_IsExist(int num)
{
	for (int i = 0; i < this->m_WorkerNum; i++)
	{
		if (this->m_WorkerArr[i]->m_Id == num)
		{
			return i;
		}
	}
	return -1;
}
//修改职工
void WorkerManeger::modefyWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或文件不存在！" << endl;
	}

	int select = 0;
	cout << "请输入查找方式：" << endl;
	cout << "1、按姓名查找" << endl;
	cout << "2、按职工编号查找" << endl;

FLAG_reManner://不按姓名或编号查找职工，回返重选
	cin >> select;

	if (select == 2)
	{
		int id;
		cout << "请输入职工编号:"; cin >> id;

		if (this->Work_IsExist(id) == -1)
		{
			cout << "未找到该职工！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			//新属性
			int new_Id;
			string new_Name;
			int new_dId = 0;


			//接受位置
			int ret = this->Work_IsExist(id);
			//先显示信息
			this->m_WorkerArr[ret]->showInfo();
			//删掉信息
			delete m_WorkerArr[ret];

			cout << "请重新输入职工编号：";
			cin >> new_Id;

			cout << "请重新输入职工姓名：";
			cin >> new_Name;

			cout << "请重新选择部门编号：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、总裁" << endl;

		FLAG_reselectForDept_Num://编号查找职工中，重新选部门编号

			//准备接收数据
			Worker* worker = NULL;

			cin >> new_dId;
			if (new_dId == 1)
			{
				worker = new Employee(new_Id, new_Name, new_dId);
			}
			else if (new_dId == 2)
			{
				worker = new Maneger(new_Id, new_Name, new_dId);
			}
			else if (new_dId == 3)
			{
				worker = new Boss(new_Id, new_Name, new_dId);
			}
			else
			{
				new_dId = 0;
				goto FLAG_reselectForDept_Num;
			}
			m_WorkerArr[ret] = worker;
			cout << "修改成功！" << endl;
			this->save();
		}
	}
	else if (select == 1)
	{
		//用于查找名字
		string old_Name;
		cout << "请输入职工姓名:"; cin >> old_Name;

		int ret = -1;
		for (int i = 0; i < this->m_WorkerNum; i++)
		{
			if (this->m_WorkerArr[i]->m_Name == old_Name)
			{
				//找到了，先展示信息
				this->m_WorkerArr[i]->showInfo();
				ret = i;
				break;
			}
		}

		//删掉信息
		delete m_WorkerArr[ret];

		if (ret == -1)
		{
			cout << "未找到该职工！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			//新属性
			int new_Id;
			string new_Name;
			int new_dId = 0;


			//开始复制
			cout << "请重新输入职工编号：";
			cin >> new_Id;

			cout << "请重新输入职工姓名：";
			cin >> new_Name;


		FLAG_reselectForDept_Name://名称查找职工中，重新选部门编号

			int new_dSelect = 0;
			cout << "请重新选择部门编号：";
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、总裁" << endl;

			//准备接收数据
			Worker* worker = NULL;

			cin >> new_dId;
			if (new_dId == 1)
			{
				worker = new Employee(new_Id, new_Name, new_dId);
			}
			else if (new_dId == 2)
			{
				worker = new Maneger(new_Id, new_Name, new_dId);
			}
			else if (new_dId == 3)
			{
				worker = new Boss(new_Id, new_Name, new_dId);
			}
			else
			{
				new_dSelect = 0;
				goto FLAG_reselectForDept_Name;
			}
			m_WorkerArr[ret] = worker;
			cout << "修改成功！" << endl;
			this->save();
		}
	}
	else
	{
		cout << "请重新输入！" << endl;
		goto FLAG_reManner;
	}
	system("pause");
	system("cls");
}
//查找职工
void WorkerManeger::findWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或文件不存在！" << endl;
	}

	int select = 0;
	cout << "请输入查找方式：" << endl;
	cout << "1、按姓名查找" << endl;
	cout << "2、按职工编号查找" << endl;

	FLAG_reManner://不按姓名或编号查找职工，回返重选
	cin >> select;

	if (select == 2)
	{
		int id;
		cout << "请输入职工编号:"; cin >> id;

		if (this->Work_IsExist(id) == -1)
		{
			cout << "未找到该职工！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			this->m_WorkerArr[this->Work_IsExist(id)]->showInfo();
			system("pause");
			system("cls");
		}
	}
	else if (select == 1)
	{
		string name;
		cout << "请输入职工姓名:"; cin >> name;

		int ret = -1;
		for (int i = 0; i < this->m_WorkerNum; i++)
		{
			if (this->m_WorkerArr[i]->m_Name == name)
			{
				//找到了，展示信息
				this->m_WorkerArr[i]->showInfo();
				ret = i;
				break;
			}
			system("pause");
			system("cls");
		}

		if (ret == -1)
		{
			cout << "未找到该职工！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	else
	{
		cout << "请重新输入！" << endl;
		goto FLAG_reManner;
	}
}
//交换位置
void WorkerManeger::Swap_Worker(Worker* w1, Worker* w2)
{
	Worker* temp = new Employee(99, "temp", 3);
	*temp = *w1;
	*w1 = *w2;
	*w2 = *temp;
	delete temp;
}
//排序
void WorkerManeger::Sort()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或文件不存在！" << endl;
	}

	int select = 0;
	cout << "请选择排序方式" << endl;
	cout << "1、按职工编号升序" << endl;
	cout << "2、按职工编号降序" << endl;

	FLAG_sortReSelect://不选1或2，重选
	cin >> select;
	if (select != 1 && select != 2)
	{
		cout << "请重新输入！" << endl;
		goto FLAG_sortReSelect;
	}
	else
	{
		int minOrMax = 0; int index = 0;

		if (select == 1)//升序，找最小置左
		{
			for (int i = 0; i < this->m_WorkerNum-1; i++)
			{
				minOrMax = this->m_WorkerArr[i]->m_Id;
				for (int j = i+1; j < this->m_WorkerNum; j++)
				{
					if (minOrMax > this->m_WorkerArr[j]->m_Id)
					{
						minOrMax = this->m_WorkerArr[j]->m_Id;
						index = j;
					}
				}
				this->Swap_Worker(this->m_WorkerArr[i], this->m_WorkerArr[index]);
				minOrMax = this->m_WorkerArr[i + 1]->m_Id; index = i+1;
			}
		}
		else if (select == 2)//降序，找最大置左
		{
			for (int i = 0; i < this->m_WorkerNum-1; i++)
			{
				minOrMax = this->m_WorkerArr[i]->m_Id;
				for (int j = i+1; j < this->m_WorkerNum; j++)
				{
					if (minOrMax < this->m_WorkerArr[j]->m_Id)
					{
						minOrMax = this->m_WorkerArr[j]->m_Id;
						index = j;
					}
				}
				this->Swap_Worker(this->m_WorkerArr[i], this->m_WorkerArr[index]);
				minOrMax = this->m_WorkerArr[i + 1]->m_Id; index = i+1;
			}
		}
		cout << "已排序完成,排序后结果为：" << endl;
		save();
		this->showWorker();
	}
	system("cls");
}
//清空文档
void WorkerManeger::Delete_All()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或文件不存在！" << endl;
		return;
	}

	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select;
	FLAG_reSelectForDeleteAll:
	cin >> select;

	if (select != 1 && select != 2)
	{
		goto FLAG_reSelectForDeleteAll;
	}
	else if (select == 2)
	{
		system("pause");
		system("cls");
		return;
	}
	else
	{
		//删除文档
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();
		//删除指针指向堆区的内存
		if (this->m_WorkerArr != NULL)
		{
			for (int i = 0; i < this->m_WorkerNum; i++)
			{
				delete this->m_WorkerArr[i];
				this->m_WorkerArr[i] = NULL;
			}
		}
		//释放指针
		delete[] this->m_WorkerArr;
		this->m_WorkerArr = NULL;
		//重置属性
		this->m_WorkerNum = 0;
		this->m_FileIsEmpty = true;

		cout << "已清空" << endl;
		system("pause");
		system("cls");
	}
}

