#include"WorkerManeger.h"

//WorkerManegerʵ��

WorkerManeger::WorkerManeger()
{
	//1���ļ�������
	ifstream ifs(FILENAME,ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������!" << endl;
		//��ʼ������
		this->m_WorkerNum = 0;
		this->m_WorkerArr = NULL;
		//��ʼ��"�ļ��Ƿ�Ϊ��"
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2���ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		//��ʼ������
		this->m_WorkerNum = 0;
		this->m_WorkerArr = NULL;
		//��ʼ��"�ļ��Ƿ�Ϊ��"
		this->m_FileIsEmpty = true;//���ļ�Ϊ����ʵ��
		ifs.close();
		return;
	}

	//3���ļ����ڣ�����������
	int num = this->getWorkerNum();
	//cout << "��" << num << "����" << endl;//���Դ���
	//��������
	this->m_WorkerNum = num;
	this->m_FileIsEmpty = false;
	
	//���ٿռ�
	this->m_WorkerArr = new Worker * [this->m_WorkerNum];
	//���ļ��е�����¼������
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

//�����ļ�
void WorkerManeger::save()
{
	//ָ��·��
	ofstream ofs(FILENAME,ios::out);
	//ͷ��ʾ��
	/*ofs << "ְ�����\t"
		<< "ְ������\t"
		<< "ְ����λ" << endl;*/
	//д������
	for (int i = 0; i < this->m_WorkerNum; i++)
	{
		ofs << this->m_WorkerArr[i]->m_Id << " ";
		ofs << this->m_WorkerArr[i]->m_Name << " ";
		ofs << this->m_WorkerArr[i]->m_DeptId;
		ofs << endl;
	}
	ofs.close();
}
//ͳ���ļ�������
int WorkerManeger::getWorkerNum()
{
	ifstream ifs(FILENAME,ios::in);
	//׼������
	int num = 0;

	char buf[1024];
	while (ifs.getline(buf,sizeof(buf)))
	{
		num++;
	}
	ifs.close();
	return num;
}
//��ʼ��ְ��
void WorkerManeger::initialWorker()
{
	ifstream ifs(FILENAME, ios::in);

	//׼������
	int id;
	string name;
	int dId;
	int index = 0;//��ʶ�±�
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)//��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2)//����
		{
			worker = new Maneger(id, name, dId);
		}
		else if (dId == 3)//�ܲ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_WorkerArr[index] = worker;
		index++;
	}
	ifs.close();
}

