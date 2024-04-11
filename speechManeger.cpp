#include"speechManeger.h"
#include"speaker.h"

using std::cout;
using std::endl;
using std::cin;

//构造函数
speechManeger::speechManeger()
{
	//初始化容器
	this->initSpeechContainers();

	//初始化选手
	this->init_Speaker();

	//读入数据(获取往届记录)
	this->load_Record();
}
//析构
speechManeger::~speechManeger()
{
	//保存数据
}

//展示菜单
void speechManeger::show_Menu()
{
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * 欢迎使用演讲比赛流程管理系统！* * * * *" << endl;
	cout << "* * * * * * * * *1、开始演讲比赛* * * * * * * * *" << endl;
	cout << "* * * * * * * * *2、查看往届成绩* * * * * * * * *" << endl;
	cout << "* * * * * * * * *3、清空所有记录* * * * * * * * *" << endl;
	cout << "* * * * * * * * *0、退出管理系统* * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << endl;
	cout << endl;
}

//退出功能
void speechManeger::exit_speechManeger()
{
	cout << "欢迎您下次使用！  _(:з」∠)_  " << endl;
	system("pause");
	exit(0);
}

//start_Speech辅助：初始化选手的数据
void speechManeger::init_Speaker()
{
	std::string nameSeed = "ABCDEFGHIJKLMNO";
	this->m_MapSpeaker.clear();
	//创建12名选手数据(姓名,编号)
	for (int i = 0; i < 12; i++)
	{
		speaker s(nameSeed[i]);
		this->m_MapSpeaker.insert(std::make_pair(10001 + i, s));
	}
}

//初始化容器
void speechManeger::initSpeechContainers()
{
	this->m_Index = 1;
	this->m_MapSpeaker.clear();
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Record.clear();
}

//遍历选手顺序
void speechManeger::show_Speaker_drawOrder_1(vector<int>& v)
{
	map<int, speaker>::iterator itMap;
	vector<int>::iterator itVector = v.begin();

	cout << "第一组：" << endl;
	for (int i = 0; i < 6; i++)
	{
		//拿到的是选手编号，去找m_MapSpeaker找选手
		itMap = this->m_MapSpeaker.find(*itVector);
		cout << "选手编号：" << *itVector << "\t\t";
		cout << "选手姓名：" << itMap->second.getName() << endl;
		itVector++;
	}
	cout << "第二组：" << endl;
	for (int i = 0; i < 6; i++)
	{
		//拿到的是选手编号，去找m_MapSpeaker找选手
		itMap = this->m_MapSpeaker.find(*itVector);
		cout << "选手编号：" << *itVector << "\t\t";
		cout << "选手姓名：" << itMap->second.getName() << endl;
		itVector++;
	}
}
void speechManeger::show_Speaker_drawOrder_2(vector<int>& v)
{
	map<int, speaker>::iterator itMap;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		//拿到的是选手编号，去找m_MapSpeaker找选手
		itMap=this->m_MapSpeaker.find(*it);
		cout << "选手编号：" << *it<<"\t\t";
		cout << "选手姓名：" << itMap->second.getName() << endl;
	}
}
void speechManeger::show_Speaker_scoreOrder_1()
{
	map<int, speaker>::iterator itMap;
	vector<int>::iterator itVector= this->v1.begin();

	cout << "第一组：" << endl;
	for (int i = 0; i < 6; i++)
	{
		//拿到的是选手编号，去找m_MapSpeaker找选手
		itMap = this->m_MapSpeaker.find(*itVector);
		cout << "选手编号：" << *itVector << "\t\t";
		cout << "选手姓名：" << itMap->second.getName() << "\t\t";
		cout << "分数：" << itMap->second.get_First_Score() << endl;
		itVector++;
	}
	cout << "第二组：" << endl;
	for (int i = 0; i < 6; i++)
	{
		//拿到的是选手编号，去找m_MapSpeaker找选手
		itMap = this->m_MapSpeaker.find(*itVector);
		cout << "选手编号：" << *itVector << "\t\t";
		cout << "选手姓名：" << itMap->second.getName() << "\t\t";
		cout << "分数：" << itMap->second.get_First_Score() << endl;
		itVector++;
	}
}
void speechManeger::show_Speaker_scoreOrder_2()
{
	map<int, speaker>::iterator itMap;
	for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
	{
		//拿到的是选手编号，去找m_MapSpeaker找选手
		itMap = this->m_MapSpeaker.find(*it);
		cout << "选手编号：" << *it << "\t\t";
		cout << "选手姓名：" << itMap->second.getName() << "\t\t";
		cout << "分数：" << itMap->second.get_Second_Score() << endl;
	}
}
void speechManeger::show_Victory()
{
	map<int, speaker>::iterator  itMap = this->m_MapSpeaker.begin();
	vector<int>::iterator itVictory = this->v2.begin();
	for (int i = 0; i < 3; i++, itVictory++)
	{
		this->vVictory.push_back(*itVictory);
	}
	itVictory = this->vVictory.begin();

	cout << endl;
	cout << "本届比赛已结束,以下为本届获奖名单：" << endl;

	cout << "冠军：" << this->m_MapSpeaker.find(*itVictory)->second.getName() << "\t";
	cout << "编号：" << this->m_MapSpeaker.find(*itVictory)->first << "\t";
	cout << "分数：" << this->m_MapSpeaker.find(*itVictory)->second.get_Second_Score()<< endl;
	cout << endl; itVictory++;
	cout << "亚军：" << this->m_MapSpeaker.find(*itVictory)->second.getName() << "\t";
	cout << "编号：" << this->m_MapSpeaker.find(*itVictory)->first << "\t";
	cout << "分数：" << this->m_MapSpeaker.find(*itVictory)->second.get_Second_Score() << endl;
	cout << endl; itVictory++;
	cout << "季军：" << this->m_MapSpeaker.find(*itVictory)->second.getName() << "\t";
	cout << "编号：" << this->m_MapSpeaker.find(*itVictory)->first << "\t";
	cout << "分数：" << this->m_MapSpeaker.find(*itVictory)->second.get_Second_Score() << endl;
	cout << endl; itVictory++;
}


