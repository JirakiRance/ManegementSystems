#include"speechManeger.h"
#include"speaker.h"

using std::cout;
using std::endl;
using std::cin;

//���캯��
speechManeger::speechManeger()
{
	//��ʼ������
	this->initSpeechContainers();

	//��ʼ��ѡ��
	this->init_Speaker();

	//��������(��ȡ�����¼)
	this->load_Record();
}
//����
speechManeger::~speechManeger()
{
	//��������
}

//չʾ�˵�
void speechManeger::show_Menu()
{
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * ��ӭʹ���ݽ��������̹���ϵͳ��* * * * *" << endl;
	cout << "* * * * * * * * *1����ʼ�ݽ�����* * * * * * * * *" << endl;
	cout << "* * * * * * * * *2���鿴����ɼ�* * * * * * * * *" << endl;
	cout << "* * * * * * * * *3��������м�¼* * * * * * * * *" << endl;
	cout << "* * * * * * * * *0���˳�����ϵͳ* * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << endl;
	cout << endl;
}

//�˳�����
void speechManeger::exit_speechManeger()
{
	cout << "��ӭ���´�ʹ�ã�  _(:�١���)_  " << endl;
	system("pause");
	exit(0);
}

//start_Speech��������ʼ��ѡ�ֵ�����
void speechManeger::init_Speaker()
{
	std::string nameSeed = "ABCDEFGHIJKLMNO";
	this->m_MapSpeaker.clear();
	//����12��ѡ������(����,���)
	for (int i = 0; i < 12; i++)
	{
		speaker s(nameSeed[i]);
		this->m_MapSpeaker.insert(std::make_pair(10001 + i, s));
	}
}

//��ʼ������
void speechManeger::initSpeechContainers()
{
	this->m_Index = 1;
	this->m_MapSpeaker.clear();
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Record.clear();
}