//չʾ�˵�
void WorkerManeger::showMenu()
{
	cout << "********************************" << endl;
	cout << "*****��ӭʹ��ְ������ϵͳ��*****" << endl;
	cout << "*********0.�˳�����ϵͳ*********" << endl;
	cout << "*********1.����ְ����Ϣ*********" << endl;
	cout << "*********2.��ʾְ����Ϣ*********" << endl;
	cout << "*********3.ɾ��ְ����Ϣ*********" << endl;
	cout << "*********4.�޸�ְ����Ϣ*********" << endl;
	cout << "*********5.����ְ����Ϣ*********" << endl;
	cout << "*********6.���ձ������*********" << endl;
	cout << "*********7.��������ĵ�*********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}
//�˳�ϵͳ
void WorkerManeger::exitSystem()
{
	cout << "��ӭ���´�ʹ�ñ�ϵͳ��(��^_^ ��)" << endl;
	system("pause");
	exit(0);
}
//���ְ��
void WorkerManeger::addWorker()
{
	FLAG_ADD://�ط����

	int addNum = 0;
	cout << "��������Ҫ��ӵ�Ա��������"; cin >> addNum;

	if (addNum > 0&&addNum<6)
	{
		//�����¿ռ䣬���ɿռ�����ת�����¿ռ�

		//�����¿ռ�
		int newSize = this->m_WorkerNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize * sizeof(Worker)];

		//���������ݣ����и��ǲ���
		if (this->m_WorkerArr != NULL)
		{
			for (int i = 0; i < this->m_WorkerNum; i++)
			{
				newSpace[i] = this->m_WorkerArr[i];
			}
		}

		//����������
		int id=-1;
		string name="-1";
		int dSelect=-1;

		for (int i = 0; i < addNum; i++)
		{
			cout << "�������" << i + 1 << "λ��ְ����ţ�"; cin >> id;
			cout << "�������" << i + 1 << "λ��ְ��������"; cin >> name;

		
			cout << "��ѡ���ְ����λ:" << endl << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ܲ�" << endl;
			cin >> dSelect;


			//��ʼ����ָ��

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
			//ָ�봴����ϣ���ʼ���
			newSpace[this->m_WorkerNum + i] = worker;

			//delete worker;
			//worker = NULL;

			//worker���ݹ黹
			id = -1;
			name = "-1";
			dSelect = -1;
		}


		//��¼��ϣ�ɾ���ɿռ䲢���¿ռ��Լ���������
		delete[] this->m_WorkerArr;
		this->m_WorkerArr = newSpace;
		this->m_WorkerNum = this->m_WorkerNum + addNum;

		//�����ļ�
		this->save();
		
		//ɾ��new���½��ռ�
		//delete[] newSpace;
		//�ļ�Ϊ������
		this->m_FileIsEmpty = false;
		//��ʾ
		cout << "�ѳɹ����" << addNum << "����ְ����Ϣ��" << endl;
	}
	else if (addNum >= 6)
	{
		cout << "������ӵ��������࣬��������" << endl;
		system("pause");
		goto FLAG_ADD;//�ط���Add��ͷ
	}
	else
	{
		cout << "������������������" << endl;
		system("pause");
		goto FLAG_ADD;//�ط���Add��ͷ
	}
	system("pause");
	system("cls");
}
//��ʾְ��
void WorkerManeger::showWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ������ڣ�" << endl;
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
//ɾ��ְ��
void WorkerManeger::deleteWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ������ڣ�" << endl;
	}

	int num;
	cout << "������ְ����ţ�"; cin >> num;
	if (this->Work_IsExist(num)==-1)
	{
		cout << "δ�ҵ���ְ����" << endl;
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

		cout << "ɾ���ɹ���" << endl;
		system("pause");
		system("cls");
	}
	//�жϻ���û����
	if (this->m_WorkerNum == 0)
	{
		this->m_FileIsEmpty = true;
	}
}
//ְ���Ƿ����(���ڷ���λ���±꣬�����ڷ���-1)
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
//�޸�ְ��
void WorkerManeger::modefyWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ������ڣ�" << endl;
	}

	int select = 0;
	cout << "��������ҷ�ʽ��" << endl;
	cout << "1������������" << endl;
	cout << "2����ְ����Ų���" << endl;

