#include"admin.h"

//Ĭ�Ϲ���
Admin::Admin()
{
	this->m_Id = 0;
}

//�вι���(����Ա��š�����������)
Admin::Admin(int adId, std::string name, std::string pwd)
{
	this->m_Id = adId;
	this->m_Name = name;
	this->m_Password = pwd;
}

//�˵�
void Admin::openMenu()
{
	system("cls");
	std::cout << "��ӭ����Ա" << this->m_Name << "��¼��\n\n";

    std::cout << "��ѡ�����Ĳ���" << std::endl;
    std::cout << "             ------------------------" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       1.����˺�        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       2.�鿴�˺�        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       3.��ӻ���        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       4.�鿴����        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       5.���ԤԼ        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "            |       0.ע����¼        |" << std::endl;
    std::cout << "            |                         |" << std::endl;
    std::cout << "             ------------------------" << std::endl;
    std::cout << "��������ѡ��";
}

//loadFile
std::vector<Identity*> Admin::loadIdentityFile(std::string fileName,int personType)
{
    //����׼��(ID,�û���������)
    std::vector<Identity*> vIdentityData;
    int id = 0;
    std::string usrName;
    std::string pwd;

    std::fstream ifs(fileName, std::ios::in);
    //�ļ�������
    if (!ifs.is_open())
    {
        //std::cout << "(����)�ļ������ڣ�\n";
        ifs.close();
        return vIdentityData;
    }
    //�ļ�Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //std::cout << "(����)�ļ�Ϊ�գ�\n";
        ifs.putback(ch);
        ifs.close();
        return vIdentityData;
    }
    ifs.putback(ch);


    while (ifs >> id && ifs >> usrName && ifs >> pwd)
    {
        Identity* person = NULL;
        switch (personType)
        {        
        case TEACHER:
            person = new Teacher(id, usrName, pwd);
            break;
        case STUDENT:
            person = new Student(id, usrName, pwd);
            break;
        default:
            break;
        }
        vIdentityData.push_back(person);
    }
    ifs.close();
    return vIdentityData;
}

//WriteBackSub
void Admin::writeBackSubFile(std::string fileName, std::vector<Identity*>& vIdentityData)
{
    std::fstream ofs(fileName, std::ios::out|std::ios::trunc);
    for (std::vector<Identity*>::iterator it = vIdentityData.begin(); it != vIdentityData.end(); it++)
    {
        ofs << (*it)->m_Id << " " << (*it)->m_Name << " " << (*it)->m_Password << std::endl;
    }
}

//loadComp
std::vector<ComputerRoom> Admin::loadCompFile()
{
    //��ȡ������Ϣ
    std::vector<ComputerRoom> vComp;
    std::ifstream ifs(COMPUTER_FILE, std::ios::in);
    int comId = 0;
    int capa = 0;
    while (ifs >> comId && ifs >> capa)
    {
        ComputerRoom cm(comId, capa);
        vComp.push_back(cm);
    }
    return vComp;
}

//writeBackComp
void Admin::writeBackCompFile(std::vector < ComputerRoom> &vComp)
{
    std::fstream ofs(COMPUTER_FILE, std::ios::out | std::ios::trunc);
    for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
    {
        ofs << it->m_ComId << " " << it->m_MaxCapacity<< std::endl;
    }
}

//loadOrder
std::vector<Order> Admin::loadOrderFile()
{
    std::vector<Order> vOrder;
    std::ifstream ifs(ORDER_FILE, std::ios::in);

    int orderId = 0;
    int stuId = 0;
    int teaId = 0;
    int oInfo = 0;        //raw
    int comId = 0;
    int wTime = 0;        //sun 
    int dTime = 0;          //am
    while (ifs>> orderId&&ifs >> stuId && ifs >> teaId && ifs >> oInfo && ifs >> comId && ifs >> wTime && ifs >> dTime)
    {
        Order od;
        od.orderId = orderId;
        od.stuId = stuId;
        od.teaId = teaId;
        od.oInfo = oInfo;
        od.copmId = comId;
        OrderTime ot(wTime, dTime);
        od.oTime = ot;

        vOrder.push_back(od);
    }
    return vOrder;
}