//����ѡ��˳��
void speechManeger::show_Speaker_drawOrder_1(vector<int>& v)
{
	map<int, speaker>::iterator itMap;
	vector<int>::iterator itVector = v.begin();

	cout << "��һ�飺" << endl;
	for (int i = 0; i < 6; i++)
	{
		//�õ�����ѡ�ֱ�ţ�ȥ��m_MapSpeaker��ѡ��
		itMap = this->m_MapSpeaker.find(*itVector);
		cout << "ѡ�ֱ�ţ�" << *itVector << "\t\t";
		cout << "ѡ��������" << itMap->second.getName() << endl;
		itVector++;
	}
	cout << "�ڶ��飺" << endl;
	for (int i = 0; i < 6; i++)
	{
		//�õ�����ѡ�ֱ�ţ�ȥ��m_MapSpeaker��ѡ��
		itMap = this->m_MapSpeaker.find(*itVector);
		cout << "ѡ�ֱ�ţ�" << *itVector << "\t\t";
		cout << "ѡ��������" << itMap->second.getName() << endl;
		itVector++;
	}
}
void speechManeger::show_Speaker_drawOrder_2(vector<int>& v)
{
	map<int, speaker>::iterator itMap;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		//�õ�����ѡ�ֱ�ţ�ȥ��m_MapSpeaker��ѡ��
		itMap=this->m_MapSpeaker.find(*it);
		cout << "ѡ�ֱ�ţ�" << *it<<"\t\t";
		cout << "ѡ��������" << itMap->second.getName() << endl;
	}
}
void speechManeger::show_Speaker_scoreOrder_1()
{
	map<int, speaker>::iterator itMap;
	vector<int>::iterator itVector= this->v1.begin();

	cout << "��һ�飺" << endl;
	for (int i = 0; i < 6; i++)
	{
		//�õ�����ѡ�ֱ�ţ�ȥ��m_MapSpeaker��ѡ��
		itMap = this->m_MapSpeaker.find(*itVector);
		cout << "ѡ�ֱ�ţ�" << *itVector << "\t\t";
		cout << "ѡ��������" << itMap->second.getName() << "\t\t";
		cout << "������" << itMap->second.get_First_Score() << endl;
		itVector++;
	}
	cout << "�ڶ��飺" << endl;
	for (int i = 0; i < 6; i++)
	{
		//�õ�����ѡ�ֱ�ţ�ȥ��m_MapSpeaker��ѡ��
		itMap = this->m_MapSpeaker.find(*itVector);
		cout << "ѡ�ֱ�ţ�" << *itVector << "\t\t";
		cout << "ѡ��������" << itMap->second.getName() << "\t\t";
		cout << "������" << itMap->second.get_First_Score() << endl;
		itVector++;
	}
}
void speechManeger::show_Speaker_scoreOrder_2()
{
	map<int, speaker>::iterator itMap;
	for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
	{
		//�õ�����ѡ�ֱ�ţ�ȥ��m_MapSpeaker��ѡ��
		itMap = this->m_MapSpeaker.find(*it);
		cout << "ѡ�ֱ�ţ�" << *it << "\t\t";
		cout << "ѡ��������" << itMap->second.getName() << "\t\t";
		cout << "������" << itMap->second.get_Second_Score() << endl;
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
	cout << "��������ѽ���,����Ϊ�����������" << endl;

	cout << "�ھ���" << this->m_MapSpeaker.find(*itVictory)->second.getName() << "\t";
	cout << "��ţ�" << this->m_MapSpeaker.find(*itVictory)->first << "\t";
	cout << "������" << this->m_MapSpeaker.find(*itVictory)->second.get_Second_Score()<< endl;
	cout << endl; itVictory++;
	cout << "�Ǿ���" << this->m_MapSpeaker.find(*itVictory)->second.getName() << "\t";
	cout << "��ţ�" << this->m_MapSpeaker.find(*itVictory)->first << "\t";
	cout << "������" << this->m_MapSpeaker.find(*itVictory)->second.get_Second_Score() << endl;
	cout << endl; itVictory++;
	cout << "������" << this->m_MapSpeaker.find(*itVictory)->second.getName() << "\t";
	cout << "��ţ�" << this->m_MapSpeaker.find(*itVictory)->first << "\t";
	cout << "������" << this->m_MapSpeaker.find(*itVictory)->second.get_Second_Score() << endl;
	cout << endl; itVictory++;
}


//ѡ�ֳ�ǩ
void speechManeger::draw_Speaker()
{
	cout << "��"<<this->m_Index<<"��ѡ�����ڳ�ǩ...." << endl;
	system("pause");
	cout << endl;

	//��һ��,��ѡ������ȡ��ȫ��12�ˣ�������
	if (this->m_Index == 1)
	{
		//��¼��ѡ�ֱ����v1��
		for (map<int,speaker>::iterator it=this->m_MapSpeaker.begin();it!= this->m_MapSpeaker.end();it++)
		{
			this->v1.push_back(it->first);
		}

		//�������ѡ��(��ǩ)
		std::random_shuffle(this->v1.begin(), this->v1.end());

		cout << "��ǩ��ϣ�ѡ��˳��Ϊ��" << endl;
		this->show_Speaker_drawOrder_1(this->v1);
	}
	else//�ڶ��֣���v2ȡ��6��
	{
		//�������ѡ��(��ǩ)
		std::random_shuffle(this->v2.begin(), this->v2.end());
		cout << "��ǩ��ϣ�ѡ��˳��Ϊ��" << endl;
		this->show_Speaker_drawOrder_2(this->v2);
	}
}

//��ÿ��ѡ�ִ��
void speechManeger::doScore_1(vector<int>& v)
{
	//���ڴ����ǩ���v1

	//����������������������,�Լ��ؼ�����ϵvector��map����ʱ����
	vector<int>::iterator itVector = v.begin();	//ѡ�ֱ�ŵĵ�����
	map<int, speaker>::iterator itMap = this->m_MapSpeaker.begin();//���ڲ���ѡ�ֵĵ�����
	std::multimap<double, int, std::greater<double>>Multi;//key�Ƿ�����value�Ǳ��
	deque<double> dScore;//��ί����
	double ret_Score = 0;//ѡ�����շ���

	//������С��������ʱ�洢����С��
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
	//�洢������itVector����
	itVector = v.begin();

	//��ʼ���
	for (int i = 0; i < v.size(); i++, itVector++)
	{
		if (!dScore.empty())
		{
			dScore.clear();
		}
		//��ί�������
		for (int i = 0; i < 10; i++)
		{
			dScore.push_back((rand() % 301 + 700) / 10.f);//��������70-100
		}
		//������ί����
		dScore.pop_back();
		dScore.pop_front();
		ret_Score = (double)std::accumulate(dScore.begin(), dScore.end(), 0);
		ret_Score /= dScore.size();

		//����д����ʱ��������
		Multi.insert(std::make_pair(ret_Score, *itVector));

		//����д��MapSpeaker
		itMap = this->m_MapSpeaker.find(*itVector);
		if (i < v.size() / 2)//������vTemp_1��ѡ��
		{
			itMap->second.set_First_Score(ret_Score);
		}
		else//������vTemp_2��ѡ��
		{
			itMap->second.set_First_Score(ret_Score);
		}
	}
	//������,��������Multi��v1��д��
	v.resize(0);
	for (std::multimap<double, int>::iterator it = Multi.begin(); it != Multi.end(); it++)
	{
		//�ҵ�vT_1
		if (std::find(vTemp_1.begin(), vTemp_1.end(), it->second) != vTemp_1.end())
		{
			v.push_back(it->second);
		}
	}
	for (std::multimap<double, int>::iterator it = Multi.begin(); it != Multi.end(); it++)
	{
		//�ҵ�vT_2
		if (std::find(vTemp_2.begin(), vTemp_2.end(), it->second) != vTemp_2.end())
		{
			v.push_back(it->second);
		}
	}
	//v1д�����,д��v2
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
	//��һ��д��ȫ�����,�����ɼ�
	this->show_Speaker_scoreOrder_1();
	this->m_Index++;

	//�������
	Multi.clear();
	vTemp_1.clear();
	vTemp_2.clear();
	dScore.clear();
}
void speechManeger::doScore_2(vector<int>& v)
{
	//���ڴ����ǩ���v2

	//����������������
	vector<int>::iterator itVec = v.begin();
	map<int, speaker>::iterator itMap;
	deque<double> dScore;
	double ret_Score = 0;//ѡ���շ���
	//������������
	std::multimap<double, int, std::greater<double>>Multi;//key�Ƿ�����value�Ǳ��

	//���
	for (int i = 0; i < v.size(); i++, itVec++)
	{
		if (!dScore.empty())
		{
			dScore.clear();
		}
		for (int j = 0; j < 10; j++)
		{
			//��������70-100
			dScore.push_back((rand() % 301 + 700)/10.f);
		}

		//һλѡ�ִ���֣�����ƽ����
		std::sort(dScore.begin(), dScore.end());
		dScore.pop_back();
		dScore.pop_front();
		ret_Score = (double)(std::accumulate(dScore.begin(), dScore.end(), 0)) / dScore.size();

		//����д����ʱ��������
		Multi.insert(std::make_pair(ret_Score, *itVec));

		//��ѡ�ָ���
		itMap = this->m_MapSpeaker.find(*itVec);
		itMap->second.set_Second_Score(ret_Score);
	}
	//����꣬��v2��д��
	v.resize(0);
	for (std::multimap<double, int>::iterator it = Multi.begin(); it != Multi.end(); it++)
	{
		v.push_back(it->second);
	}

	//��һ��д��ȫ�����,�����ɼ�
	this->show_Speaker_scoreOrder_2();

	//�������
	dScore.clear();
	Multi.clear();
}

//�����¼
void speechManeger::saveRecord()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out | std::ios::app);

	//��ÿ���˵�����д��
	for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
	{
		ofs << *it << "," << (this->m_MapSpeaker.find(*it))->second.get_Second_Score()<< ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼�ѱ��棡" << endl;
	this->file_IsEmpty = false;
}