FLAG_reManner://�����������Ų���ְ�����ط���ѡ
	cin >> select;

	if (select == 2)
	{
		int id;
		cout << "������ְ�����:"; cin >> id;

		if (this->Work_IsExist(id) == -1)
		{
			cout << "δ�ҵ���ְ����" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			//������
			int new_Id;
			string new_Name;
			int new_dId = 0;


			//����λ��
			int ret = this->Work_IsExist(id);
			//����ʾ��Ϣ
			this->m_WorkerArr[ret]->showInfo();
			//ɾ����Ϣ
			delete m_WorkerArr[ret];

			cout << "����������ְ����ţ�";
			cin >> new_Id;

			cout << "����������ְ��������";
			cin >> new_Name;

			cout << "������ѡ���ű�ţ�" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ܲ�" << endl;

		FLAG_reselectForDept_Num://��Ų���ְ���У�����ѡ���ű��

			//׼����������
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
			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
	}
	else if (select == 1)
	{
		//���ڲ�������
		string old_Name;
		cout << "������ְ������:"; cin >> old_Name;

		int ret = -1;
		for (int i = 0; i < this->m_WorkerNum; i++)
		{
			if (this->m_WorkerArr[i]->m_Name == old_Name)
			{
				//�ҵ��ˣ���չʾ��Ϣ
				this->m_WorkerArr[i]->showInfo();
				ret = i;
				break;
			}
		}

		//ɾ����Ϣ
		delete m_WorkerArr[ret];

		if (ret == -1)
		{
			cout << "δ�ҵ���ְ����" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			//������
			int new_Id;
			string new_Name;
			int new_dId = 0;


			//��ʼ����
			cout << "����������ְ����ţ�";
			cin >> new_Id;

			cout << "����������ְ��������";
			cin >> new_Name;


		FLAG_reselectForDept_Name://���Ʋ���ְ���У�����ѡ���ű��

			int new_dSelect = 0;
			cout << "������ѡ���ű�ţ�";
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ܲ�" << endl;

			//׼����������
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
			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
	}
	else
	{
		cout << "���������룡" << endl;
		goto FLAG_reManner;
	}
	system("pause");
	system("cls");
}
//����ְ��
void WorkerManeger::findWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ������ڣ�" << endl;
	}

	int select = 0;
	cout << "��������ҷ�ʽ��" << endl;
	cout << "1������������" << endl;
	cout << "2����ְ����Ų���" << endl;

	FLAG_reManner://�����������Ų���ְ�����ط���ѡ
	cin >> select;

	if (select == 2)
	{
		int id;
		cout << "������ְ�����:"; cin >> id;

		if (this->Work_IsExist(id) == -1)
		{
			cout << "δ�ҵ���ְ����" << endl;
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
		cout << "������ְ������:"; cin >> name;

		int ret = -1;
		for (int i = 0; i < this->m_WorkerNum; i++)
		{
			if (this->m_WorkerArr[i]->m_Name == name)
			{
				//�ҵ��ˣ�չʾ��Ϣ
				this->m_WorkerArr[i]->showInfo();
				ret = i;
				break;
			}
			system("pause");
			system("cls");
		}

		if (ret == -1)
		{
			cout << "δ�ҵ���ְ����" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	else
	{
		cout << "���������룡" << endl;
		goto FLAG_reManner;
	}
}
//����λ��
void WorkerManeger::Swap_Worker(Worker* w1, Worker* w2)
{
	Worker* temp = new Employee(99, "temp", 3);
	*temp = *w1;
	*w1 = *w2;
	*w2 = *temp;
	delete temp;
}
//����
void WorkerManeger::Sort()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ������ڣ�" << endl;
	}

	int select = 0;
	cout << "��ѡ������ʽ" << endl;
	cout << "1����ְ���������" << endl;
	cout << "2����ְ����Ž���" << endl;

	FLAG_sortReSelect://��ѡ1��2����ѡ
	cin >> select;
	if (select != 1 && select != 2)
	{
		cout << "���������룡" << endl;
		goto FLAG_sortReSelect;
	}
	else
	{
		int minOrMax = 0; int index = 0;

		if (select == 1)//��������С����
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
		else if (select == 2)//�������������
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
		cout << "���������,�������Ϊ��" << endl;
		save();
		this->showWorker();
	}
	system("cls");
}
//����ĵ�
void WorkerManeger::Delete_All()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��ļ������ڣ�" << endl;
		return;
	}

	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
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
		//ɾ���ĵ�
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();
		//ɾ��ָ��ָ��������ڴ�
		if (this->m_WorkerArr != NULL)
		{
			for (int i = 0; i < this->m_WorkerNum; i++)
			{
				delete this->m_WorkerArr[i];
				this->m_WorkerArr[i] = NULL;
			}
		}
		//�ͷ�ָ��
		delete[] this->m_WorkerArr;
		this->m_WorkerArr = NULL;
		//��������
		this->m_WorkerNum = 0;
		this->m_FileIsEmpty = true;

		cout << "�����" << endl;
		system("pause");
		system("cls");
	}
}