//����˺�
void Admin::addAccount()
{
    std::string fileName;//׼��������ofstream��
    int personType = 0;//׼��ѡ��
    std::ofstream ofs;
    //ѡ������
    while (true)
    {
        std::cout << "��ѡ����ӵ��˺����ͣ�\n";
        std::cout << "1.���ѧ��\n2.�����ʦ\n";

       
        int select = 0;
        std::cin >> select;
        if (select == 1)//ѧ��
        {
            fileName = STUDENT_FILE;
            personType = STUDENT;
            std::cout << "������ѧ�ţ�";
            break;
        }
        else if (select == 2)//��ʦ
        {
            fileName = TEACHER_FILE;
            personType = TEACHER;
            std::cout << "������ְ���ţ�";
            break;
        }
        else
        {
            system("cls");
            this->openMenu();
            continue;
        }
    }
    //��ʼ���,�û���������
    ofs.open(fileName, std::ios::out | std::ios::app);
    int id;
    std::string name;
    std::string pwd;
    std::cin >> id;
    std::cout << "�������û�����"; std::cin >> name;
    std::cout << "���������룺"; std::cin >> pwd; std::cout << std::endl;

 //���ݴ���  1.��������  2.�����ظ�  3.�����Լ���ʾ
    std::vector<Identity*> vIdentityData=this->loadIdentityFile(fileName, personType);

    //��ʼ�����Ƿ��ظ�
    bool isExist = false;
    for (std::vector<Identity*>::iterator it = vIdentityData.begin(); it != vIdentityData.end(); it++)
    {
        if ((*it)->m_Id == id)
        {
            isExist = true;
            break;
        }
    }

    //�����Լ���ʾ
    if (isExist)
    {
        std::cout << "�ظ���ID!\n"; 
        ofs.close();       
    }
    else//д������
    {
        Admin *ad =new Admin(id, name, pwd);
        vIdentityData.push_back(ad);
        this->writeBackSubFile(fileName,vIdentityData);
        ofs.close();
        vIdentityData.clear();
        std::cout << "��ӳɹ�!\n";
    }
}

//�鿴�˺�
void Admin::showAccount()
{
    //��Ҫ�鿴,��������
    std::vector<Identity*> vStudent = this->loadIdentityFile(STUDENT_FILE, STUDENT);
    std::vector<Identity*> vTeacher = this->loadIdentityFile(TEACHER_FILE, TEACHER);

    //ѧ��
    std::cout << "-----------------\n";
    std::cout << "��ǰѧ���˺���:" << vStudent.size() << std::endl;
    std::cout << "-----------------\n";
    if (vStudent.size())
    {
        std::cout << "\tѧ��\t����\t\t����\n";
        for (std::vector<Identity*>::iterator it = vStudent.begin(); it != vStudent.end(); it++)
        {
            std::cout << "\t" << (*it)->m_Id << "\t" << (*it)->m_Name << "\t\t" << (*it)->m_Password << std::endl;
        }
    }
    std::cout << std::endl;
    //��ʦ
    std::cout << "-----------------\n";
    std::cout << "��ǰ��ʦ�˺���:" << vTeacher.size() << std::endl;
    std::cout << "-----------------\n";
    if (vTeacher.size())
    {
        std::cout << "\tְ����\t����\t\t����\n";
        for (std::vector<Identity*>::iterator it = vTeacher.begin(); it != vTeacher.end(); it++)
        {
            std::cout << "\t" << (*it)->m_Id << "\t" << (*it)->m_Name << "\t\t" << (*it)->m_Password << std::endl;
        }
    }
    std::cout << std::endl;
}

//��������
void Admin::showRoomDetail(int week, int day)
{
    //���ػ�����Ϣ
    std::vector<ComputerRoom> vComp = this->loadCompFile();
    //���ض���
    std::vector<Order> vOrder = this->loadOrderFile();

    //ɸѡ
    std::vector<Order> vSubOrder;
    for (std::vector<Order>::iterator it = vOrder.begin(); it != vOrder.end(); it++)
    {
        if (it->oTime.weekTime == week && it->oTime.dayTime == day&&it->oInfo==SUCCEED)
            vSubOrder.push_back(*it);
    }
    //�����Ϣ
    std::cout << "��ǰʱ�ζ���������" << vSubOrder.size() << "\n";
    std::cout << "---------------------\n";
    std::cout << "\t������\t�������\t��ԤԼ��\t����\n";
    for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
    {
        int comId = 0;//����ԤԼ����
        for (std::vector<Order>::iterator jt = vSubOrder.begin(); jt != vSubOrder.end(); jt++)
        {
            if (jt->copmId == it->m_ComId)
                comId++;
        }
        std::cout << "\t" << it->m_ComId << "\t" << it->m_MaxCapacity << "\t\t" << comId << "\t\t" << it->m_MaxCapacity - comId << "\n";
    }
    std::cout << std::endl;
}