//选手抽签
void speechManeger::draw_Speaker()
{
	cout << "第"<<this->m_Index<<"轮选手正在抽签...." << endl;
	system("pause");
	cout << endl;

	//第一轮,从选手容器取出全部12人，分两组
	if (this->m_Index == 1)
	{
		//先录入选手编号于v1中
		for (map<int,speaker>::iterator it=this->m_MapSpeaker.begin();it!= this->m_MapSpeaker.end();it++)
		{
			this->v1.push_back(it->first);
		}

		//随机打乱选手(赋签)
		std::random_shuffle(this->v1.begin(), this->v1.end());

		cout << "抽签完毕，选手顺序为：" << endl;
		this->show_Speaker_drawOrder_1(this->v1);
	}
	else//第二轮，从v2取出6人
	{
		//随机打乱选手(赋签)
		std::random_shuffle(this->v2.begin(), this->v2.end());
		cout << "抽签完毕，选手顺序为：" << endl;
		this->show_Speaker_drawOrder_2(this->v2);
	}
}

//对每个选手打分
void speechManeger::doScore_1(vector<int>& v)
{
	//现在传入抽签后的v1

	//创建容器、迭代器、分数,以及关键的联系vector与map的临时容器
	vector<int>::iterator itVector = v.begin();	//选手编号的迭代器
	map<int, speaker>::iterator itMap = this->m_MapSpeaker.begin();//用于查找选手的迭代器
	std::multimap<double, int, std::greater<double>>Multi;//key是分数，value是编号
	deque<double> dScore;//评委分数
	double ret_Score = 0;//选手最终分数

	//用两个小的容器临时存储两个小组
	vector<int> vTemp_1;
	vector<int> vTemp_2;
	for (int i = 0; i < v.size(); i++, itVector++)
	{
		if (i < v.size() / 2)
		{
			vTemp_1.push_back(*itVector);
		}
		else
		{
			vTemp_2.push_back(*itVector);
		}
	}
	//存储结束，itVector归零
	itVector = v.begin();

	//开始打分
	for (int i = 0; i < v.size(); i++, itVector++)
	{
		if (!dScore.empty())
		{
			dScore.clear();
		}
		//评委打出分数
		for (int i = 0; i < 10; i++)
		{
			dScore.push_back((rand() % 301 + 700) / 10.f);//分数介于70-100
		}
		//处理评委分数
		dScore.pop_back();
		dScore.pop_front();
		ret_Score = (double)std::accumulate(dScore.begin(), dScore.end(), 0);
		ret_Score /= dScore.size();

		//数据写入临时链接容器
		Multi.insert(std::make_pair(ret_Score, *itVector));

		//数据写入MapSpeaker
		itMap = this->m_MapSpeaker.find(*itVector);
		if (i < v.size() / 2)//分数给vTemp_1中选手
		{
			itMap->second.set_First_Score(ret_Score);
		}
		else//分数给vTemp_2中选手
		{
			itMap->second.set_First_Score(ret_Score);
		}
	}
	//打分完毕,现在利用Multi对v1重写入
	v.resize(0);
	for (std::multimap<double, int>::iterator it = Multi.begin(); it != Multi.end(); it++)
	{
		//找到vT_1
		if (std::find(vTemp_1.begin(), vTemp_1.end(), it->second) != vTemp_1.end())
		{
			v.push_back(it->second);
		}
	}
	for (std::multimap<double, int>::iterator it = Multi.begin(); it != Multi.end(); it++)
	{
		//找到vT_2
		if (std::find(vTemp_2.begin(), vTemp_2.end(), it->second) != vTemp_2.end())
		{
			v.push_back(it->second);
		}
	}
	//v1写入完毕,写入v2
	vector<int>::iterator it_1 = this->v1.begin();
	vector<int>::iterator it_2 = this->v1.begin() + this->v1.size() / 2;
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			this->v2.push_back(*it_1);
			it_1++;
		}
		else
		{
			this->v2.push_back(*it_2);
			it_2++;
		}
	}
	//第一轮写入全部完成,遍历成绩
	this->show_Speaker_scoreOrder_1();
	this->m_Index++;

	//清除容器
	Multi.clear();
	vTemp_1.clear();
	vTemp_2.clear();
	dScore.clear();
}
void speechManeger::doScore_2(vector<int>& v)
{
	//现在传入抽签后的v2

	//创建迭代器，分数
	vector<int>::iterator itVec = v.begin();
	map<int, speaker>::iterator itMap;
	deque<double> dScore;
	double ret_Score = 0;//选手终分数
	//创建链接容器
	std::multimap<double, int, std::greater<double>>Multi;//key是分数，value是编号

	//打分
	for (int i = 0; i < v.size(); i++, itVec++)
	{
		if (!dScore.empty())
		{
			dScore.clear();
		}
		for (int j = 0; j < 10; j++)
		{
			//分数介于70-100
			dScore.push_back((rand() % 301 + 700)/10.f);
		}

		//一位选手打完分，求其平均分
		std::sort(dScore.begin(), dScore.end());
		dScore.pop_back();
		dScore.pop_front();
		ret_Score = (double)(std::accumulate(dScore.begin(), dScore.end(), 0)) / dScore.size();

		//数据写入临时链接容器
		Multi.insert(std::make_pair(ret_Score, *itVec));

		//给选手赋分
		itMap = this->m_MapSpeaker.find(*itVec);
		itMap->second.set_Second_Score(ret_Score);
	}
	//打分完，对v2重写入
	v.resize(0);
	for (std::multimap<double, int>::iterator it = Multi.begin(); it != Multi.end(); it++)
	{
		v.push_back(it->second);
	}

	//第一轮写入全部完成,遍历成绩
	this->show_Speaker_scoreOrder_2();

	//清除容器
	dScore.clear();
	Multi.clear();
}