//����1-��ʼ�ݽ�
void speechManeger::start_Speech()
{
//��һ��
	//��ʼ��ǩ
	this->draw_Speaker();
	cout << endl;
	cout << "���ڵȴ���" << this->m_Index << "��ѡ���ݽ�......" << endl;
	system("pause");
	cout << endl;

	//��ÿ��ѡ�ֽ��д��
	cout << "�ݽ���ϣ�ѡ���������£�" << endl;
	this->doScore_1(this->v1);
	cout << endl;
	system("pause");
	cout << endl;


//�ڶ���
	//��ʼ��ǩ
	this->draw_Speaker();
	cout << endl;
	cout << "���ڵ�"<<this->m_Index<<"�ֵȴ�ѡ���ݽ�......" << endl;
	system("pause");
	cout << endl;

	//��ÿ��ѡ�ֽ��д��
	cout << "�ݽ���ϣ�ѡ���������£�" << endl;
	this->doScore_2(this->v2);
	cout << endl;
	system("pause");
	cout << endl;

	this->show_Victory();

	this->saveRecord();
}


//���������¼
void speechManeger::load_Record()
{
	//��ţ�����(3��)
	std::ifstream ifs(FILENAME, std::ios::in);

	//û���ļ�
	if (!ifs.is_open())
	{
		this->file_IsEmpty = true;

		#ifdef DEBUG
		cout << "�ļ������ڣ�" << endl;
		#endif // DEBUG

		ifs.close();
		return;
	}

	//�ļ�Ϊ��
	char ch;//��ȡ����
	ifs >> ch;
	if (ifs.eof())
	{
	
		#ifdef DEBUG
		cout << "�ļ�Ϊ��!" << endl;
		#endif // DEBUG

		this->file_IsEmpty = true;

		//��ȡ���ַ��Ż�ȥ
		ifs.putback(ch);

		//�ر��ļ�
		ifs.close();
		return;
	}

	//�����ļ�����������
	this->file_IsEmpty = false;
	//��ȡ���ַ��Ż�ȥ
	ifs.putback(ch);

	//��ʼ��������
	string data;
	int index = 0;//����

	//һ�ζ���һ��
	while (ifs >> data)
	{
		vector<string> v;//�洢ĳһ��ľ�������

		int pos = -1;
		int start = 0;
	
		while (true)
		{
			//����","
			pos = data.find(",", start);
			if (pos == -1)
			{
				//û�ҵ�
				break;
			}
			//�ҵ���
			string temp = data.substr(start, pos - start);//��start��ʼ��ȡ��ȡǰpos-start��
			v.push_back(temp);

			start = pos + 1;
		}
		
		//����һ������,д��map
		this->m_Record.insert(std::make_pair(index, v));
		index++;
	}

	//����
	ifs.close();
}

//����2-�鿴�����¼
void speechManeger::see_Record()
{
	if (this->file_IsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��!" << endl;
		return;
	}

	//һ��д��һ������
	for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); it++)
	{
		cout << "��" << it->first+1 << "�죺";
		cout << "\t�ھ����:" << it->second[0]  << "\t����:" <<it->second[1];
		cout << "\t�Ǿ����:" << it->second[2]  << "\t����:" <<it->second[3] ;
		cout << "\t�������:" << it->second[4]  << "\t����:" <<it->second[5] ;
		cout << endl;
	}
}


//����3-����ȫ�����
void speechManeger::clear_List()
{
	int user_Choice = 0;

	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl << endl;

	while (1)
	{
		cin >> user_Choice;

		if ((user_Choice != 1) && (user_Choice != 2))//��ѡ�ؿ�
		{
			continue;
		}
		if (user_Choice == 2)
		{
			return;
		}
		else
		{
			//������м�¼
			std::ofstream ofs(FILENAME, std::ios::trunc);//����ļ�������ɾ�������´���
			ofs.close();

			this->initSpeechContainers();

			this->init_Speaker();

			this->file_IsEmpty = true;

			cout << "�������������!" << endl;
			return;
		}
	}
}