//�鿴������Ϣ()
void Admin::showCompuRoomInfo()
{
    //���ػ�����Ϣ
    std::vector<ComputerRoom> vComp = this->loadCompFile();

    //���������Ϣ
    std::cout << "-----------------\n";
    std::cout << "��������:" <<vComp.size() << std::endl;
    std::cout << "-----------------\n";
    
    if (vComp.size())//�л���
    {
        std::cout << "\t������\t�������\n";
        for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
        {
            std::cout << "\t" << it->m_ComId << "\t" << it->m_MaxCapacity << "\n";
        }
        std::cout << std::endl;

        //��һ������
        std::cout << "����0�鿴���飬�������������ַ��˳���ѯ\n";
        char nextSelect = '0';
        std::cin >> nextSelect;
        if (nextSelect == '0')
        {
            std::cout << "��ѡ���ܼ���(0-sun,1-mon...)\n";
            int weekSelect = 0;
            while (1)
            {
                std::cin >> weekSelect;
                if (weekSelect != 0 && weekSelect != 1 && weekSelect != 2 && weekSelect != 3 && weekSelect != 4 && weekSelect != 5 && weekSelect != 6)
                    continue;
                break;
            }
            std::cout << "��ѡ��ʱ�Σ�(0-am,1-pm)\n";
            int daySelect = 0;
            while (1)
            {
                std::cin >> daySelect;
                if (daySelect != 0 && daySelect != 1)
                    continue;
                break;
            }
            //ѡ���ˣ���������
            if (weekSelect == 0)//����
            {
                std::cout << "---------------------\n";
                std::cout << "����ѡ������";
                if (daySelect == 0)
                {
                    std::cout << "����\n";
                }
                else
                {
                    std::cout << "����\n";
                }
            }
            else//1-6
            {
                std::cout << "---------------------\n";
                std::cout << "����ѡ����" << weekSelect << " ";
                if (daySelect == 0)
                {
                    std::cout << "����\n";
                }
                else
                {
                    std::cout << "����\n";
                }
            }
            this->showRoomDetail(weekSelect, daySelect);
        }
        else
        {
            return;
        }
    }
    else//û����
    {
        return;
    }
}

//����ظ�����
bool Admin::roomIsExist(std::vector<ComputerRoom>& vComp, ComputerRoom& cr)
{
    for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
    {
        if (it->m_ComId==cr.m_ComId)
        {
            return true;
        }
    }
    return false;
}

//������id��ȫ��
int Admin::getCompId(std::string str)
{
    std::vector<int> v;
    bool isSafe = false;
    for (std::string::iterator it = str.begin(); it != str.end(); it++)
    {
        if ((*it - '0') < 0 || (*it - '0') > 9)//�ַ����ڷ�����
        {
            isSafe = false;
            return -1;//��������
        }
        else//�ַ�����
        {
            v.push_back(*it - '0');
        }
    }
    int sum = 0;//�ַ���ת���ɴ�����
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        sum = sum * 10 + *it;
    }
    //��������Ƿ��Ѵ���
    //���ػ�����Ϣ
    std::vector<ComputerRoom> vComp = this->loadCompFile();
    for (std::vector<ComputerRoom>::iterator it = vComp.begin(); it != vComp.end(); it++)
    {
        if (sum==it->m_ComId)
        {
            return -2;//�����Ѵ���
        }
    }
    return sum;
}

//��ӻ���
void Admin::addComputerRoom()
{
    //���ػ�����Ϣ
    std::vector<ComputerRoom> vComp = this->loadCompFile();

    std::string safeId;
    std::cout << "���������:"; std::cin >> safeId;
    int comId = this->getCompId(safeId);
    if (comId == -1)
    {
        std::cout << "��������!\n";
        return;
    }
    else if (comId == -2)
    {
        std::cout << "�����Ѵ���!\n";
        return;
    }
    //��ʼ����
    int maxCapa = 0;
    std::cout << "����������������"; std::cin >> maxCapa;

    ComputerRoom cr(comId, maxCapa);
    vComp.push_back(cr);
    std::sort(vComp.begin(), vComp.end());
    std::cout << "��ӳɹ���";
    //д�ػ�����Ϣ
    this->writeBackCompFile(vComp);
}

//���ԤԼ��¼
void Admin::clearReservation()
{
    //����ļ�
    std::fstream ifs(ORDER_FILE, std::ios::in);
    //�ļ�������
    if (!ifs.is_open())
    {
        std::cout << "�ļ������ڣ�\n";
        ifs.close();
        return;
    }
    //�ļ�Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        std::cout << "�ļ�Ϊ�գ�\n";
        ifs.putback(ch);
        ifs.close();
        return;
    }
    ifs.putback(ch);
    ifs.close();

    //�ļ�������������
        std::cout << "ȷ����գ�(����0ȷ�ϣ��������������ַ�ȡ��)\n";
        char ConfirmNumber='0';
        std::cin >> ConfirmNumber;
        if (ConfirmNumber == '0')
        {
            std::ofstream ofs(ORDER_FILE, std::ios::trunc);
            ofs.close();
            std::cout << "�����!  ";
            return;
        }
        else
        {
            std::cout << "��ȡ��!  ";
            return;
        }
}