//保存记录
void speechManeger::saveRecord()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out | std::ios::app);

	//将每个人的数据写入
	for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
	{
		ofs << *it << "," << (this->m_MapSpeaker.find(*it))->second.get_Second_Score()<< ",";
	}
	ofs << endl;

	//关闭文件
	ofs.close();

	cout << "记录已保存！" << endl;
	this->file_IsEmpty = false;
}

//功能1-开始演讲
void speechManeger::start_Speech()
{
//第一轮
	//开始抽签
	this->draw_Speaker();
	cout << endl;
	cout << "正在等待第" << this->m_Index << "轮选手演讲......" << endl;
	system("pause");
	cout << endl;

	//对每个选手进行打分
	cout << "演讲完毕，选手排名如下：" << endl;
	this->doScore_1(this->v1);
	cout << endl;
	system("pause");
	cout << endl;


//第二轮
	//开始抽签
	this->draw_Speaker();
	cout << endl;
	cout << "正在第"<<this->m_Index<<"轮等待选手演讲......" << endl;
	system("pause");
	cout << endl;

	//对每个选手进行打分
	cout << "演讲完毕，选手排名如下：" << endl;
	this->doScore_2(this->v2);
	cout << endl;
	system("pause");
	cout << endl;

	this->show_Victory();

	this->saveRecord();
}


//读入往届记录
void speechManeger::load_Record()
{
	//编号，分数(3名)
	std::ifstream ifs(FILENAME, std::ios::in);

	//没有文件
	if (!ifs.is_open())
	{
		this->file_IsEmpty = true;

		#ifdef DEBUG
		cout << "文件不存在！" << endl;
		#endif // DEBUG

		ifs.close();
		return;
	}

	//文件为空
	char ch;//读取尝试
	ifs >> ch;
	if (ifs.eof())
	{
	
		#ifdef DEBUG
		cout << "文件为空!" << endl;
		#endif // DEBUG

		this->file_IsEmpty = true;

		//读取的字符放回去
		ifs.putback(ch);

		//关闭文件
		ifs.close();
		return;
	}

	//现在文件可以正常打开
	this->file_IsEmpty = false;
	//读取的字符放回去
	ifs.putback(ch);

	//开始读入数据
	string data;
	int index = 0;//届数

	//一次读入一行
	while (ifs >> data)
	{
		vector<string> v;//存储某一届的具体数据

		int pos = -1;
		int start = 0;
	
		while (true)
		{
			//查找","
			pos = data.find(",", start);
			if (pos == -1)
			{
				//没找到
				break;
			}
			//找到了
			string temp = data.substr(start, pos - start);//从start开始截取，取前pos-start个
			v.push_back(temp);

			start = pos + 1;
		}
		
		//找完一行数据,写入map
		this->m_Record.insert(std::make_pair(index, v));
		index++;
	}

	//读完
	ifs.close();
}

//功能2-查看往届记录
void speechManeger::see_Record()
{
	if (this->file_IsEmpty)
	{
		cout << "文件不存在或文件为空!" << endl;
		return;
	}

	//一轮写入一届数据
	for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); it++)
	{
		cout << "第" << it->first+1 << "届：";
		cout << "\t冠军编号:" << it->second[0]  << "\t分数:" <<it->second[1];
		cout << "\t亚军编号:" << it->second[2]  << "\t分数:" <<it->second[3] ;
		cout << "\t季军编号:" << it->second[4]  << "\t分数:" <<it->second[5] ;
		cout << endl;
	}
}


//功能3-数据全部清空
void speechManeger::clear_List()
{
	int user_Choice = 0;

	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl << endl;

	while (1)
	{
		cin >> user_Choice;

		if ((user_Choice != 1) && (user_Choice != 2))//乱选重开
		{
			continue;
		}
		if (user_Choice == 2)
		{
			return;
		}
		else
		{
			//清空所有记录
			std::ofstream ofs(FILENAME, std::ios::trunc);//如果文件存在先删除再重新创建
			ofs.close();

			this->initSpeechContainers();

			this->init_Speaker();

			this->file_IsEmpty = true;

			cout << "已清空所有数据!" << endl;
			return;
		}
	}
}

